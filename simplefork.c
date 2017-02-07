#include <sys/types.h>
#include <sys/wait.h>
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include "option_parse.h"

#define TRUE 1
#define FALSE 0

int main(int argc, char** argv) {
  char options_string[8] = "uN:M:ps:";
  
  int opt = initializeOptions(argc, argv, options_string);
  if(opt == 1){
    return 1;
  }

  
  pid_t pid = 0, this_pid ,ppid; // for a child process 
  this_pid = getpid();
  ppid = getppid();

  printf("ALIVE: Level %d process with pid=%d, child of ppid=%d.\n", num_lvl, this_pid, ppid);
 
  if(num_lvl < 2){
    if(p_flag){
      pause();
    }else{
      sleep(slp_tim);
    }
    printf("EXITING: Level %d process with pid=%d, child of ppid=%d.\n", num_lvl, this_pid, ppid);
    return 0;
  }

  
  int i = 0;
  for(i = 0; i < num_chd; i++){
    pid = fork();
    if (pid < 0) { // error
      fprintf(stderr, "Fork failed.\n");
      return 1;
    }else if (pid == 0) { //child process 
      execv("prog2tree", argv);
    }
  }
  wait(NULL);
  sleep(1);
  
  printf("EXITING: Level %d process with pid=%d, child of ppid=%d.\n", num_lvl, this_pid, ppid);

  
  return 0;
}
