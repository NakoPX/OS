#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main() {
    int pipefds[2];
    char signal = '1'; // A simple signal indicator
    char buffer;

    if (pipe(pipefds) == -1) {
        perror("pipe failed");
        return 1;
    }

    pid_t pid = fork();

    if (pid < 0) {
        perror("fork failed");
        return 1;
    }

    if (pid == 0) {
        close(pipefds[1]);
        printf("Child is waiting for a signal from the parent...\n");
        read(pipefds[0], &buffer, 1); // Wait for the "signal"
        if (buffer == '1') {
            printf("Child received the signal from the parent!\n");
        }
        close(pipefds[0]);
    } else { 
        close(pipefds[0]); 
        printf("Parent is sending a signal to the child...\n");
        write(pipefds[1], &signal, 1); // Send a "signal" to the child
        close(pipefds[1]);
    }

    return 0;
}
