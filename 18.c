/*

Program Number 18
Name: Akshath Kaushal
Roll no. IMT2018501
Date: January 21, 2021

Description:
Write a program to perform Record locking.
a. Implement write lock
b. Implement read lock
Create three records in a file. Whenever you access a particular record, first lock it then modify/access
to avoid race condition.

*/
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

struct train_ticket{
	int train;
	int count;
};


int main(){
	
	int fd = open("record.txt", O_RDWR|O_EXCL);
	printf("File status: %d\n", fd);

	struct train_ticket rec1 = {17, 0};
	struct train_ticket rec2 = {18, 0};
	struct train_ticket rec3 = {19, 0};
	
	lseek(fd, 0, SEEK_SET);
	

	struct flock filelock;

	filelock.l_type = F_UNLCK;
        filelock.l_whence = SEEK_SET;
        filelock.l_start = 0;
        filelock.l_len = 0;
        filelock.l_pid = getpid();
	int lck = fcntl(fd, F_SETLKW, &filelock);

	printf("Select train number: ");
	int num;
	scanf("%d", &num);

	struct train_ticket train_no;
	lseek(fd, (num-1)*sizeof(struct train_ticket), SEEK_SET);

	filelock.l_type = F_RDLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);
	int sz = read(fd, &train_no, sizeof(struct train_ticket));
	printf("Train number: %d\tTicket count: %d\n", train_no.train, train_no.count);
	filelock.l_type = F_UNLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);
	//printf("Increment count? (y/n) ");
	char clar='y';
	//scanf("%c", &clar);

	if(clar=='y'){
		filelock.l_type = F_UNLCK;
		lck = fcntl(fd, F_SETLKW, &filelock);
		filelock.l_type = F_WRLCK;
		lck = fcntl(fd, F_SETLKW, &filelock);

		train_no.count++;
		printf("Train number: %d\tNew ticket count: %d\n", train_no.train, train_no.count);
	}
	lseek(fd, (num-1)*sizeof(struct train_ticket), SEEK_SET);
	write(fd, &train_no, sizeof(struct train_ticket));	
	filelock.l_type = F_UNLCK;
	lck = fcntl(fd, F_SETLKW, &filelock);

	close(fd);

		

	return 0;
}
