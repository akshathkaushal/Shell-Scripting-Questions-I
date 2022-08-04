/*

Program Number 27
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
 Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execle
d. execv
e. execvp

Note: uncomment the commented lines in the code one by one
*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(){
	
	char* command[] = {"ls", "-Rl", NULL};
	//execl("/bin/ls", "ls","-Rl", 0);
	//printf("\n");
	//execle("/bin/ls", command[0], command[1], (char*) NULL, NULL); 
	//printf("\n");
	//execlp("ls", command[0], command[1], (char*) NULL);
	//printf("\n");
	//execvp("ls", command);
	execv("/bin/ls", command);
	return 0;
}
