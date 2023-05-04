#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   int child_pid = fork();

   if (child_pid == 0) {
      // Processus enfant
      int return_val;
      printf("Enter a value : ");
      scanf("%d", &return_val);
      exit(return_val); //Le processus retourne la valeur
   } else {
      // Processus parent
      int status;
      wait(&status); // On attent que le processus enfant se termine
      if (status != -1) { //Le processus parent vérifie que le statut n'est pas -1, ce qui indique que le processus enfant s'est terminé normalement
         int return_val = status >> 8; // Get child process return value
         printf("Parent process (%d) received child process (%d) return value: %d\n", getpid(), child_pid ,return_val);
      
   }

   return 0;
    }
}   