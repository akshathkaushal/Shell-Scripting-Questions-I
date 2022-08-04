/*

Program Number 22
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>


int main(){
	printf("File writen at files/22.txt\n");
	int fd = open("files/22.txt", O_RDWR);	
	if(!fork()){
		const char *buff = "Child";
		write(fd, buff, sizeof(buff));
	}
	else{
		const char *buff2 = "Parent";
		write(fd, buff2, sizeof(buff2));
		wait(0);
	}
	close(fd);
	return 0;
}
