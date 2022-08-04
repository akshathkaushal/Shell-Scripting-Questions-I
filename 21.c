/*

Program Number 21
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program, call fork and print the parent and child process id.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

int main(){
	
	if(!fork()){
		printf("Child process id = %d\n", getpid());

	}
	else{
		printf("Parent process id = %d\n", getppid());
		wait(0);
	}

	return 0;
}
