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
    struct studentNode *start;
    struct studentNode **now;

public:
    LinkedList();
    ~LinkedList();

    void InsNode(char studentName[], int studentAge, char studentSex, float studentGpa);
    void DelNode();
    void GoNext();
    void GoFirst();
    void GoLast();
    void ShowAll();
    int  FindNode(char studentName[]);
    struct studentNode *NowNode();
    void EditNode(char studentName[], int studentAge, char studentSex, float studentGpa);
};

void EditData(LinkedList *list);
void AddData(LinkedList *list);
void FindData(LinkedList *list);
void readfile(LinkedList *list);
void writefile(LinkedList *list);

int main() {

    LinkedList listA;
    int menu;

    readfile(&listA);

    printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
    scanf("%d", &menu);

    while (menu != 0) {

        switch (menu) {

            case 1:
                AddData(&listA);
                break;

            case 2:
                EditData(&listA);
                break;

            case 3:
                listA.DelNode();
                break;

            case 4:
                FindData(&listA);
                break;

            case 5:
                listA.ShowAll();
                break;
        }

        printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
        scanf("%d", &menu);
    }

    writefile(&listA);

    return 0;
}

LinkedList::LinkedList() {

    start = NULL;
    now   = &start;
}

LinkedList::~LinkedList() {

    struct studentNode *currentNode = start;

    while (currentNode != NULL) {

        struct studentNode *deleteNode = currentNode;
        currentNode = currentNode->next;
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

    struct studentNode **cursor = &start;

    while (*cursor != NULL) {
        cursor = &((*cursor)->next);
    }

    *cursor = newNode;
    now = cursor;
}

void LinkedList::DelNode() {

    if (*now == NULL) {
        return;
    }

    struct studentNode *deleteNode = *now;
    *now = deleteNode->next;
    free(deleteNode);
}

void LinkedList::GoNext() {

    if (*now != NULL) {
        now = &((*now)->next);
    }
}

void LinkedList::GoFirst() {

    now = &start;
}

void LinkedList::GoLast() {

    struct studentNode **cursor = &start;

    while (*cursor != NULL && (*cursor)->next != NULL) {
        cursor = &((*cursor)->next);
    }

    now = cursor;
}

void LinkedList::ShowAll() {

    struct studentNode *cursor = start;

    while (cursor != NULL) {

        printf("%s %d %c %.2f\n",
               cursor->name,
               cursor->age,
               cursor->sex,
               cursor->gpa);

        cursor = cursor->next;
    }
}

int LinkedList::FindNode(char studentName[]) {

    now = &start;

    while (*now != NULL) {

        if (strcmp((*now)->name, studentName) == 0) {
            return 1;
        }

        now = &((*now)->next);
    }

    return 0;
}

struct studentNode *LinkedList::NowNode() {

    return *now;
}

void LinkedList::EditNode(char studentName[], int studentAge, char studentSex, float studentGpa) {

    if (*now == NULL) {
        return;
    }

    strcpy((*now)->name, studentName);
    (*now)->age = studentAge;
    (*now)->sex = studentSex;
    (*now)->gpa = studentGpa;
}

void AddData(LinkedList *list) {

    char studentName[20];
    int studentAge;
    char studentSex;
    float studentGpa;

    printf("Name : ");
    scanf("%s", studentName);

    printf("Age : ");
    scanf("%d", &studentAge);

    printf("Sex : ");
    scanf(" %c", &studentSex);

    printf("GPA : ");
    scanf("%f", &studentGpa);

    list->InsNode(studentName, studentAge, studentSex, studentGpa);
}

void EditData(LinkedList *list) {

    char searchName[20];
    char newName[20];
    int newAge;
    char newSex;
    float newGpa;

    printf("Search name : ");
    scanf("%s", searchName);

    if (list->FindNode(searchName)) {

        printf("New name : ");
        scanf("%s", newName);

        printf("Age : ");
        scanf("%d", &newAge);

        printf("Sex : ");
        scanf(" %c", &newSex);

        printf("GPA : ");
        scanf("%f", &newGpa);

        list->EditNode(newName, newAge, newSex, newGpa);
    }
    else {
        printf("Not found\n");
    }
}

void FindData(LinkedList *list) {

    char searchName[20];

    printf("Search name : ");
    scanf("%s", searchName);

    if (list->FindNode(searchName)) {

        struct studentNode *foundNode = list->NowNode();

        printf("%s %d %c %.2f\n",
               foundNode->name,
               foundNode->age,
               foundNode->sex,
               foundNode->gpa);
    }
    else {
        printf("Not found\n");
    }
}

void readfile(LinkedList *list) {

    FILE *filePointer = fopen("student.txt", "r");

    if (filePointer == NULL) {
        return;
    }

    char studentName[20];
    int studentAge;
    char studentSex;
    float studentGpa;

    while (fscanf(filePointer, "%s %d %c %f",
                  studentName, &studentAge, &studentSex, &studentGpa) == 4) {

        list->InsNode(studentName, studentAge, studentSex, studentGpa);
    }

    fclose(filePointer);
}

void writefile(LinkedList *list) {

    FILE *filePointer = fopen("student.txt", "w");

    if (filePointer == NULL) {
        return;
    }

    list->GoFirst();

    struct studentNode *cursor = list->NowNode();

    while (cursor != NULL) {

        fprintf(filePointer, "%s %d %c %.2f\n",
                cursor->name,
                cursor->age,
                cursor->sex,
                cursor->gpa);

        list->GoNext();
        cursor = list->NowNode();
    }

    fclose(filePointer);
}