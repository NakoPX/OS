#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

void handle_signal(int sig) {
    printf("Child process received signal: %d\n", sig);
    exit(0); 
}

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        return 1;
    }

    if (pid == 0) {
        // Child process
        printf("Child process started with PID: %d\n", getpid());
        signal(SIGUSR1, handle_signal);
        while (1) {
            pause();
        }
    } else {
        // Parent process
        printf("Parent process sending signal to child PID: %d\n", pid);
        sleep(1);
        kill(pid, SIGUSR1);
        wait(NULL); // Wait for the child process to exit
    }

    return 0;
}
