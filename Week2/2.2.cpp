#include <stdio.h>
#include <stdlib.h>

char* reverse(char str1[]);

int main() {
    char text[50];
    char *out;
    
    fgets(text, 50, stdin);
    
    int i = 0;
    while (text[i] != '\n' && text[i] != '\0') {
        i++;
    }
    text[i] = '\0';
    
    out = reverse(text);
    printf("%s", out);
    
    free(out);
    return 0;
}

char* reverse(char str1[]) {
    int len = 0;
    while (str1[len] != '\0') {
        len++;
    }
    
    char *str2 = (char*)malloc(len + 1);
    if (str2 == NULL) {
        return NULL;
    }
    
    for (int i = 0; i < len; i++) {
        str2[i] = str1[len - 1 - i];
    }
    str2[len] = '\0';
    
    return str2;
}