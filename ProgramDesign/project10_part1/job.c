#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "job.h"

/////////////////////////
// function definitions //
//////////////////////////

void help() {
	printf("List of operation codes:\n");
	printf("\t'h' for help;\n");
	printf("\t'a' for adding a job to the scheduler;\n");
	printf("\t'p' for removing a job from the scheduler;\n");
	printf("\t'u' for searching jobs per user;\n");
	printf("\t'j' for searching jobs per capacity;\n");
	printf("\t'l' for listing all jobs;\n");
	printf("\t'q' for quit.\n");
 } void read(char *job_name, char *user_name, int *num_cpus, int *num_gpus, int *memory, double *time, int *priority) { if(job_name != NULL) { printf("Enter the name of the job: "); scanf("%s", job_name); } if(user_name != NULL) { printf("Enter the name of the user: "); scanf("%s", user_name); } if(num_cpus != NULL) { printf("Enter the number of CPUs: "); scanf("%d", num_cpus); } if(num_gpus != NULL) { printf("Enter the number of GPUs: "); scanf("%d", num_gpus);
	}
	if(memory != NULL) {
		printf("Enter the amount of memory: ");
		scanf("%d", memory);
	}
	if(time != NULL) {
		printf("Enter the amount of time: ");
		scanf("%lf", time);
	}
	if(priority != NULL) {
		printf("Enter the priority: ");
		scanf("%d", priority);
	}
}

/////////////////////////////////////////////////////////
// WARNING - WARNING - WARNING - WARNING - WARNING     //
/////////////////////////////////////////////////////////
// Do not modify anything before this point, otherwise //
// your solution will be considered incorrect.         //
/////////////////////////////////////////////////////////

struct job * add_job(struct job *scheduler, char *job_name, char *user_name, int num_cpus, int num_gpus, int memory, double time, int priority) {
	/// @brief the function creates a node and adds it to the linked list.

	// Creates a new node:
	struct job *new_job = (struct job *) malloc(sizeof(struct job));
	if (new_job == NULL)
	{
		printf("Error: Malloc could not allocate memory");
		return scheduler;
	}
	
	// Check if the scheduler points to null:
	if (scheduler == NULL)
	{	
		scheduler = new_job;
		new_job -> next = NULL;
	}	
	else
	{
		// Locate the intended node in the linked list:
		struct job *tail;
		struct job *head = scheduler;
		for (; (head != NULL) && (head -> priority >= priority); tail = head, head = head -> next)
			;
		// Change the address stored in next of the last node:
		if (head == scheduler)
		{
			new_job -> next = head;
			scheduler = new_job;
		}
		else
		{
			tail -> next = new_job;
			// Set the added node to point to the next node:
			new_job -> next = head;
		}
	}

	// Add all of the information provided to the node:
	strcpy(new_job -> job_name, job_name);
	strcpy(new_job -> user_name, user_name);
	new_job -> num_cpus = num_cpus;
	new_job -> num_gpus = num_gpus;
	new_job -> memory = memory;
	new_job -> time = time;
	new_job -> priority = priority; 
	
	// Return the scheduler:
	return scheduler;	
}

struct job * pop_job(struct job *scheduler) {

	/// @brief the function removes the first node from the linked list.
	// Checks if there are no nodes:
	if (scheduler == NULL)
		return scheduler;

	// output format
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler -> job_name, scheduler -> user_name, scheduler -> num_cpus, scheduler -> num_gpus, scheduler -> memory, scheduler -> time, scheduler -> priority);
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

	// Removes the first node from the linked list:
	struct job *p = scheduler;
	scheduler = p -> next;
	free(p); 

	return scheduler;
}

void list_user(struct job *scheduler, char *user_name) {

	/// @brief the function prompts for a user name and returns all of the jobs using that user name.

	// Check if there are on nodes:
	if (scheduler == NULL)
		return;	

	// Check if the user name is in the linked list:
	struct job *p = scheduler;
	for (; (p != NULL); p = p -> next)
		if (strcmp(p -> user_name, user_name) == 0)
			break;
	if (p == NULL)
		return;

	// output format
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	// ...
	// Print out all of the jobs from the user:
	for (; (scheduler != NULL); scheduler = scheduler -> next)
	{
		if ((strcmp(scheduler -> user_name, user_name)) != 0)
			continue;
		else
		{	
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler -> job_name, scheduler -> user_name, scheduler -> num_cpus, scheduler -> num_gpus, scheduler -> memory, scheduler -> time, scheduler -> priority); 
		    printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		}	
	}
}

void list_jobs(struct job *scheduler, int num_cpus, int num_gpus, int memory, double time) {

	/// @brief the function prompts for some information and returns all of the jobs that satisfy the requirements.
	
	// Check if there are no nodes:
	if (scheduler == NULL)
		return;

	// Check if the jobs exist:
	struct job *p = scheduler;
	for (; (p != NULL); p = p -> next)
		if (p -> num_cpus == num_cpus && p -> num_gpus == num_gpus && p -> memory == memory && p -> time == time)
			break;
	
	if (p == NULL)
		return;

	// output format
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");

	// Print out all of the nodes that match the description: 
	for (; (scheduler != NULL); scheduler = scheduler -> next)
	{
		if (scheduler -> num_gpus != num_gpus || scheduler -> num_cpus != num_cpus || scheduler -> memory != memory || scheduler -> time != time)
			continue;
		else
		{
			printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler -> job_name, scheduler -> user_name, scheduler -> num_cpus, scheduler -> num_gpus, scheduler -> memory, scheduler -> time, scheduler -> priority);
			printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
		}
	}
}

void list_all_jobs(struct job *scheduler) {

	/// @brief the function list all of the jobs stored in the linked list.

	// Check if there are no nodes:
	if (scheduler == NULL)
		return;

	// output format
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	printf("| Job name             | User name            | CPUs | GPUs | Mem. | Time   | Priority |\n");
	printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	for (;(scheduler != NULL); scheduler = scheduler -> next)
	{
        printf("| %-20s | %-20s | %4d | %4d | %4d | %6.2f | %8d |\n", scheduler -> job_name , scheduler -> user_name, scheduler -> num_cpus, scheduler -> num_gpus, scheduler -> memory, scheduler -> time, scheduler -> priority);
        printf("|----------------------|----------------------|------|------|------|--------|----------|\n");
	}		
}

struct job * clear_jobs(struct job *scheduler) {

	/// @brief the function removes all jobs from the linked list.

	// Check if there are no nodes:
	if (scheduler == NULL)
		return scheduler;
	
	// Remove all jobs:
	for (struct job *p = scheduler -> next; (p != NULL); scheduler = p, p = p -> next)
		free(scheduler);
	
	// Check that all are deleted:
	if (scheduler != NULL)
		free(scheduler);

	// Set scheduler to null:
	scheduler = NULL;
	return scheduler;
}
