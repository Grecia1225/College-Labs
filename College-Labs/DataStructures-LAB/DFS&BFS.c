#include <stdio.h>

// Global variable declarations from your notes
int q[20], top = -1, front = -1, rear = -1, a[20][20];
int vis[20], stack[20];

// Function prototypes
int delete();
void add(int item);
void bfs(int s, int n);
void dfs(int s, int n);
void push(int item);
int pop();

void main() {
    int n, i, j, s, ch;
    char c;

    printf("Enter the number vertices: ");
    scanf("%d", &n);

    // Adjacency Matrix Input
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("Enter 1 if %d has a node with %d else 0: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Display Adjacency Matrix
    printf("the adjacent matrix is \n");
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }

    // Menu Logic
    do {
        for (i = 1; i <= n; i++)
            vis[i] = 0;

        printf("\n Menu");
        printf("\n 1. BFS");
        printf("\n 2. DFS");
        printf("\n Enter your choice: ");
        scanf("%d", &ch);

        printf("Enter your source vertex: ");
        scanf("%d", &s);

        switch (ch) {
            case 1: 
                bfs(s, n); 
                break;
            case 2: 
                dfs(s, n); 
                break;
        }

        printf("\n Do you want to continue (Y/N)? ");
        scanf(" %c", &c); // Added space before %c to clear buffer
    } while (c == 'y' || c == 'Y');
}

// --- BFS Implementation (Breadth-First Search) ---

void bfs(int s, int n) {
    int p, i;
    add(s);
    vis[s] = 1;
    p = delete();
    if (p != 0)
        printf("%d ", p);

    for (i = 1; i <= n; i++) {
        if (a[s][i] != 0 && vis[i] == 0) {
            add(i);
            vis[i] = 1;
        }
    }
    p = delete();
    while (p != 0) {
        if (vis[p] == 0) {
            printf("%d ", p);
            vis[p] = 1;
        }
        p = delete();
    }
}

void add(int item) {
    if (rear == 19)
        printf("queue full");
    else {
        if (rear == -1) {
            q[++rear] = item;
            front++;
        } else {
            q[++rear] = item;
        }
    }
}

int delete() {
    int k;
    if ((front > rear) || (front == -1))
        return (0);
    else {
        k = q[front++];
        return (k);
    }
}

// --- DFS Implementation (Depth-First Search) ---

void dfs(int s, int n) {
    int i, k;
    push(s);
    vis[s] = 1;
    k = pop();
    if (k != 0)
        printf("%d ", k);

    while (k != 0) {
        for (i = 1; i <= n; i++) {
            if ((a[k][i] != 0) && (vis[i] == 0)) {
                push(i);
                vis[i] = 1;
            }
        }
        k = pop();
        if (k != 0)
            printf("%d ", k);
    }
}

void push(int item) {
    if (top == 19)
        printf("stack overflow");
    else
        stack[++top] = item;
}

int pop() {
    int k;
    if (top == -1)
        return (0);
    else {
        k = stack[top--];
        return (k);
    }
}