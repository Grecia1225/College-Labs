#include <stdio.h>
#include <stdlib.h>
#define MAX 20 // Define max philosophers
int tph, philname[MAX], status[MAX], howhung, hu[MAX], cho;
void one();
void two();
int main() {
 int i;
 printf("\n\nDINING PHILOSOPHER PROBLEM");
 printf("\nEnter the total no. of philosophers: ");
 scanf("%d", &tph);
 if (tph > MAX) {
 printf("\nError: Max philosophers limit is %d\n", MAX);
 return 1;
 }
 for (i = 0; i < tph; i++) {
 philname[i] = (i + 1);
 status[i] = 1; // 1 means thinking
 }
 printf("How many are hungry: ");
 scanf("%d", &howhung);
 if (howhung > tph) {
 printf("\nError: More hungry philosophers than total available!\n");
 return 1;
 }
 if (howhung == tph) {
 printf("\nAll are hungry..\nDeadlock stage will occur");
 printf("\nExiting..\n");
 return 0;
 } else {
 for (i = 0; i < howhung; i++) {
 printf("Enter philosopher %d position (1 to %d): ", (i + 1), tph);
 scanf("%d", &hu[i]);
 if (hu[i] < 1 || hu[i] > tph) {
 printf("\nError: Invalid philosopher number!\n");
 return 1;
 }
 status[hu[i] - 1] = 2; // 2 means hungry
 }
 do {
 printf("\n1. One can eat at a time\t2. Two can eat at a time\t3.\tExit\nEnter your choice: ");
 scanf("%d", &cho);
 switch (cho) {
 case 1:
 one();
 break;
 case 2:
 two();
 break;
 case 3:
 exit(0);
 default:
 printf("\nInvalid option..");
 }
 } while (1);
 }
 return 0;
}
// Function to allow one philosopher to eat at a time
void one() {
 int pos = 0, x, i;
 printf("\nAllow one philosopher to eat at any time\n");
 for (i = 0; i < howhung; i++, pos++) {
 printf("\nP %d is granted to eat", philname[hu[pos] - 1]);
 for (x = pos + 1; x < howhung; x++) {
 printf("\nP %d is waiting", philname[hu[x] - 1]);
 }
 }
}
// Function to allow two philosophers to eat at the same time
void two() {
 int i, j, s = 0, t, r, x;
 printf("\nAllow two philosophers to eat at the same time\n");
 for (i = 0; i < howhung; i++) {
 for (j = i + 1; j < howhung; j++) {
 if (abs(hu[i] - hu[j]) >= 1 && abs(hu[i] - hu[j]) != tph - 1) {
 printf("\n\nCombination %d \n", (s + 1));
 t = hu[i];
 r = hu[j];
 s++;
 printf("\nP %d and P %d are granted to eat", philname[hu[i] - 1],
philname[hu[j] - 1]);
 for (x = 0; x < howhung; x++) {
 if ((hu[x] != t) && (hu[x] != r))
 printf("\nP %d is waiting", philname[hu[x] - 1]);
 }
 }
 }
 }
}