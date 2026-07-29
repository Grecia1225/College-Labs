#include<pthread.h>
#include<stdio.h>
#define NUM_THREADS 3
int je=0,jo=0;
int evensum=0,sumn=0,oddsum=0;
int evenarr[50],oddarr[50];
pthread_mutex_t lock;//Mutex for synchronization
void *Even(void *threadid){
int i,n=*(int *)threadid;
pthread_mutex_lock(&lock);//Locking shared variables
for (i=1;i<=n;i++){
if(i%2==0){
evenarr[je]=i;
evensum+=i;
je++;
}
}
pthread_mutex_unlock(&lock);//Unlocking
pthread_exit(NULL);
}
void *Odd(void *threadid){
int i,n=*(int*)threadid;
pthread_mutex_lock(&lock);
for(i=1;i<=n;i++){
if(i%2!=0){
oddarr[jo]=i;
oddsum+=i;
jo++;
}
}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
void *SumN(void *threadid){
int i,n=*(int *)threadid;
pthread_mutex_lock(&lock);
for(i=1;i<=n;i++)
{sumn+=i;}
pthread_mutex_unlock(&lock);
pthread_exit(NULL);
}
int main(){
pthread_t threads[NUM_THREADS];
int i,t;
pthread_mutex_init(&lock,NULL);//Initialize mutex
printf("Enter a number: ");
scanf("%d",&t);
//Pass address of t so each thread gets correct input
pthread_create(&threads[0],NULL,Even,(void *)&t);
pthread_create(&threads[1],NULL,Odd,(void *)&t);
pthread_create(&threads[2],NULL,SumN,(void *)&t);
//Wait for threads to complete
for(i=0;i<NUM_THREADS;i++){
pthread_join(threads[i],NULL);
}
printf("\nThe sum of first N natural numbers is:%d\n",sumn);
printf("The sum of first N even natural numbers is:%d\n",evensum);
printf("The sum of first N odd natural numbers is:%d\n",oddsum);
printf("\n First N even natural numbers:\n");
for(i=0;i<je;i++)
{printf("%d ",evenarr[i]);}
printf("\n\nFirst odd natural numbers:\n");
for(i=0;i<jo;i++)
{printf("%d ",oddarr[i]);}
printf("\n");
pthread_mutex_destroy(&lock);//Destroy mutex
pthread_exit(NULL);
}