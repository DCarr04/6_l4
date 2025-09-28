/*
  pipe-sync.c: Use Pipe for Process Synchronization
*/

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

// Question: Update this program to synchronize execution of the parent and
// child processes using pipes, so that we are guaranteed the following
// sequence of print messages:
// Child line 1
// Parent line 1
// Child line 2
// Parent line 2


int main()
{
  char *s, buf[1024];
  int fds[2];
  int ret, stat;
  s  = "Use Pipe for Process Synchronization\n";

  /* create pipe */
  pipe(fds);

  ret = fork();
  if (ret == 0) {

    /* child process. */
    //write
    printf("Child line 1\n");
    read(fds[0], buf, strlen(s));
    printf("Child line 2\n");
  } else {

    /* parent process */
    //read(fds[0], buf, strlen(s));
    printf("Parent line 1\n");
    write(fds[1], buf, strlen(s));
    printf("Parent line 2\n");

    wait(&stat);
  }
}
