#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void create_binary_tree(int height) {
    pid_t pid1, pid2;
    if (height == 0) {
        return;
    }
    pid1 = fork();
    if (pid1 < 0) {
        exit(EXIT_FAILURE);
    } else if (pid1 == 0) {
         // Processus 1 enfant
        printf("Parent (%d) -> Child process with PID %d\n", getppid(), getpid());
        sleep(10);
        create_binary_tree(height - 1); //récursivité
        exit(EXIT_SUCCESS);
    } else {
        // Processus  1 parent
        pid2 = fork(); 
        if (pid2 < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        } else if (pid2 == 0) {
            // Processus 2 enfant
            printf("Parent (%d) -> Child process with PID %d\n", getppid(), getpid());
            sleep(10);
            create_binary_tree(height - 1);
            exit(EXIT_SUCCESS);
        } else {
            // Processus  2 parent
            wait(NULL);  // Le processus parent attend la fin du processus enfant
            wait(NULL);  
            printf("Parent process with PID %d create children with PIDs %d and %d\n", getpid(), pid1, pid2);
            exit(EXIT_SUCCESS);
        }
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Usage: %s <height>\n", argv[0]);
        return EXIT_FAILURE;
    }
    int height = atoi(argv[1]);
    create_binary_tree(height);
    return EXIT_SUCCESS;
}
