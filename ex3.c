#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
   pid_t pid = fork();

   if (pid == 0) {
      // Processus enfant
      sleep(10); // Le processus enfant reste inactif pendant 10 secondes
      exit(0); // Le processus enfant se termine normalement
   } else {
      // Processus parent
      printf("Le processus enfant a été créé avec le PID %d\n", pid);
      sleep(10); // Le processus parent attend un peu pour permettre au processus enfant de passer en état zombie
      system("ps -l"); // Affiche les informations sur les processus en cours d'exécution
      wait(NULL); // Le processus parent attend la fin du processus enfant
      printf("Le processus enfant est terminé.\n");
   }

   return 0;
}
