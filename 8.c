/*

Program Number 8
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>
#include<sys/stat.h>


int main(void) {
	
	char buff, inp;
	int fd = open("files/3_testfile", O_RDONLY);
    
    int count=0;
    while(read(fd, &buff, 1)){
        if(buff=='\n'){
            char buf[count];
            lseek(fd, -count-1, SEEK_CUR);
            read(fd, &buf, count);
            write(1, &buf, sizeof(buf));
            count=0;   
            lseek(fd, count+1, SEEK_CUR);
            write(1, &buff, 1);
        }    
        else{
            count++;
        }

    }	

    /*
	while(read(fd, &buff, 1))
	{
		if(buff=='\n'){
			read(0, &inp, 1); //getchar()
		}
		write(1, &buff, 1);
	}*/
	close(fd);
	
	
	return 0;
}
