#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **start, char n[], int a, char s, float g);
void InsNode(struct studentNode *now, char n[], int a, char s, float g);
void DelNode(struct studentNode *now);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 'M', 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 'F', 3.22); ShowAll(start);
    InsNode(now, "three", 10, 'M', 3.33); ShowAll(start);
    InsNode(now, "four", 12, 'F', 3.44); ShowAll(start);
    DelNode(now); ShowAll(start);
    return 0;
}

void ShowAll(struct studentNode *walk) {
    while(walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start, char n[], int a, char s, float g) {
    struct studentNode *newNode;
    struct studentNode *lastNode;
    
    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = NULL;
    
    if(*start == NULL) {
        *start = newNode;
    } else {
        lastNode = *start;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
    
    return newNode;
}

void InsNode(struct studentNode *now, char n[], int a, char s, float g) {
    struct studentNode *newNode;
    
    if(now == NULL) return;
    
    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->sex = s;
    newNode->gpa = g;
    newNode->next = now->next;
    now->next = newNode;
}

void DelNode(struct studentNode *now) {
    struct studentNode *temp;
    
    if(now == NULL) return;
    if(now->next == NULL) return;
    
    temp = now->next;
    now->next = now->next->next;
    free(temp);
}