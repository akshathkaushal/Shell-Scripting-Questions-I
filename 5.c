/*

Program Number 5
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
 Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	while(1){
		int f1 = open("files/4_testfile_1", O_CREAT, 0744); 
		int f2 = open("files/4_testfile_2", O_CREAT, 0744);
		int f3 = open("files/4_testfile_3", O_CREAT, 0744);
		int f4 = open("files/4_testfile_4", O_CREAT, 0744);
		int f5 = open("files/4_testfile_5", O_CREAT, 0744);
	}
	return 0;
}

/*
 *	It creates max number of files as specified in the limits file in the respective pid
 */
