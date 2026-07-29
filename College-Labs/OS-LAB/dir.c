#include <stdio.h>
#include <dirent.h>//Directory-handling function opendir(),readdir(),closedir()
#include <errno.h>
#include <stdlib.h>//Functions like malloc(),free(),exit(),atoi()
#include <unistd.h>//provides access to POSIX operating system API functions
int main(int argc, char *argv[]){
struct dirent *direntp;
DIR *dirp;
//Check if directory name is provided 
if(argc!=2){
printf("Usage:%s <directory_name> \n",argv[0]);
return EXIT_FAILURE;
}
//Attempt to open directory
if((dirp=opendir(argv[1]))==NULL){
perror("Failed to open directory");
return EXIT_FAILURE;
}
//Read and print directory entries
while((direntp=readdir(dirp))!=NULL){
printf("%s\n",direntp->d_name);
}
//CLose directory stream
if (closedir(dirp)==-1){
perror("Failed to close directory");
return EXIT_FAILURE;
}
return EXIT_SUCCESS;
}