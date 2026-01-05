#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>
int main()
{
 pid_t pid;
 int status;
 pid = fork();
 if (pid == 0)
 {
 // Child
 printf("Child process (PID: %d)\n", getpid());
 execlp("ls", "ls", NULL);
 exit(0);
 }
 else
 {
 // Parent
 printf("Parent process (PID: %d)\n", getpid());
 printf("Parent waiting for the child (PID: %d) to finish\n",pid);
 wait(&status);
 printf("Child process exited with status %d\n",
WEXITSTATUS(status));
 }
 return 0;
}
