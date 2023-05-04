#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main(int argc, char *argv[]) {
   
    int n = atoi(argv[1]);
    pid_t pid;
    for (int i = 0; i < n; i++) {
        pid = fork();
        if (pid < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid == 0) {
            printf("Child process with PID %d\n", getpid());
            sleep(10);
        } else {
            wait(NULL);
            printf("Parent process with PID %d create a child process with PID %d\n", getpid(), pid);
            exit(EXIT_SUCCESS);
        
    }
    return EXIT_SUCCESS;
    }
}
