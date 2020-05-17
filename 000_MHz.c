#include <stdio.h>
#include <time.h>
#include <sys/time.h>
#include <stdlib.h>

#define NUMBER_OF_LOOPS_MULTIPLIER 1000
#define SHOW_MHZ 1

int main (int argc, char **argv)
{
	struct timeval mytime[1];
	struct timezone myzone[1];
	long long i;
	int interval;
	clock_t end_time = 0;
	clock_t start_time = 0;
	long long junk;
	long long iter = 0;
	float iter_total = 0;
	long long start_clocks, end_clocks, no_of_loops;
	int clocks_interval;
	float cpu_util;
  
	if (argc != 2 || argv[1] == "-h" || argv[1] == "-help") {
		printf ("\nUSAGE: measure_mhz <update interval>\n\n");
		printf ("This program will measure CPU utilization of a background task.\n");
		printf ("<update interval> will need to be tuned for a particular CPU frequency\n");
		printf ("On a 3GHz Pentium an update interval of 20000 refreshes about every 1 second\n");
		printf ("with nothing else running. As the CPU\n");
		printf ("becomes loaded with other things the background task will run and update slower.\n");
		printf ("This will allow you to estimate what the utilization of higher priority tasks is.\n");
		printf ("The best way to use this program is as a low priority background task. For example:\n\n");
		printf ("nice -n 19 ./measure_mhz 20000\n\n");
		printf ("The output is a comma delinated so it can be saved to a .csv file for use in excel\n");
		printf ("Time interval is the actual time that elapsed through the process.\n");
		printf ("Process Clocks is the number of clock cycles that were used in the process.\n");
		printf ("CPU Utilization calculates from the other two values what percentage of the\n");
		printf ("CPU was used in the background task.\n\n");
		return 0;
	}

	no_of_loops = atoi(argv[1]) * NUMBER_OF_LOOPS_MULTIPLIER;

	///printf("TIME INTERVAL  ,PROCESS CLOCKS     ,CPU_UTILIZATION\n");
	printf("CPU_UTILIZATION\n");

	start_clocks = clock();

	while (1) {
	
		if (gettimeofday(mytime, myzone)) {
    		printf("TIME OF DAY ERROR!\n");
	    	return -1;
  		}

		start_time = 1000000 * mytime->tv_sec + mytime->tv_usec;
		junk = 0;

		for (i = 0; i < no_of_loops; i++) { /* Do something heavy to occupy CPU */
    		junk++;
	    	junk = junk / 3152;
		}

		end_clocks = clock();

		/* Grab the actual time and time process took */
		if (gettimeofday(mytime, myzone)) {
   			printf("TIME OF DAY ERROR!\n");
			return -1;
		}
   
		/* Calculate actual time interval */
		end_time = 1000000 * mytime->tv_sec + mytime->tv_usec;
		interval = end_time - start_time;

		/* Calculate process time interval */
		clocks_interval = end_clocks - start_clocks;
		start_clocks = end_clocks;		

		cpu_util = ((float) clocks_interval / (float) CLOCKS_PER_SEC) / ((float) interval / 1000000);
#if 0
		printf("\n Clock Interval: %f", ((float) clocks_interval));
		printf("\n Clock Per Sec : %f", ((float) CLOCKS_PER_SEC));
        printf("\n Process Time Intercval: %f\n", ((float) interval));
#endif
   
		//printf("%i             , %i        ,",interval, clocks_interval);
		printf("%f \n",cpu_util);
	
		iter++;
		iter_total = iter_total + cpu_util;

		if (iter == 10) {
			printf("\n******** Average for 10 Iterations");
			printf("\n Average CPU Utilization: %f", ((float)iter_total/(float)iter));
			printf("\nCPU_UTILIZATION\n");
			iter = 0;
			iter_total = 0;
		}

	}
}
