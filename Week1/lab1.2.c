#include <stdio.h>
#include <stdlib.h>

void GetSet(int **, int *);

int main() {
    int *data, num;
    GetSet(&data, &num);
    free(data);
    return 0;
}

void GetSet(int **set, int *n) {
    scanf("%d", n);
    *set = (int*)malloc(*n * sizeof(int));
    for (int i = 0; i < *n; i++) {
        scanf("%d", &(*set)[i]);
    }
    printf("%d\n", *n);
    for (int i = 0; i < *n; i++) {
        printf("%d\n", i, (*set)[i]);
    }
}