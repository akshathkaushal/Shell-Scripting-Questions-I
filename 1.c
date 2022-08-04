/*

Program Number 1
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
 Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
b. hard link (link system call)
c. FIFO (mkfifo Library Function or mknod system call)


*/



#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(void) {
	// create a softlink 
	int sft_ln = symlink("newfile", "files/newfile-softlink");
	
	// create a hard link
	int hrd_ln = link("newfile", "files/newfile-hardlink");
	
	// create FIFO
	int fifo = mknod("files/myfifo", S_IFIFO, 0666);

	printf("Status-\nHard link: %d\nSoft link: %d\nFIFO: %d\n", sft_ln, hrd_ln, fifo);

	return 0;
}
