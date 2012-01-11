/* pg: 7 ECP */

#include <stdio.h>
#include <time.h>

void to_years(double secs)
{
	unsigned int mins = 0;
	unsigned int hrs = 0;
	unsigned int days = 0;

	days = (secs)/(60*60*24);
	secs = secs - 60*60*24*days;
	hrs = secs/(60*60);
	secs = secs - 60*60*hrs;
	mins = secs/60;
	secs = secs - mins*60;

	printf(" %u Days %u Hours %u Minutes %g Seconds\n", days, hrs, mins, secs);

}

int main (int argc, char *argv[])
{
	time_t end = 0x7FFFFFFF; /* Is 4 bytes long */
	time_t now = 0;
	double secs;

	argc = argc;
	argv = argv;

	printf("Time is %u or %02X \n", end, end);
	printf("End of time is %s\n",asctime(gmtime(&end)));

	time(&now);
	printf("Current Time is %s\n", ctime(&now));
	secs = difftime(end, now);
	printf("Seconds till epoch: %20.20g \n", secs);

	to_years(secs);

	return 0;
}
