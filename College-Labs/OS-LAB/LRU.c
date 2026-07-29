#include<stdio.h>
int main() {
int frames, pages, i, j, k, page_faults = 0;
printf("Enter number of frames: ");
scanf("%d", &frames);
printf("Enter number of pages: ");
scanf("%d", &pages);
int frame[frames], page[pages], recent[frames];
// Initialize frames to -1 (means empty)
for(i = 0; i < frames; i++) {
frame[i] = -1;
recent[i] = 0; // No usage yet
}
printf("Enter the page reference string: ");
for(i = 0; i < pages; i++) {
scanf("%d", &page[i]);
}
int time = 0; // To track usage time
for(i = 0; i < pages; i++) {
int found = 0; // Flag to check if page hit
// Check if page is already present
for(j = 0; j < frames; j++) {
if(frame[j] == page[i]) {
found = 1; // Page hit
time++;
recent[j] = time; // Update recent usage
break;
}
}
if(found == 0) { // Page not found - page fault
int lru_index = 0;
int min_recent = recent[0];
// Find least recently used frame
for(j = 1; j < frames; j++) {
if(recent[j] < min_recent) {
min_recent = recent[j];
lru_index = j;
}
}
// Replace LRU page with new page
frame[lru_index] = page[i];
time++;
recent[lru_index] = time; // Update recent usage
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