#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;
    FILE *file = fopen("pids.txt", "w");
    if (!file) {
        perror("Failed to open file");
        return 1;
    }

    pid = fork();

    if (pid < 0) {
        perror("Fork failed");
        fclose(file);
        return 1;
    }

    if (pid == 0) {
        fprintf(file, "Child PID: %d\n", getpid());
    } else {
        fprintf(file, "Parent PID: %d\n", getpid());
        wait(NULL);
	printf("pids.txt created.\n");
    }

    fclose(file);
    return 0;
}

