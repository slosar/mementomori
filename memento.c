/* defines */
#define GLOB_STR "/var/spool/emailrelay/*content"
#define FAN_DEV "/sys/devices/platform/thinkpad_hwmon/hwmon/hwmon6/fan1_input"
/* use gettimes.py for these */
#define TIMEBIRTH 249109200.0

#include <glob.h>
#include <stdio.h>
#include <time.h>

int main() {

time_t secnow = time(NULL);
int dayspassed = (int)((secnow-TIMEBIRTH)/(24*3600));
printf ("[%i",dayspassed); 
 
glob_t p;
int res=glob(GLOB_STR, GLOB_NOSORT,
	       NULL, &p);
if (!(res==GLOB_NOMATCH))  printf (" unsent emails: %lu",p.gl_pathc);

int fanSpeed;
FILE *file = fopen(FAN_DEV, "r");
if (file != NULL) {
	fscanf(file, "%d", &fanSpeed);
	fclose(file);
	printf(" | %d RPM", fanSpeed);
}
printf("]");
globfree(&p);
return 0;
}
