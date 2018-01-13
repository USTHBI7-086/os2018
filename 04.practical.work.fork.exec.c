#include <unistd.h>
#include <stdio.h>

int main() {
  printf("Main before fork()\n");
  int pid1 = fork();
  if (pid1 == 0) {
    char *freeh[]= { "free", "-h" , NULL};
    execvp("free", freeh);
  }
  int pid2 = fork();
  if (pid2 == 0) {
    char *ps[]= { "/bin/ps", "-ef" , NULL};
    execvp("/bin/ps", ps);
  }
  return 0;
}
