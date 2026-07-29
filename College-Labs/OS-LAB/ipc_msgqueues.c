#include <sys/ipc.h>
#include <stdio.h>
#include <string.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <unistd.h>
struct msgbuf{
long mtype;
char mtext[20];
}send,recv;
int main(){
int qid,pid,len;
//creating message queue
qid=msgget((key_t)0X200,IPC_CREAT | 0666);
if(qid==-1){
perror("\n Message queue creation failed.");
exit(1);
}
send.mtype=1;
strcpy(send.mtext,"Hello, I am parent");
len=sizeof(send.mtext);
pid=fork();
if(pid>0){
//Parent process
if(msgsnd(qid,&send,len,0)==-1){
perror("\n Message sending failed.");
exit(1);
}
printf("\n Message has been posted by parent.");
sleep(2);//Give child process time to read message
if(msgrcv(qid,&recv,sizeof(recv.mtext),2,0)==-1){
perror("\n Parent: msgrcv error");
exit(1);
}
printf("\n Message received from child: %s\n",recv.mtext);
//Remove message queue
msgctl(qid,IPC_RMID,NULL);
}
else if(pid==0){
send.mtype=2;
strcpy(send.mtext,"Hi, I am child");
len=sizeof(send.mtext);
if(msgrcv(qid,&recv,sizeof(recv.mtext),1,0)==-1){
perror("\n Child: message receive failed");
exit(1);
}
printf("\n Received from parent: %s",recv.mtext);
if(msgsnd(qid,&send,len,0)==-1){
perror("\n Child: message send failed");
exit(1);}
}
else{
perror("\n Fork failed");
exit(1);
}
return 0;
}