/*

Program Number 3
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
 Write a program to create a file and print the file descriptor value. Use creat ( ) system call

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	int fd = creat("files/3_testfile", 0744);	
	printf("File descriptor value: %d\n", fd);
	getchar();
	return 0;
}
