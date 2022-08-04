/*

Program Number 4
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to open an existing file with read write mode. Try O_EXCL flag also.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	char buf[1000];
	int st = open("files/3_testfile", O_RDWR & O_EXCL);	
	printf("Status: %d\n", st);

	read(st, buf, sizeof(buf));
	printf("Data:\n%s", buf);
	return 0;
}
