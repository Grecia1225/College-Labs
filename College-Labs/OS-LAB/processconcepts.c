#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <signal.h>
void execute_execvp(){
char *args[]={"ls","-l",NULL};//Arguments for execvp
execvp(args[0],args);
perror("execvp failed");//If exec fails
exit(1);
}
int main(){
pid_t pid;
pid=fork();//Create a child process
if(pid<0){
perror("Fork failed");
exit(1);
}
if(pid==0){//Child process
printf("Child Process (PID:%d) executing execvp()... \n",getpid());
execute_execvp();//Replaces the child process 
}
else{//Parent process
printf("Parent Process (PID:%d) waiting for child... \n",getpid());
wait(NULL);//Wait for child to complete
printf("Child process finished. Parent continues.\n");
printf("Killing parent process... \n");
kill(getpid(), SIGTERM);//Terminate the parent 
}
return 0;
}