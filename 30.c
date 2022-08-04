/*

Program Number 30
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to run a script at a specific time using a Daemon process.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/wait.h>

int main(){

	if(!fork()){
	
		setsid();
		chdir("/");
		umask(0);
		printf("New process starting...\n");
		sleep(5);
		printf("Child PID: %d\n", getpid());
		printf("Daemon started!\n");

	}
	else{
		//wait(0);
		exit(0);
	}
	return 0;
}
