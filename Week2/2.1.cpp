#include <stdio.h>

void reverse(char str1[], char str2[]);

int main() {
    char text[50];
    char out[50];
    
    fgets(text, 50, stdin);
    
    int p = 0;
    while (text[p] != '\0') {
        if (text[p] == '\n') {
            text[p] = '\0';
            break;
        }
        p++;
    }
    
    reverse(text, out);
    printf("%s", out);
    
    return 0;
}

void reverse(char str1[], char str2[]) {
    int len = 0;
    while (str1[len] != '\0') {
        len++;
    }
    
    int a = 0;
    int b = len - 1;
    while (b >= 0) {
        str2[a] = str1[b];
        a++;
        b--;
    }
    str2[a] = '\0';
}