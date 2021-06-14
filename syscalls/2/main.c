#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>  // stat
#include <sys/param.h> // NOFILE





// functions
void print_file_stats(struct stat const *st)
{
	switch(st->st_mode & S_IFMT)
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

	printf("Size: %li bytes\n", st->st_size);
	return;
}





// main
int main(int argc, char *argv[], char *envp[])
{
	// Environment variables
	for(char **var = envp; *var != NULL; ++var)
		printf("%s\n", *var);
	printf("\n");


	// Files
	printf("Maximum number of opened files is %i\n\n", NOFILE);

	struct stat st;

	FILE *file = fopen("file", "w");
	fprintf(file, "DOG > CAT\n");
	fflush(file);

	for(int fd = 0; fd < NOFILE; ++fd)
	{
		if (fstat(fd, &st) < 0)
			continue;

		printf("Stats for file with fd %i\n", fd);
		print_file_stats(&st);
		printf("\n");
	}

	fclose(file);

	return 0;
}





// end
