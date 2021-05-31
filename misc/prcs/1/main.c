#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>





// functions
void main_child1();
void main_child2();
void main_child3();

void main_child1()
{
	int cpid = fork();
	if (!cpid)
		main_child2();

	int pid = getpid();
	usleep(1 * 1000000);
	printf("\nChild 1 is living! (%i)\n", pid);
	usleep(0.5 * 1000000);
	printf("Child 1 is diying... (%i)\n", pid);
	exit(0);
}

void main_child2()
{
	if (!fork())
		main_child3();

	int pid = getpid();
	usleep(2 * 1000000);
	printf("\nChild 2 is living! (%i)\n", pid);
	usleep(0.5 * 1000000);
	printf("Child 2 is diying... (%i)\n", pid);
	exit(0);
}

void main_child3()
{
	int pid = getpid();
	usleep(3 * 1000000);
	printf("\nChild 3 is living! (%i)\n", pid);
	usleep(0.5 * 1000000);
	printf("Child 3 is diying... (%i)\n", pid);
	exit(0);
}





// main
int main(int argc, char *argv[])
{
	int pid = getpid();
	printf("Starting main proccess (%i)\n", pid);

	int cpid = fork();
	if (!cpid)
		main_child1();

	printf("Ending main proccess (%i)\n", pid);
	return 0;
}





// end
