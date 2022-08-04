/*

Program Number 7
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to copy file1 into file2 ($cp file1 file2).

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include<limits.h>


int main(void) {

	char buff;
	int fd_open = open("files/3_testfile", O_RDONLY);
	int fd_write = open("files/7_testfile", O_CREAT|O_RDWR, 0744);
	while(read(fd_open, &buff, 1))
	{
		write(fd_write, &buff, 1);
	}

	return 0;
}
