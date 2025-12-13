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
    int x = 0;
    int y = 0;
    int z = 0;
    
    while (str1[x] != '\0') {
        if (str1[x] == splitter) {
            str2[y][z] = '\0';
            y++;
            z = 0;
        } else {
            str2[y][z] = str1[x];
            z++;
        }
        x++;
    }
    
    str2[y][z] = '\0';
    *count = y + 1;
}