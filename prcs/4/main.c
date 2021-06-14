#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>





// global objects
int pipefd[2];





// functions
int main_child()
{
	char intbytes[sizeof(int) + 1];
	intbytes[sizeof(int)] = '\0';

	char eof[sizeof(int) + 1];
	int const eofint = -1;
	memcpy(eof, &eofint, sizeof eofint);
	eof[sizeof eofint] = '\0';

	int ret;
	char buf[1023];
	while ( (ret = read(pipefd[0], buf, 1022)) > 0 )
	{
		memcpy(intbytes, buf, sizeof(int));
		if (strcmp(intbytes, eof) == 0)
			break;

		buf[ret] = '\0';
		printf("GET: %s\n", buf);
	}

	close(pipefd[0]);
	printf("Child proccess exit\n");
	return 0;
}





// main
int main(int argc, char *argv[])
{
	if (pipe(pipefd) != 0)
	{
		perror("Error:");
		return 1;
	}

	int cpid = fork();
	if (cpid == 0)
		return main_child();

	char buf[1024];
	int ret;
	while ( (ret = read(0, buf, 1024)) > 0 )
		write(pipefd[1], buf, ret);

	int const eof = -1;
	write(pipefd[1], &eof, sizeof eof);
	close(pipefd[1]);

	printf("Main proccess waiting for child...\n");
	fflush(stdout);
	waitpid(cpid, NULL, 0);

	printf("Main proccess exit\n");
	fflush(stdout);
	return 0;
}





// end
