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
struct studentNode *AddNode(struct studentNode **start, const char name[], int age, float gpa);
void InsNode(struct studentNode *currentNode, const char name[], int age, float gpa);
void GoBack(struct studentNode **currentNode);
void DelNode(struct studentNode **currentNode);

int main() {
    struct studentNode *start = NULL;
    struct studentNode *currentNode = NULL;
    
    currentNode = AddNode(&start, "one", 6, 3.11);
    ShowAll(start);
    
    currentNode = AddNode(&start, "two", 8, 3.22);
    ShowAll(start);
    
    InsNode(currentNode, "three", 10, 3.33);
    ShowAll(start);
    
    InsNode(currentNode, "four", 12, 3.44);
    ShowAll(start);
    
    GoBack(&currentNode);
    
    DelNode(&currentNode);
    ShowAll(start);
    
    DelNode(&currentNode);
    ShowAll(start);
    
    DelNode(&currentNode);
    ShowAll(start);
    
    return 0;
}

void ShowAll(struct studentNode *walk) {
    while (walk != NULL) {
        printf("%s ", walk->name);
        walk = walk->next;
    }
    printf("\n");
}

struct studentNode *AddNode(struct studentNode **start, const char name[], int age, float gpa) {
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    struct studentNode *lastNode = *start;
    
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->gpa = gpa;
    newNode->next = NULL;
    newNode->back = NULL;
    
    if (*start == NULL) {
        *start = newNode;
        return newNode;
    }
    
    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }
    
    lastNode->next = newNode;
    newNode->back = lastNode;
    
    return newNode;
}

void InsNode(struct studentNode *currentNode, const char name[], int age, float gpa) {
    if (currentNode == NULL) {
        return;
    }
    
    struct studentNode *newNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->gpa = gpa;
    newNode->next = currentNode;
    newNode->back = currentNode->back;
    
    if (currentNode->back != NULL) {
        currentNode->back->next = newNode;
    }
    
    currentNode->back = newNode;
}

void GoBack(struct studentNode **currentNode) {
    if (*currentNode != NULL && (*currentNode)->back != NULL) {
        *currentNode = (*currentNode)->back;
    }
}

void DelNode(struct studentNode **currentNode) {
    if (*currentNode == NULL) {
        return;
    }
    
    struct studentNode *nodeToDelete = *currentNode;
    
    if (nodeToDelete->back != NULL) {
        nodeToDelete->back->next = nodeToDelete->next;
    }
    
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->back = nodeToDelete->back;
        *currentNode = nodeToDelete->next;
    } else if (nodeToDelete->back != NULL) {
        *currentNode = nodeToDelete->back;
    } else {
        *currentNode = NULL;
    }
    
    free(nodeToDelete);
}