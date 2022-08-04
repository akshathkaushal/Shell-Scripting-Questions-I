/*

Program Number 14
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	char path[100];
	//read(0, &path, sizeof(path));	
	scanf("%s", path);
	printf("File name: %s\n", path);
	struct stat file;
	stat(path, &file);

	switch(file.st_mode & S_IFMT){
		case S_IFBLK:
			printf("Type: Block Device\n");
			break;
		case S_IFCHR:
			printf("Type: Character Device\n");
			break;
		case S_IFDIR:
			printf("Type: Directory\n");
			break;
		case S_IFIFO:
			printf("Type: FIFO/Pipe\n");
			break;
		case S_IFLNK:
			printf("Type: Symlink\n");
			break;
		case S_IFREG:
			printf("Type: Regular File\n");
			break;
		case S_IFSOCK:
			printf("Type: Socket\n");
			break;
	
		default:
			printf("Type: Unknown\n");
	}

	return 0;
}
