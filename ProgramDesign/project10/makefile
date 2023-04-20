project10_scheduler: project10_scheduler project10_scheduler.o job.o
	gcc -std=c99 -Wall -o project10_scheduler project10_scheduler.o job.o
job.o: job.o job.h 
	gcc -std=c99 -Wall -c -o job.o job.c
project10_scheduler.o: project10_scheduler.o job.h
	gcc -std=c99 -Wall -c -o project10_scheduler.o project10_scheduler.c
