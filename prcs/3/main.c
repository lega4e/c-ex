#include <stdio.h>
#include <string.h>
#include <unistd.h>





// objects
#define MESSAGE_COUNT 3

char const *messages[MESSAGE_COUNT] = {
	"Hello",
	"Hello 2",
	"Hello 3"
};





// main
int main(int argc, char *argv[])
{
	int pipefd[2];

	if (pipe(pipefd) != 0)
		return 1;

	for (int i = 0; i < MESSAGE_COUNT; ++i)
		write(pipefd[1], messages[i], strlen(messages[i])+1);
	close(pipefd[1]);


	char readbuf[512];
	int const bytes = read(pipefd[0], readbuf, 512);

	for (int i = 0; i < bytes; ++i)
	{
		if (readbuf[i] == '\0')
			putchar('\n');
		else
			putchar(readbuf[i]);
	}
	close(pipefd[0]);

	return 0;
}





// end
