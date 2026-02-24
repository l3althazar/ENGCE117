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

void SaveNode(struct studentNode *student, const char studentName[], int studentAge, char studentGender, float studentGPA);
void GoNext2(struct studentNode **currentNodePointer);

int main() {
    struct studentNode *headPointer;
    struct studentNode *firstNodePointer;
    struct studentNode **secondNodePointer;
    
    headPointer = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headPointer, "one", 6, 'M', 3.11);
    
    headPointer->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headPointer->next, "two", 8, 'F', 3.22);
    
    headPointer->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headPointer->next->next, "three", 10, 'M', 3.33);

    headPointer->next->next->next = (struct studentNode*)malloc(sizeof(struct studentNode));
    SaveNode(headPointer->next->next->next, "four", 12, 'F', 3.44);
    
    headPointer->next->next->next->next = NULL;

    firstNodePointer = headPointer;
    secondNodePointer = &headPointer;

    GoNext2(secondNodePointer);
    printf("Current node name after GoNext2: %s\n", (*secondNodePointer)->name);

    struct studentNode *currentFreeNode = headPointer;
    struct studentNode *nextFreeNode;
    
    while (currentFreeNode != NULL) {
        nextFreeNode = currentFreeNode->next;
        free(currentFreeNode);
        currentFreeNode = nextFreeNode;
    }
    
    return 0;
}

void SaveNode(struct studentNode *student, const char studentName[], int studentAge, char studentGender, float studentGPA) {
    strcpy(student->name, studentName);
    student->age = studentAge;
    student->sex = studentGender;
    student->gpa = studentGPA;
}

void GoNext2(struct studentNode **currentNodePointer) {
    struct studentNode *currentNode = *currentNodePointer;
    
    if (currentNode != NULL && currentNode->next != NULL) {
        *currentNodePointer = currentNode->next;
        
        struct studentNode *newCurrentNode = *currentNodePointer;
        
        printf("Successfully moved to next node.\n");
        printf("Node Information:\n");
        printf("Name: %s\n", newCurrentNode->name);
        printf("Age: %d\n", newCurrentNode->age);
        printf("Gender: %c\n", newCurrentNode->sex);
        printf("GPA: %.2f\n\n", newCurrentNode->gpa);
    }
    else {
        if (currentNode == NULL) {
            printf("Error: Current node pointer is NULL.\n");
        }
        else {
            printf("Error: No next node available. This is the last node.\n");
        }
    }
}