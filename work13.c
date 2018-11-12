#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <fcntl.h>
static void sighandler(int signo){
  if(signo == SIGUSR1){
    printf("Parent PID: %d\n",getppid());
  }
  else if(signo == SIGINT){
    int x = open("headsup.txt",O_WRONLY|O_CREAT,0766);
    char warning []= "Program exited due to SIGINT\n";
    write(x,warning,sizeof(warning));
    close(x);
    exit(0);
  }
}
int main(){
  signal(SIGINT,sighandler);
  signal(SIGUSR1,sighandler);
  while(1){
    printf("PID: %d\n", getpid());
    sleep(1);
  }
  return 0;
}
