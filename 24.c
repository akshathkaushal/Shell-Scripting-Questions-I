/*

Program Number 24
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to create an orphan process.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
		
	if(!fork()){
		printf("Before being orphan:\npid: %d\nparent pid: %d\n", getpid(), getppid());
		sleep(5);
		printf("After being orphan:\npid: %d\nparent pid: %d\n", getpid(), getppid());
	}else{
			printf("Parent process starting...\npid: %d\n", getpid());
	}


	return 0;
}
