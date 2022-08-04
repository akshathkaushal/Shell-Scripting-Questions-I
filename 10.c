/*

Program Number 10
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	int fd = open("files/10_testfile", O_RDWR);	
	int w1 = lseek(fd, 10, SEEK_CUR);
	char buf[10];
	printf("Enter the text: ");
	scanf("%[^\n]", buf);
	printf("buff = %s\n", &buf);
	write(fd, &buf, 10);
	lseek(fd, 10, SEEK_CUR);
	write(fd, &buf, 10);	
		

	return 0;
}
