#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* structure for each student node */
struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *head;
    struct studentNode *current;

public:
    LinkedList();
    ~LinkedList();

    void InsNode(char studentName[], int studentAge, char studentSex, float studentGpa);
    void DelNode();
    void GoNext();
    virtual void ShowNode();
};

class NewList : public LinkedList {
public:
    void GoFirst();
    virtual void ShowNode();
};

LinkedList::LinkedList() {
    head = NULL;
    current = NULL;
}

LinkedList::~LinkedList() {
    struct studentNode *tempNode = head;

    while (tempNode != NULL) {
        struct studentNode *deleteNode = tempNode;
        tempNode = tempNode->next;
        free(deleteNode);
    }
}

void LinkedList::InsNode(char studentName[], int studentAge, char studentSex, float studentGpa) {

    struct studentNode *newNode =
        (struct studentNode*)malloc(sizeof(struct studentNode));

    strcpy(newNode->name, studentName);
    newNode->age = studentAge;
    newNode->sex = studentSex;
    newNode->gpa = studentGpa;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        current = head;
    }
    else {
        struct studentNode *lastNode = head;

        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }

        lastNode->next = newNode;
    }
}

void LinkedList::DelNode() {

    if (current == NULL)
        return;

    if (current == head) {

        struct studentNode *deleteNode = head;
        head = head->next;
        current = head;
        free(deleteNode);
    }
    else {

        struct studentNode *previousNode = head;

        while (previousNode->next != current) {
            previousNode = previousNode->next;
        }

        previousNode->next = current->next;
        free(current);
        current = previousNode->next;
    }
}

void LinkedList::GoNext() {

    if (current != NULL && current->next != NULL) {
        current = current->next;
    }
}

void LinkedList::ShowNode() {

    if (current != NULL) {

        printf("%s %d %c %.2f\n",
               current->name,
               current->age,
               current->sex,
               current->gpa);
    }
}

void NewList::GoFirst() {
    current = head;
}

/* override function */
void NewList::ShowNode() {

    if (head == NULL)
        return;

    struct studentNode *firstNode = head;
    struct studentNode *lastNode  = head;

    while (lastNode->next != NULL) {
        lastNode = lastNode->next;
    }

    printf("%s %s\n", lastNode->name, firstNode->name);
}

int main() {

    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    char one[]   = "one";
    char two[]   = "two";
    char three[] = "three";
    char four[]  = "four";
    char five[]  = "five";
    char six[]   = "six";

    listA.InsNode(one,   1, 'A', 1.1);
    listA.InsNode(two,   2, 'B', 2.2);
    listA.InsNode(three, 3, 'C', 3.3);

    listA.GoNext();
    listA.ShowNode();

    listB.InsNode(four, 4, 'D', 4.4);
    listB.InsNode(five, 5, 'E', 5.5);
    listB.InsNode(six,  6, 'F', 6.6);

    listB.GoNext();
    listB.DelNode();
    listB.ShowNode();

    listC = &listA;
    listC->GoNext();
    listC->ShowNode();

    listC = &listB;
    listC->ShowNode();

    return 0;
}