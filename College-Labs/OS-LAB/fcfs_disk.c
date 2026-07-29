#include <stdio.h>
#include <stdlib.h>
int main() {
int n, i, head, total = 0;
printf("Enter number of disk requests: ");
scanf("%d", &n);
int request[n];
printf("Enter the disk requests sequence: ");
for(i = 0; i < n; i++) {
scanf("%d", &request[i]);
}
printf("Enter initial head position: ");
scanf("%d", &head);
printf("\nOrder of head movement: %d", head);
for(i = 0; i < n; i++) {
total += abs(request[i] - head); // Calculate movement
head = request[i];
printf(" -> %d", head);
}
printf("\n\nTotal Head Movement: %d\n", total);
return 0;
}