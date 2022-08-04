/*

Program Number 28
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to get maximum and minimum real time priority.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sched.h>

int main(){

	printf("Maximum priority: %d\n", sched_get_priority_max(SCHED_RR));
	printf("Minimum priority: %d\n", sched_get_priority_min(SCHED_RR));
	return 0;
}
