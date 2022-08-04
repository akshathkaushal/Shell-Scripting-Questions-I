/*

Program Number 11
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
 Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	char buf1[8] = "1<test>1";
	char buf2[8] = "2<test>2";
	
	// using dup
	int fd1_dup = open("files/11_testfile", O_RDWR);
	int fd2_dup = dup(fd1_dup);
	//write(fd1_dup, buf1, sizeof(buf1));	
	//write(fd2_dup, buf2, sizeof(buf2));
	
	//// using dup2
	//int fd1_dup2 = open("files/11_testfile", O_RDWR), fd2_dup2;
	//int che = dup2(fd1_dup2, fd2_dup2);
	//printf("%d %d\n", fd1_dup2, fd2_dup2);
	//write(fd1_dup2, buf1, sizeof(buf1));


	//dup2(fd1_dup2, fd2_dup2);	
	//printf("%d %d\n", fd1_dup2, fd2_dup2);
	//write(fd2_dup2, buf2, sizeof(buf2));
	
	// using fcntl	
	int fd1_fcntl = open("files/11_testfile", O_RDWR), fd2_fcntl;
	write(fd1_fcntl, buf1, sizeof(buf1));

	int status = fcntl(fd1_fcntl, F_DUPFD, fd1_fcntl);
	printf("Status: %d\n", status);
	printf("%d %d\n", fd1_fcntl, status);

	write(status, buf2, sizeof(buf2));


	return 0;
}
