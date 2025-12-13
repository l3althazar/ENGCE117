#include <stdio.h>
#include <stdlib.h>

int GetSet(int **);

int main() {
    int *data, num;
    num = GetSet(&data);
    
    for (int i = 0; i < num; i++) {
        printf("[%d]: %d\n", i, data[i]);
    }
    
    free(data);
    return 0;
}

int GetSet(int **arr) {
    int n;
    scanf("%d", &n);
    
    *arr = (int*)malloc(n * sizeof(int));
    
    for (int i = 0; i < n; i++) {
        scanf("%d", *arr + i);
    }
    
    return n;
}