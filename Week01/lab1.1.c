#include <stdio.h>

int handle_input(int *value);
void print_messages(int count);

int main() 
{
    int count = 0;
    
    if (!handle_input(&count)) {
        return 1;
    }
    
    print_messages(count);
    
    return 0;
}

int handle_input(int *value)
{
    printf("Enter number: ");
    return scanf("%d", value) == 1;
}

void print_messages(int count)
{
    for (int i = 0; i < count; i++) {
        printf("[%d] Hello world\n", i + 1);
    }
}