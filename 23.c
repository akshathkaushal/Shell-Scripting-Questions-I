/*

Program Number 23
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to create a Zombie state of the running program.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/time.h>
#include<sys/wait.h>

int main(){

	if(!fork()){
		printf("Child process...\n");
	}
	else{
		sleep(5);
		printf("Parent process... exiting\n");
	}
	return 0;
}
