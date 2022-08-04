/*

Program Number 6
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	char buff[100];
	int inp = read(0, buff, sizeof(buff)+1);
	write(1, buff, inp);	

	return 0;
}
