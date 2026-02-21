#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
protected:
    struct studentNode *start, *now;
public:
    LinkedList();
    ~LinkedList();
    void InsNode(char n[], int a, char s, float g);
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
    start = NULL;
    now = NULL;
}

LinkedList::~LinkedList() {
    struct studentNode *p = start;
    while (p != NULL) {
        struct studentNode *tmp = p;
        p = p->next;
        free(tmp);
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    struct studentNode *p = (struct studentNode*)malloc(sizeof(struct studentNode));
    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;
    p->next = NULL;

    if (start == NULL) {
        start = p;
        now = start;
    } else {
        struct studentNode *q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

void LinkedList::DelNode() {
    if (now == NULL) return;

    if (now == start) {
        struct studentNode *tmp = start;
        start = start->next;
        now = start;
        free(tmp);
    } else {
        struct studentNode *p = start;
        while (p->next != now)
            p = p->next;
        p->next = now->next;
        free(now);
        now = p->next;
    }
}

void LinkedList::GoNext() {
    if (now != NULL && now->next != NULL)
        now = now->next;
}

void LinkedList::ShowNode() {
    if (now != NULL) {
        printf("%s %d %c %.2f\n",
               now->name,
               now->age,
               now->sex,
               now->gpa);
    }
}

void NewList::GoFirst() {
    now = start;
}

void NewList::ShowNode() {
    if (start == NULL) return;

    struct studentNode *first = start;
    struct studentNode *last = start;

    while (last->next != NULL)
        last = last->next;

    printf("%s %s\n", last->name, first->name);
}

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    char n1[] = "one";
    char n2[] = "two";
    char n3[] = "three";
    char n4[] = "four";
    char n5[] = "five";
    char n6[] = "six";

    listA.InsNode(n1, 1, 'A', 1.1);
    listA.InsNode(n2, 2, 'B', 2.2);
    listA.InsNode(n3, 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode(n4, 4, 'D', 4.4);
    listB.InsNode(n5, 5, 'E', 5.5);
    listB.InsNode(n6, 6, 'F', 6.6);
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