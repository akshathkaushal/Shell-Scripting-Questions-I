/*

Program Number 25
Name: Akshath Kaushal
Roll no. IMT2018501
Date: February 20, 2021

Description:
Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/wait.h>

// first try

/*int main(){
	printf("Initial PID = %d\n", getpid());

	int pid1 = fork();
	int pid2 = fork();
	int pid3 = fork();
	printf("PID1 = %d, being called from %d\n", pid1, getpid());
	printf("PID2 = %d, being called from %d\n", pid2, getpid());
	printf("PID3 = %d, being called from %d\n", pid3, getpid());
	
	return 0;
}*/


// second try

int main(){
	int pid1 = fork(), temp;
	if(pid1==0){
		printf("Child 1, pid = %d, parent = %d\n",  getpid(), getppid());

	} else{
		int pid2 = fork();
		if(pid2==0){
			printf("Child 2, pid = %d, parent = %d\n",  getpid(), getppid());

		}else{
			int pid3 = fork();
			if(pid3==0){
				printf("Child 3, pid = %d, parent = %d\n", getpid(), getppid());
			}else{
				waitpid(pid1, &temp, 0);
				printf("Parent is executing...\n");
			}


		}


	}


	return 0;
}
