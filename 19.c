/*

Program Number 20
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to find out time taken to execute getpid system call. Use time stamp counter.

*/

#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<sys/time.h>

# include <sys/time.h>
unsigned long long rdtsc ()  
{
     unsigned long long dst;
     __asm__ __volatile__ ("rdtsc":"=A" (dst));
     return dst;  
 }



int main(){

	long long int start = rdtsc();
	int buf = getpid();
	long long int end = rdtsc();
	printf("Time taken: %lld\n", end-start);
	printf("PID = %d\n", buf);
	return 0;
}
