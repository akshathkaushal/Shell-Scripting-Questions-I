/*

Program Number 9
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
 Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change

*/
#include<time.h>
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	struct stat file_des;
	stat("files/3_testfile", &file_des);
	printf("Inode: %d\n", file_des.st_ino);
	printf("Number of hard links: %d\n", file_des.st_nlink);
	printf("UID: %o\n", file_des.st_uid);
	printf("GID: %o\n", file_des.st_gid);
	printf("Size: %d\n", file_des.st_size);
	printf("Block size: %d\n", file_des.st_blksize);
	printf("Number of blocks: %d\n", file_des.st_blocks);
	printf("Time of last access: %s", ctime(&file_des.st_atim));
	printf("Time of last modification: %s", ctime(&file_des.st_mtim));
	printf("Time of last change: %s", ctime(&file_des.st_ctim));


	return 0;
}
