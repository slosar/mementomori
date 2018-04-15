/* defines */
#define GLOB_STR "/home/anze/spool/email/*content"
#define uncomment_DODEATH /* if you want to also get diff to TIMEDEATH  */

/* use gettimes.py for these */
#define TIMEBIRTH 249109200.0
#define TIMEDEATH 2805253200.0


#include <glob.h>
#include <stdio.h>
#include <time.h>

int main() {

time_t secnow = time(NULL);
int dayspassed = (int)((secnow-TIMEBIRTH)/(24*3600));
#ifdef DODEATH
 int daystogo = (int)((TIMEDEATH-secnow)/(24*3600));
 printf ("[%i <-> %i",dayspassed, daystogo); */
#else
printf ("[%i",dayspassed); 
#endif
 
glob_t p;
int res=glob(GLOB_STR, GLOB_NOSORT,
	       NULL, &p);
if (!(res==GLOB_NOMATCH))  printf (" unsent emails: %lu",p.gl_pathc);
printf ("]");
globfree(&p);
return 0;
}
