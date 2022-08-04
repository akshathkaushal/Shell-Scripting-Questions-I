/*

Program Number 12
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to find out the opening mode of a file. Use fcntl

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	int fd = open("files/11_testfile", O_RDWR);	
	printf("%d\n", fcntl(fd, F_GETFL));

	return 0;
}
