#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>





// constants
#define P_COUNT 2





// main
int main(int argc, char *argv[])
{
	int pid = getpid();
	printf("Starting main proccess (%i)\n", pid);

	int cpid[P_COUNT];
	char const *progs[P_COUNT] = {
		"ychild",
		"schild"
	};

	for (int i = 0; i < P_COUNT; ++i)
	{
		cpid[i] = fork();
		if (cpid[i] == 0)
			execv(progs[i], argv);
	}

	while (wait(NULL) > 0);

	printf("\nEnding main proccess (%i)\n", pid);
	return 0;
}





// end
