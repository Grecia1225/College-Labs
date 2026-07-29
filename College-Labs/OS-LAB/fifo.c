#include<stdio.h>
int main() {
int frames, pages, i, j, k, page_faults = 0;
printf("Enter number of frames: ");
scanf("%d", &frames);
printf("Enter number of pages: ");
scanf("%d", &pages);
int frame[frames], page[pages];
// Initialize frames to -1 (means empty)
for(i = 0; i < frames; i++) {
frame[i] = -1;
}
printf("Enter the page reference string: ");
for(i = 0; i < pages; i++) {
scanf("%d", &page[i]);
}
int index = 0; // To replace frames in FIFO order
for(i = 0; i < pages; i++) {
int found = 0; // Flag to check if page hit
// Check if page is already in any frame
for(j = 0; j < frames; j++) {
if(frame[j] == page[i]) {
found = 1; // Page hit
break;
}
}
if(found == 0) { // Page fault occurs
frame[index] = page[i]; // Replace frame at 'index'
index = (index + 1) % frames; // Move to next frame (circular)
page_faults++;
}
// Print current frame contents
printf("Frames after page %d: ", page[i]);
for(k = 0; k < frames; k++) {
if(frame[k] != -1)
printf("%d ", frame[k]);
else
printf("- ");
}
printf("\n");
}
printf("\nTotal Page Faults = %d\n", page_faults);
return 0;
}