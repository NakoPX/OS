#include <stdio.h>
#include <unistd.h>

int main() {
    pid_t pid1, pid2, pid3;

    pid1 = fork();
    if (pid1 < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid1 == 0) {
        printf("First child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    }

    if (pid1 > 0) {
        printf("Parent after first fork: PID = %d\n", getpid());
    }

    pid2 = fork();
    if (pid2 < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid2 == 0) {
        printf("Second child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    }

    if (pid2 > 0) {
        printf("Parent after second fork: PID = %d\n", getpid());
    }

    pid3 = fork();
    if (pid3 < 0) {
        perror("fork failed");
        return 1;
    }
    if (pid3 == 0) {
        printf("Third child process: PID = %d, Parent PID = %d\n", getpid(), getppid());
        return 0;
    }

    if (pid3 > 0) {
        printf("Parent after third fork: PID = %d\n", getpid());
    }

    return 0;
}

