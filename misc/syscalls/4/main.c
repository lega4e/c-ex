#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>





// constants
#define BUF_SIZE 512





// functions
int egate(int code)
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
	// Get new and old file names
	if (argc < 3)
	{
		fprintf(stderr, "Required two arguments: old file and new file\n");
		return 1;
	}

	char const *oldfn = argv[1];
	char const *newfn = argv[2];


	// Open files and set mode
	int oldfd = egate(open(oldfn, O_RDONLY));
	struct stat oldst;
	egate(fstat(oldfd, &oldst));

	int newfd = egate(open( newfn, O_WRONLY | O_CREAT | O_TRUNC));
	fchmod(newfd, oldst.st_mode);


	// Write old file data to new file and close files
	char buf[BUF_SIZE];
	int count;
	while( (count = read(oldfd, buf, BUF_SIZE)) )
	{
		egate( write(newfd, buf, count) );
	}

	close(oldfd);
	close(newfd);


	return 0;
}





// end
