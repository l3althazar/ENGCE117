#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct studentNode {
    char name[20];
    int age;
    float gpa;
    struct studentNode *next;
    struct studentNode *back;
};

void ShowAll(struct studentNode *walk);
struct studentNode *AddNode(struct studentNode **start, const char n[], int a, float g);
void InsNode(struct studentNode *now, const char n[], int a, float g);
void GoBack(struct studentNode **now);
void DelNode(struct studentNode **now);

int main() {
    struct studentNode *start, *now;
    start = NULL;
    now = AddNode(&start, "one", 6, 3.11); ShowAll(start);
    now = AddNode(&start, "two", 8, 3.22); ShowAll(start);
    InsNode(now, "three", 10, 3.33); ShowAll(start);
    InsNode(now, "four", 12, 3.44); ShowAll(start);
    GoBack(&now);
    DelNode(&now); ShowAll(start);
    DelNode(&now); ShowAll(start);
    DelNode(&now); ShowAll(start);
    return 0;
}

void ShowAll(struct studentNode *walk) {
    while(walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start, const char n[], int a, float g) {
    struct studentNode *newNode, *lastNode;
    
    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->gpa = g;
    newNode->next = NULL;
    newNode->back = NULL;
    
    if(*start == NULL) {
        *start = newNode;
    } else {
        lastNode = *start;
        while(lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
        newNode->back = lastNode;
    }
    
    return newNode;
}

void InsNode(struct studentNode *now, const char n[], int a, float g) {
    struct studentNode *newNode;
    
    if(now == NULL) return;
    
    newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(newNode->name, n);
    newNode->age = a;
    newNode->gpa = g;
    newNode->next = now;
    newNode->back = now->back;
    
    if(now->back != NULL) {
        now->back->next = newNode;
    }
    now->back = newNode;
}

void GoBack(struct studentNode **now) {
    if(*now != NULL && (*now)->back != NULL) {
        *now = (*now)->back;
    }
}

void DelNode(struct studentNode **now) {
    struct studentNode *temp;
    
    if(*now == NULL) return;
    
    temp = *now;
    
    if(temp->back != NULL) {
        temp->back->next = temp->next;
    }
    if(temp->next != NULL) {
        temp->next->back = temp->back;
        *now = temp->next;
    } else if(temp->back != NULL) {
        *now = temp->back;
    } else {
        *now = NULL;
    }
    
    free(temp);
}