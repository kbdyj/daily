#include <sys/types.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 25
#define READ_FD     0
#define WRITE_FD    1

int test_pipe()
{
    char wbuf[BUFFER_SIZE] = "Hello, Qt6";
    char rbuf[BUFFER_SIZE];
    int fd[2];

    if (-1 == pipe(fd)) {
        fprintf(stderr, "pipe failed.\n");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork failed.\n");
        return 1;
    }

    if (0 < pid) { // parent
        close(fd[READ_FD]);
        write(fd[WRITE_FD], wbuf, strlen(wbuf) + 1);
        close(fd[WRITE_FD]);
    } else { // child
        close(fd[WRITE_FD]);
        read(fd[READ_FD], rbuf, BUFFER_SIZE);
        printf("read: %s\n", rbuf);
        close(fd[READ_FD]);
    }
    return 0;
}