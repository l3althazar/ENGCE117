#include <stdio.h>
#include <stdlib.h>

int *GetSet(int *);

int main() {
    int *data, num;
    data = GetSet(&num);
    free(data);
    return 0;
}

int *GetSet(int *n) {
    scanf("%d", n);
    int *arr = (int*)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++) {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < *n; i++) {
        printf("%d: %d\n", i, arr[i]);
    }
    return arr;
}