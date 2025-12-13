#include <stdio.h>

void reverse(char str1[], char str2[]);

int main() {
    char text[50];
    char out[50];
    
    scanf("%[^\n]", text);
    
    reverse(text, out);
    
    printf("%s", out);
    
    return 0;
}

void reverse(char str1[], char str2[]) {
    int n = 0;
    while (str1[n] != '\0') {
        n++;
    }
    
    for (int i = 0; i < n; i++) {
        str2[i] = str1[n - 1 - i];
    }
    str2[n] = '\0';
}