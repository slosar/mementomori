/* defines */
#define GLOB_STR "/var/spool/emailrelay/*content"
#ifdef LAMPEDUSA
#define FAN_DEV "/sys/devices/platform/thinkpad_hwmon/hwmon/hwmon5/fan1_input"
#endif
#ifdef REMLER
#define FAN_DEV "/sys/class/hwmon/hwmon1/fan%d_input"
#endif

/* use gettimes.py for these */
#define TIMEBIRTH 249109200.0

#include <glob.h>
#include <stdio.h>
#include <time.h>

int main() {

time_t secnow = time(NULL);
int dayspassed = (int)((secnow-TIMEBIRTH)/(24*3600));
printf (" %i",dayspassed); 
 
glob_t p;
int res=glob(GLOB_STR, GLOB_NOSORT,
	       NULL, &p);
if (!(res==GLOB_NOMATCH))  printf (" unsent emails: %lu",p.gl_pathc);


#ifdef LAMPEDUSA 
int fanSpeed;
FILE *file = fopen(FAN_DEV, "r");
if (file != NULL) {
	fscanf(file, "%d", &fanSpeed);
	fclose(file);
	printf(" | %d RPM", fanSpeed);
}
#endif
#ifdef REMLER
 int fanSpeed, fanSpeed_cpu, fanSpeed_other;
 fanSpeed_other=0;
 char fname[128];
 for (int i=1; i<=7; i++) {
   sprintf (fname, FAN_DEV,i);
   FILE *file = fopen(fname, "r");
   fscanf(file, "%d", &fanSpeed);
   fclose(file);
   if (i==2) 
     fanSpeed_cpu=fanSpeed;
   else
     fanSpeed_other+=fanSpeed;
 }
 /*
 char fanSpeed_gpu[128];
FILE *gpuTempFile = popen("nvidia-settings -t -q GPUCurrentFanSpeedRPM", "r");
if (gpuTempFile != NULL) {
  fgets(fanSpeed_gpu, sizeof(fanSpeed_gpu), gpuTempFile);
  pclose(gpuTempFile);
}
 printf(" | %d RPM | %d RPM | %d RPM ", fanSpeed_cpu, fanSpeed_other, atoi(fanSpeed_gpu));
 */
  printf(" | %d RPM | %d RPM ", fanSpeed_cpu, fanSpeed_other);
#endif
 

 
printf(" ");
globfree(&p);
return 0;
}
