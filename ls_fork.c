#include <stdio.h>
#include <unistd.h>

#include <sys/wait.h>

int main()
{
	char *params[] = {"ls", "-a", NULL};
	int pid = fork();
	if (pid == 0) {
		// int ret = execlp("ls", "ls", "/home/hans", "-a", NULL);
		int ret = execvp("ls", params);
		printf("Exited with status %d.\n", ret);
	} else {
		wait(NULL);
		int ret = execlp("ls", "ls", "/home/hans", "-l", NULL);
		printf("Exited with status %d.\n", ret);
	}
	return 0;
}
