#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>//For exit()
int main(){
printf("Before execl\n");
//Execute "/bin/ls","lsL as argv[0],no additional arg
if (execl("/bin/ls","ls",(char*)0)==-1){
perror("execl failed");//Print error if execl fails
exit(1);//Exit with failure status
}
//This will not be executed unless execl fails
printf("After Execl\n");
return 0;
}