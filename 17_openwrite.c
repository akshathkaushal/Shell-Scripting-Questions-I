/*

Program Number 17 a
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
	int fd = open("ticketnumber.txt", O_RDWR|O_EXCL);
	
	struct flock filelock;
	filelock.l_type = F_WRLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start=0;
	filelock.l_len = 0;
	filelock.l_pid = getpid();

	int lck = fcntl(fd, F_SETLKW, &filelock);
	printf("File write lock status: %d\n", lck);

	int current_ticket_no;
	read(fd, &current_ticket_no, sizeof(int));
	//current_ticket_no = current_ticket_no - '0';
	current_ticket_no = current_ticket_no + 1;
	printf("From code: %d\n", current_ticket_no);
	lseek(fd, 0, SEEK_SET);
	write(fd, &current_ticket_no, sizeof(int));

	filelock.l_type = F_UNLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);
	printf("File unlock status: %d\n", lck);
	
	lseek(fd, 0, SEEK_SET);

	int newvalue;
	read(fd, &newvalue, sizeof(int));
	write(1, &newvalue, sizeof(int));

	close(fd);


	return 0;
}
