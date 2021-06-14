#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>





// constants
#define COUNTERS_SIZE 256
#define BUFFER_SIZE 1024





// functions
int ergate(int code)
{
	if (code < 0)
	{
		perror("Error occured");
		exit(errno);
	}

	return code;
}





// main
int main(int argc, char *argv[])
{
	// Get file descriptior
	int fd = 0; // stdin
	if (argc > 1)
		fd = ergate(open(argv[1], O_RDONLY));

	long counters[COUNTERS_SIZE];
	memset(counters, 0, sizeof(long) * COUNTERS_SIZE);



	// Counting
	char buf[BUFFER_SIZE];
	int count;
	while ( (count = read(fd, buf, BUFFER_SIZE)) > 0 )
	{
		for (int i = 0; i < count; ++i)
		{
			if (buf[i] < 0 || buf[i] > COUNTERS_SIZE)
			{
				fprintf(stderr, "Error: unresolved symbol '%c'\n", buf[i]);
				exit(1);
			}

			++counters[(int)buf[i]];
		}
	}
	
	
	
	// Printing table
	printf(" SYMN | SYMV | COUNT \n");

	for (int row = 0; row < COUNTERS_SIZE; ++row)
	{
		if (!counters[row])
			continue;

		printf(
			" %4i |  %-3c | %7li \n",
			row, isgraph(row) ? (char)row : ' ',
			counters[row]
		);
	}



	return 0;
}





// end
