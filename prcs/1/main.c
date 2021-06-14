#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>





// functions
int main_child1()
{
	int pid = getpid();
	usleep(1 * 1000000);
	printf("\nChild 1 is living! (%i)\n", pid);
	usleep(0.5 * 1000000);
	printf("Child 1 is diying... (%i)\n", pid);
	return 0;
}

int main_child2()
{
	int pid = getpid();
	usleep(2 * 1000000);
	printf("\nChild 2 is living! (%i)\n", pid);
	usleep(0.5 * 1000000);
	printf("Child 2 is diying... (%i)\n", pid);
	return 0;
}

int main_child3()
{
	int pid = getpid();
	usleep(3 * 1000000);
	printf("\nChild 3 is living! (%i)\n", pid);
	usleep(0.5 * 1000000);
	printf("Child 3 is diying... (%i)\n", pid);
	return 0;
}





// main
int main(int argc, char *argv[])
{
	int pid = getpid();
	printf("Starting main proccess (%i)\n", pid);

	int cpid[3];
	int (*pfun[3])(void) = {
		main_child1,
		main_child2,
		main_child3
	};

	for (int i = 0; i < 3; ++i)
	{
		cpid[i] = fork();
		if (cpid[i] == 0)
			return pfun[i]();
	}

	for (int i = 0; i < 3; ++i)
		waitpid(cpid[i], NULL, 0);

	printf("\nEnding main proccess (%i)\n", pid);
	return 0;
}





// end
