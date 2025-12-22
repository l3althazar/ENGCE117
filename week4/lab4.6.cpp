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

void SaveNode(struct studentNode *studentNode, const char studentName[], int studentAge, char studentGender, float studentGPA);
void GoNext2(struct studentNode ***triplePointer);

int main() {
    struct studentNode *headNode;
    struct studentNode *firstPointer;
    struct studentNode **secondPointer;
    
    headNode = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode, "one", 6, 'M', 3.11);
    
    headNode->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode->next, "two", 8, 'F', 3.22);
    
    headNode->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode->next->next, "three", 10, 'M', 3.33);

    headNode->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headNode->next->next->next, "four", 12, 'F', 3.44);
    
    headNode->next->next->next->next = NULL;

    firstPointer = headNode;
    secondPointer = &headNode;

    GoNext2(&secondPointer);
    printf("Current node name: %s\n", (*secondPointer)->name);

    struct studentNode *currentNode = headNode;
    struct studentNode *nextNode;
    
    while (currentNode != NULL) {
        nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    
    return 0;
}

void SaveNode(struct studentNode *studentNode, const char studentName[], int studentAge, char studentGender, float studentGPA) {
    strcpy(studentNode->name, studentName);
    studentNode->age = studentAge;
    studentNode->sex = studentGender;
    studentNode->gpa = studentGPA;
}

void GoNext2(struct studentNode ***triplePointer) {
    struct studentNode **doublePointer;
    struct studentNode *singlePointer;
    
    doublePointer = *triplePointer;
    
    if (doublePointer == NULL) {
        printf("Error: Double pointer is NULL.\n");
        return;
    }
    
    singlePointer = *doublePointer;
    
    if (singlePointer == NULL) {
        printf("Error: Single pointer is NULL.\n");
        return;
    }
    
    if (singlePointer->next != NULL) {
        *triplePointer = &(singlePointer->next);
        
        struct studentNode **newDoublePointer;
        struct studentNode *newSinglePointer;
        
        newDoublePointer = *triplePointer;
        newSinglePointer = *newDoublePointer;
        
        printf("Successfully moved to next node.\n");
        printf("Node Information:\n");
        printf("Name: %s\n", newSinglePointer->name);
        printf("Age: %d\n", newSinglePointer->age);
        printf("Gender: %c\n", newSinglePointer->sex);
        printf("GPA: %.2f\n\n", newSinglePointer->gpa);
    }
    else {
        printf("Error: Cannot move to next node. This is the last node.\n");
    }
}