#include <fcntl.h>
#include <stdio.h>
#include <sys/param.h>





// functions
char const *gfflags(int fd)
{
	int flags = fcntl(fd, F_GETFL, NULL);

	if (flags < 0)
		return NULL;

	if (flags & O_WRONLY)
		return "w";

	if (flags & O_RDONLY)
		return "r";

	if (flags & O_RDWR)
		return "r+w";

	return "unknown";
}





// main
int main(int argc, char *argv[])
{
	FILE *wfile  = fopen("wfile", "w");
	FILE *rfile  = fopen("rfile", "r");
	FILE *rwfile = fopen("rwfile", "rw");

	char const *flags;
	for(int fd = 0; fd < NOFILE; ++fd)
	{
		flags = gfflags(fd);
		if (flags == NULL)
			continue;

		printf("%i: %s\n", fd, flags);
	}

	if (wfile)  fclose(wfile);
	if (rfile)  fclose(rfile);
	if (rwfile) fclose(rwfile);



	return 0;
}





// end
