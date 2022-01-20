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
	printf("Stared smacking child (%i)\n", pid);

	for (int i = 0; i < 7; ++i)
	{
		usleep( 1000 * randi(300, 3000) );
		printf("S-CH %i, (%i)\n", i, pid);
	}
	usleep( 1000 * randi(300, 3000) );

	printf("End smacking child (%i)\n", pid);

	return 0;
}





// end
