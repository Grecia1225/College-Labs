#include <stdio.h>
struct process {
 int allocation[3];
 int max[3];
 int need[3];
 int finish;
} p[10];
int main() {
 int n, i, j, k = 0, flag, count = 0;
 int avail[3], work[3], sequence[10];
 // Input number of processes
 printf("\nEnter the number of processes: ");
 scanf("%d", &n);
  // Input Allocation and Max resources for each process
 for(i = 0; i < n; i++) {
 printf("\nEnter allocated resources for process P%d (A B C): ", i);
 scanf("%d %d %d", &p[i].allocation[0], &p[i].allocation[1],
&p[i].allocation[2]);
 printf("Enter maximum required resources for process P%d (A B C): ", i);
 scanf("%d %d %d", &p[i].max[0], &p[i].max[1], &p[i].max[2]);
 // Calculate need = max - allocation
 for(j = 0; j < 3; j++)
 p[i].need[j] = p[i].max[j] - p[i].allocation[j];
 p[i].finish = 0; // Initially, all processes are not finished
 }
 // Input Available resources
 printf("\nEnter the available resources (A B C): ");
 scanf("%d %d %d", &avail[0], &avail[1], &avail[2]);
 // Copy available resources to work array
 for(i = 0; i < 3; i++)
 work[i] = avail[i];
 // Banker's Algorithm main loop
 while(count < n) {
 int progress = 0; // Track if any process gets completed in this pass
 for(i = 0; i < n; i++) {
 if(p[i].finish == 0) {
 flag = 1;
 for(j = 0; j < 3; j++) {
 if(p[i].need[j] > work[j]) {
 flag = 0;
break;
 }
 }
 if(flag) {
 // Simulate process execution
 for(j = 0; j < 3; j++)
 work[j] += p[i].allocation[j];
 p[i].finish = 1;
 sequence[k++] = i;
 progress = 1;
 }
 }
 }
 if(!progress) {
 break; // No further process can proceed
 }
 count = 0;
 for(i = 0; i < n; i++) {
 if(p[i].finish == 1)
 count++;
 }
 }
 // Output the safe sequence if all processes finished
 if(count == n) {
 printf("\nSystem is in a SAFE STATE.\nSafe sequence is: ");
 for(i = 0; i < k; i++) {
 printf("P%d", sequence[i]);
 if(i < k - 1) printf(" -> ");
 }
 printf("\n");
 } else {
 printf("\nSYSTEM IS NOT IN A SAFE STATE.\n");
 }
 return 0;
}