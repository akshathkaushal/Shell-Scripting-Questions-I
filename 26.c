/*

Program Number 26
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program. (for example execute an executable of $./a.out name)

Note: give the input from command line argument (eg. ./a.out)

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

int main(int argc, char* argv[]){

	char *list[] = {argv[1], NULL};
       	execvp(list[0], list);	

	return 0;
}
