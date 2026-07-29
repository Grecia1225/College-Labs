#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#define MSG_SIZE 29
int main(){
int ser[2],cli[2],pid;
char inbuff[MSG_SIZE];
char *msg="Thank you";
system("clear");
//Create pipes
if(pipe(ser)==-1 || pipe(cli)==-1){
perror("Pipe creation failed.");
return 1;
}
printf("\n Server read id=%d,write id=%d",ser[0],ser[1]);
printf("\n Client read id=%d, write id=%d",cli[0],cli[1]);
pid=fork();
if(pid<0){
perror("Fork failed");
return 1;
}
//Child process (client)
if(pid==0)
{printf("\n I am in the child process !");
close(cli[0]);
close(ser[0]);
write(cli[1],msg,strlen(msg)+1);
printf("\n Message written to pipe...!");
sleep(2);
read(ser[0],inbuff,MSG_SIZE);
printf("\n Echo message received from server");
printf("\n %s\n",inbuff);
close(cli[1]);
}
//Parent process
else{
close(cli[1]);
close(ser[0]);
printf("\n Parent process");
read(cli[0],inbuff,strlen(inbuff)+1);
printf("\n Parent ended!\n");
close(cli[0]);
close(ser[1]);
}
return 0;
}