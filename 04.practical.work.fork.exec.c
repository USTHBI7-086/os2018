 #include <unistd.h>
#include <stdio.h>

int main() {
  printf("Main before fork()\n");
  int pid = fork();
  if (pid == 0) {
    char *freeh[]= { "free", "-h" , NULL};
    execvp("free", freeh);
  }
  else
  {
    char *ps[]= { "/bin/ps", "-ef" , NULL};
    execvp("/bin/ps", ps);
  }
  return 0;
}
