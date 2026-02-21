#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

struct studentNode {
    char name[20];
    int age;
    char sex;
    float gpa;
    struct studentNode *next;
};

class LinkedList {
    protected:
        struct studentNode *start;
        struct studentNode **now;
        
    public:
        LinkedList() {
            start = NULL;
            now = &start;
        }
        
        ~LinkedList() {
            struct studentNode *current = start;
            struct studentNode *temp;
            while(current != NULL) {
                temp = current;
                current = current->next;
                delete temp;
            }
        }
        
        void InsNode(const char studentName[], int studentAge, char studentSex, float studentGpa) {
            struct studentNode *newNode = new studentNode;
            struct studentNode *walker = start;
            
            strcpy(newNode->name, studentName);
            newNode->age = studentAge;
            newNode->sex = studentSex;
            newNode->gpa = studentGpa;
            newNode->next = NULL;
            
            if(start == NULL) {
                start = newNode;
                now = &start;
                return;
            }
            
            while(walker->next != NULL) {
                walker = walker->next;
            }
            
            walker->next = newNode;
        }
        
        void DelNode() {
            if(*now == NULL || (*now)->next == NULL) {
                return;
            }
            
            struct studentNode *nodeToDelete = (*now)->next;
            (*now)->next = nodeToDelete->next;
            delete nodeToDelete;
        }
        
        void GoNext() {
            if(*now != NULL && (*now)->next != NULL) {
                now = &(*now)->next;
            }
        }
        
        virtual void ShowNode() {
            if(*now != NULL) {
                cout << (*now)->name << " " 
                     << (*now)->age << " " 
                     << (*now)->sex << " ";
                printf("%.2f\n", (*now)->gpa);
            }
        }
};

class NewList : public LinkedList {
    public:
        void GoFirst() {
            now = &start;
        }
        
        virtual void ShowNode() {
            struct studentNode *traversal = start;
            while(traversal != NULL) {
                cout << traversal->name << " ";
                traversal = traversal->next;
            }
            cout << endl;
        }
};

int main() {
    LinkedList listA;
    NewList listB;
    LinkedList *listC;

    listA.InsNode("one", 1, 'A', 1.1);
    listA.InsNode("two", 2, 'B', 2.2);
    listA.InsNode("three", 3, 'C', 3.3);
    
    listA.GoNext();
    listA.ShowNode();

    listB.InsNode("four", 4, 'D', 4.4);
    listB.InsNode("five", 5, 'E', 5.5);
    listB.InsNode("six", 6, 'F', 6.6);
    
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