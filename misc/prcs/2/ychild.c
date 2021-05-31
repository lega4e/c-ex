#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>





// functions
int randi(int a, int b)
{
	return a + rand() % (b - a);
}





// main
int main(int argc, char *argv[])
{
	srand(time(NULL));

	int pid = getpid();
	printf("Stared yelling child (%i)\n", pid);

	for (int i = 0; i < 20; ++i)
	{
		usleep( 1000 * randi(100, 1000) );
		printf("AA-AA-AAAA-A-AAAAAA %i (%i)\n", i, pid);
	}
	usleep( 1000 * randi(100, 1000) );

	printf("End yelling child (%i)\n", pid);

	return 0;
}





// end
