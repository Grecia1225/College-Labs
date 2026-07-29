#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
int main()
{int i,pid;
pid=fork();//creating a child process
if(pid==-1)
{printf("Fork failed\n");
exit(1);
}
else if(pid==0)//Child process
{printf("\n Child process starts \n");
for(i=0;i<5;i++)
{printf("\n Child process %d is called",i);}
printf("\n Child process ends \n");
exit(0);//Exit the child process
}
else{//Parent process
int status;
wait(&status);//Parent waits for the child to complete
printf("\n Parent process ends \n");
}
return 0;
}