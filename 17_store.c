/*

Program Number 17 b
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to simulate online ticket reservation. 
Implement write lock
Write a program to open a file, store a ticket number and exit. 
Write a separate program, to open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	
	int fd = open("ticketnumber.txt", O_WRONLY);
	int buf;
	int size_ticketno = read(0, &buf, sizeof(int));
	write(fd, &buf, size_ticketno); 
	write(1, &buf, size_ticketno);
	close(fd);
	return 0;
}
