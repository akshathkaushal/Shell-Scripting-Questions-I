/*

Program Number 13
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
 Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not (check in $man 2 select).

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(void) {

	struct timeval t_val;
	fd_set filedes;
	FD_ZERO(&filedes);
	FD_SET(0, &filedes);
	t_val.tv_sec=10;
	t_val.tv_usec=0;

	if(select(1, &filedes, NULL, NULL, &t_val)){
		printf("Data was obtained within 10 seconds!\n");
	} else{
		printf("No data was obtained within 10 seconds!\n");
	}

	return 0;
}
