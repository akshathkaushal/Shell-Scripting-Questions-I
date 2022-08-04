/*

Program Number 16
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to perform mandatory locking.
a. Implement write lock
b. Implement read lock

*/
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>

int main(int argc, char **argv){
	
	int fd = open(argv[1], O_RDWR);
	printf("File status: %d\n\n", fd);	
	struct flock filelock;

	filelock.l_type = F_RDLCK;
	filelock.l_whence = SEEK_SET;
	filelock.l_start = 0;
	filelock.l_len = 0;
	filelock.l_pid = getpid();
	
	
	int lck = fcntl(fd, F_SETLKW, &filelock);
	printf("File lock status: %d\n", lck);
	getchar();

	filelock.l_type = F_UNLCK;
	lck = fcntl(fd, F_SETLK, &filelock);
	printf("File lock: Unlock => %d\n", lck);
	getchar();

	filelock.l_type = F_WRLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);
	printf("File lock: Write lock => %d\n", lck);
	getchar();

	filelock.l_type = F_UNLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);
	filelock.l_type = F_RDLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);
	printf("File lock: Read lock => %d\n", lck);
	getchar();

	filelock.l_type = F_UNLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);


	return 0;
}
