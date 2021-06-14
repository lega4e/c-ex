#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

// constants
#define BUF_SIZE 512

// objects
int			g_oldfd;
int			g_newfd;

char const	*g_oldfn;
char const	*g_newfn;

// functions
int	egate(int code)
{
	if (code < 0)
	{
		perror("Error occured");
		exit(errno);
	}
	return (code);
}

// main
int	main(int argc, char *argv[])
{
	struct stat	oldst;
	char		buf[BUF_SIZE];
	int			count;

	if (argc < 3)
	{
		fprintf(stderr, "Required two arguments: old file and new file\n");
		return (1);
	}
	g_oldfn = argv[1];
	g_newfn = argv[2];
	g_oldfd = egate(open(g_oldfn, O_RDONLY));
	egate(fstat(g_oldfd, &oldst));
	g_newfd = egate(open(g_newfn, O_WRONLY | O_CREAT | O_TRUNC));
	fchmod(g_newfd, oldst.st_mode);
	count = read(g_oldfd, buf, BUF_SIZE);
	while (count)
	{
		egate(write(g_newfd, buf, count));
		count = read(g_oldfd, buf, BUF_SIZE);
	}
	close(g_oldfd);
	close(g_newfd);
	return (0);
}

// end
