#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <fcntl.h>//File control options
int main(){
int fd[2];
char buf1[25]="just a test \n";
char buf2[50];
//Open files and check for errors
fd[0]=open("file1",O_RDWR | O_CREAT, 0644);
if(fd[0]==-1){
perror("Error opening file1");
return 1;
}
fd[1]=open("file2",O_RDWR | O_CREAT, 0644);
if(fd[1]==-1){
perror("Error opening file2");
close(fd[0]);//Close first file before exiting
return 1;
}
//Write initial message to file1
write(fd[0],buf1,strlen(buf1));
//Get user input safely
printf("\n Enter the text now: ");
fgets(buf1, sizeof(buf1),stdin);
//Write user input to file1
write(fd[0],buf1,strlen(buf1));
//Reset file pointer to beginning
lseek(fd[0],0,SEEK_SET);
//Read from file1 into buf2
read(fd[0],buf2,sizeof(buf1));
//Write to file2
write(fd[1],buf2,strlen(buf2));
//Close files
close(fd[0]);
close(fd[1]);
printf("\n");
return 0;
}