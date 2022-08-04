/*

Program Number 15
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to display the environmental variable of the user (use environ).

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	extern char** environ;
	int i=0;
	while(environ[i] != NULL){
		printf("%s\n", environ[i]);
		i++;
	}

	return 0;
}
