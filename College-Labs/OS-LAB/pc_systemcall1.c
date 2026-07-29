#include <stdio.h>//for printf
#include <unistd.h>//for fork,getpid,getppid
#include <sys/types.h>//for pid_t
#include <sys/wait.h>//for wait()
int main()
{
int id, childid;
id=getpid();//get process ID before fork
if ((childid=fork())>0){//Parent process
printf("\n I am in the Parent process. My PID:%d",id);
printf("\n I am in the Parent process. My PID (After fork):%d",getpid());
printf("\n I am in the Parent process. My parent PID:%d\n",getpid());
wait(NULL);//wait for child to finish execution
}
else if(childid==0){//Child process
printf("\n I am in the child process. Parent PID:%d",id);
printf("\n I am in the child process. My PID:%d",getpid());
printf("\n I am in the child process. My parent PID:%d\n",getppid());
}
else{//Fork failed
printf("\n Fork failed.");
}
}