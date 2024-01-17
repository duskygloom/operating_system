#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>

#define MAX_HELLOS	5

int main()
{
	int pid;
	
	/*
	 * 		parent
	 *		|	 \
	 *	parent	child1
	 *			 |   \
	 *		 child1  child2
	 *		          |   \
	 *		      child2  child3
	 */
	pid = fork();
	if (pid == 0) pid = fork();
	if (pid == 0) pid = fork();
	
	// all forks executing concurrently
	for (int i = 0; i < MAX_HELLOS; ++i) {
		printf("(%d/%d) Hello [%d]\n", i, MAX_HELLOS, getpid());
		sleep(pid % 4);
	}
	
	// waiting for children
	if (pid != 0) wait(NULL);

	return 0;
}

