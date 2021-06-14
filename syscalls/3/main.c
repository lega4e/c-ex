#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sys/dir.h>





// main
int main(int argc, char *argv[])
{
	// Get dirname
	char const *dirname = ".";
	if (argc > 1)
		dirname = argv[1];

	DIR *dir = opendir(dirname);
	if(!dir)
	{
		perror("Error occured");
		return errno;
	}



	// Print dir
	while(1)
	{
		struct dirent *dirinfo = readdir(dir);
		if(!dirinfo)
			break;

		if(!strcmp(dirinfo->d_name, ".") || !strcmp(dirinfo->d_name, ".."))
			continue;
		
		printf("%s\n", dirinfo->d_name);
	}



	return 0;
}





// end
