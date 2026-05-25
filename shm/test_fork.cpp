#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>

namespace { //=================================================================

int test_execlp()
{
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork() failed.\n");

        return 1;
    } else if (0 == pid) {
        pid_t pid0 = getpid();
        printf("[child] PID: %d\n", pid0);
        fflush(stdout);

        execlp("/bin/ls", "ls", NULL);
        printf("[child] LINE J\n");

    } else {
        wait(NULL);
        printf("[parent] Child complete.\n");
    }

    return 0;
}

int test_pid()
{
    pid_t pid = fork();

    if (pid < 0) {
        fprintf(stderr, "fork() failed.\n");

        return 1;
    } else if (0 == pid) {
        pid_t pid0 = getpid();
        printf("[child] pid : %d\n", pid);
        printf("[child] pid0: %d\n", pid0);
    } else {
        pid_t pid0 = getpid();
        printf("[parent] pid : %d\n", pid);
        printf("[parent] pid0: %d\n", pid0);

        wait(NULL);
    }

    return 0;
}

} //===========================================================================

int test_fork()
{
    return
        //test_execlp();
        test_pid();
}