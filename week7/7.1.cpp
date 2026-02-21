#include <iostream>
#include <cstring>
#include <iomanip>
using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    studentNode *next;
};

class LinkedList {
protected:
    studentNode *start, *now;
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
    studentNode *p = start;
    while (p != NULL) {
        studentNode *tmp = p;
        p = p->next;
        delete tmp;
    }
}

void LinkedList::InsNode(char n[], int a, char s, float g) {
    studentNode *p = new studentNode;
    strcpy(p->name, n);
    p->age = a;
    p->sex = s;
    p->gpa = g;
    p->next = NULL;

    if (start == NULL) {
        start = p;
        now = start;
    } else {
        studentNode *q = start;
        while (q->next != NULL)
            q = q->next;
        q->next = p;
    }
}

void LinkedList::DelNode() {
    if (now == NULL) return;

    if (now == start) {
        studentNode *tmp = start;
        start = start->next;
        now = start;
        delete tmp;
    } else {
        studentNode *p = start;
        while (p->next != now)
            p = p->next;
        p->next = now->next;
        delete now;
        now = p->next;
    }
}

void LinkedList::GoNext() {
    if (now != NULL && now->next != NULL)
        now = now->next;
}

void LinkedList::ShowNode() {
    if (now != NULL) {
        cout << now->name << " "
             << now->age << " "
             << now->sex << " "
             << fixed << setprecision(2)
             << now->gpa << endl;
    }
}

void NewList::GoFirst() {
    now = start;
}

void NewList::ShowNode() {
    if (start == NULL) return;

    studentNode *first = start;
    studentNode *last = start;

    while (last->next != NULL)
        last = last->next;

    cout << last->name << " " << first->name << endl;
}

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode((char*)"one", 1, 'A', 1.1);
    listA.InsNode((char*)"two", 2, 'B', 2.2);
    listA.InsNode((char*)"three", 3, 'C', 3.3);
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode((char*)"four", 4, 'D', 4.4);
    listB.InsNode((char*)"five", 5, 'E', 5.5);
    listB.InsNode((char*)"six", 6, 'F', 6.6);
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