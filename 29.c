/*

Program Number 29
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sched.h>

int main(){

	struct sched_param prior;
	chdir("/");
	int process_pid = 1;
	prior.sched_priority = 89;
	printf("Current priority: %d\n", sched_getscheduler(process_pid));
	int val = sched_setscheduler(process_pid, SCHED_RR, &prior);
	printf("Current priority (SCHED_RR): %d\n", sched_getscheduler(process_pid));
	val = sched_setscheduler(process_pid, SCHED_FIFO, &prior);
	printf("Current priority (SCHED_FIFO): %d\n", sched_getscheduler(process_pid));

	

	return 0;
}
