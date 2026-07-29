#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>//For exit()
int main(int argc, char *argv[]){
printf("Before execv\n");
//Replace current process with "/bin/ls"
char *args[]={"ls","-l",NULL};//NULL terminates the argument list
if(execv("/bin/ls",args)==-1){
perror("execv failed");//Print error message if execv fails
exit(1);//Exit with failure status
}
//This line will not be executed unless execv() fails
printf("After execv \n");
return 0;
}