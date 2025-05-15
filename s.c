#include <time.h>
#include <stdio.h>
#include <stdlib.h>


/* struct tm { */
/*         int     tm_sec;         /\* seconds after the minute [0-60] *\/ */
/*         int     tm_min;         /\* minutes after the hour [0-59] *\/ */
/*         int     tm_hour;        /\* hours since midnight [0-23] *\/ */
/*         int     tm_mday;        /\* day of the month [1-31] *\/ */
/*         int     tm_mon;         /\* months since January [0-11] *\/ */
/*         int     tm_year;        /\* years since 1900 *\/ */
/*         int     tm_wday;        /\* days since Sunday [0-6] *\/ */
/*         int     tm_yday;        /\* days since January 1 [0-365] *\/ */
/*         int     tm_isdst;       /\* Daylight Savings Time flag *\/ */
/*         long    tm_gmtoff;      /\* offset from UTC in seconds *\/ */
/*         char    *_LIBC_CSTR     tm_zone;        /\* timezone abbreviation *\/ */
/* }; */

int main(int argc, char **argv) {
  time_t now = time(NULL);
  struct tm *now_struct = gmtime(&now);
  char *z = malloc(10);

  strftime(z, 10, "%z", now_struct);

  printf("%%z: %s\n", z);

  strftime(z, 10, "%Z", now_struct);

  printf("%%Z: %s\n", z);

  printf("tm_isdst: %d\n", now_struct->tm_isdst);
  // Doesn't exist on windows
  // printf("tm_gmtoff: %ld\n", now_struct->tm_gmtoff);
  // printf("tm_zone: %s\n", now_struct->tm_zone);
}
