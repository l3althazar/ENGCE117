#include <stdio.h>

void explode(char str1[], char splitter, char str2[][10], int *count);

int main() {
    char out[20][10];
    int num;
    explode("I/Love/You", '/', out, &num);
    
    for (int i = 0; i < num; i++) {
        printf("str2[%d] = \"%s\"\n", i, out[i]);
    }
    printf("count = %d\n", num);
    
    return 0;
}

void explode(char str1[], char splitter, char str2[][10], int *count) {
    int i = 0;
    int k = 0;
    int l = 0;
    
    while (str1[i] != '\0') {
        if (str1[i] == splitter) {
            str2[k][l] = '\0';
            k++;
            l = 0;
        } else {
            str2[k][l] = str1[i];
            l++;
        }
        i++;
    }
    
    str2[k][l] = '\0';
    *count = k + 1;
}