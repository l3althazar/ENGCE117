#include <stdio.h>
#include <stdlib.h>

char* reverse(char str1[]);

int main() {
    char text[50];
    char *out;
    
    fgets(text, 50, stdin);
    
    int i = 0;
    while (text[i] != '\0') {
        if (text[i] == '\n') {
            text[i] = '\0';
            break;
        }
        i++;
    }
    
    out = reverse(text);
    printf("%s", out);
    
    free(out);
    return 0;
}

char* reverse(char str1[]) {
    int m = 0;
    while (str1[m] != '\0') {
        m++;
    }
    
    char *str2 = (char*)malloc(m + 1);
    
    int x = 0;
    int y = m - 1;
    while (y >= 0) {
        str2[x] = str1[y];
        x++;
        y--;
    }
    str2[x] = '\0';
    
    return str2;
}