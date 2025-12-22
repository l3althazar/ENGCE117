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

void SaveNode(struct studentNode *node, const char studentName[], int studentAge, char studentGender, float studentGPA);
void GoNext1(struct studentNode **currentNode);

int main() {
    struct studentNode *headNode, *currentNode, **pointerToCurrentNode;
    
    headNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode, "one", 6, 'M', 3.11);
    
    headNode->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode->next, "two", 8, 'F', 3.22);
    
    headNode->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode->next->next, "three", 10, 'M', 3.33);

    headNode->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode->next->next->next, "four", 12, 'F', 3.44);
    
    headNode->next->next->next->next = NULL;

    currentNode = headNode;
    pointerToCurrentNode = &headNode;

    GoNext1(&currentNode);
    printf("Current node name after GoNext1: %s\n", currentNode->name);

    struct studentNode *tempNode = headNode;
    while (tempNode != NULL) {
        struct studentNode *nodeToFree = tempNode;
        tempNode = tempNode->next;
        free(nodeToFree);
    }
    
    return 0;
}

void SaveNode(struct studentNode *node, const char studentName[], int studentAge, char studentGender, float studentGPA) {
    strcpy(node->name, studentName);
    node->age = studentAge;
    node->sex = studentGender;
    node->gpa = studentGPA;
}

void GoNext1(struct studentNode **currentNode) {
    if ((*currentNode)->next != NULL) {
        *currentNode = (*currentNode)->next;
        
        printf("Moved to next node. Node details:\n");
        printf("Name: %s\n", (*currentNode)->name);
        printf("Age: %d\n", (*currentNode)->age);
        printf("Gender: %c\n", (*currentNode)->sex);
        printf("GPA: %.2f\n\n", (*currentNode)->gpa);
    }
    else {
        printf("Cannot move to next node. Current node is the last node.\n");
    }
}