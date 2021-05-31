#include <errno.h>
#include <stdio.h>
#include <sys/stat.h>





// main
int main(int argc, char *argv[])
{
	// Get file
	if (argc < 2)
	{
		fprintf(stderr, "Required filename in first argument\n");
		return 0;
	}

	char const *filename = argv[1];
	printf("Get information about file '%s'\n\n", filename);



	// Get stats of file
	struct stat st;
	int ret = stat(filename, &st);
	fflush(stdout);

	if (ret < 0)
	{
		perror("Error occured");
		return 0;
	}



	// Print info
	switch(st.st_mode & S_IFMT)
	{
	case S_IFLNK:
		printf("Type: symbolic link\n");
		break;

	case S_IFREG:
		printf("Type: regular file\n");
		break;

	case S_IFDIR:
		printf("Type: directory\n");
		break;

	case S_IFIFO:
		printf("Type: FIFO channel\n");
		break;

	case S_IFBLK: case S_IFCHR:
		printf("Type: device\n");
		break;

	default:
		printf("Unknown type\n");
		break;
	}

	printf("Size: %li bytes\n", st.st_size);



	return 0;
}





// end
