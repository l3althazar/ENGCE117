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
	struct studentNode *start, **now;

public:
	LinkedList();
	~LinkedList();

	void InsNode(char n[], int a, char s, float g);
	void DelNode();
	void GoNext();
	void GoFirst();
	void GoLast();
	void ShowAll();
	int FindNode(char n[]);
	struct studentNode *NowNode();
	void EditNode(char n[], int a, char s, float g);
};

void EditData(LinkedList *ll);
void AddData(LinkedList *ll);
void FindData(LinkedList *ll);
void readfile(LinkedList *ll);
void writefile(LinkedList *ll);

int main() {

	LinkedList listA;
	int menu;

	readfile(&listA);

	printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
	scanf("%d", &menu);

	while(menu != 0) {

		switch(menu) {
			case 1: AddData(&listA); break;
			case 2: EditData(&listA); break;
			case 3: listA.DelNode(); break;
			case 4: FindData(&listA); break;
			case 5: listA.ShowAll(); break;
		}

		printf("Menu - (1) Add (2) Edit (3) Delete (4) Find (5) Show (0) Exit : ");
		scanf("%d", &menu);
	}

	writefile(&listA);

	return 0;
}

LinkedList::LinkedList() {
	start = NULL;
	now = &start;
}

LinkedList::~LinkedList() {
	struct studentNode *current = start;
	while(current != NULL) {
		struct studentNode *temp = current;
		current = current->next;
		free(temp);
	}
}

void LinkedList::InsNode(char n[], int a, char s, float g) {

	struct studentNode *newNode =
		(struct studentNode*)malloc(sizeof(struct studentNode));

	strcpy(newNode->name, n);
	newNode->age = a;
	newNode->sex = s;
	newNode->gpa = g;
	newNode->next = NULL;

	struct studentNode **cursor = &start;

	while(*cursor != NULL)
		cursor = &((*cursor)->next);

	*cursor = newNode;
	now = cursor;
}

void LinkedList::DelNode() {

	if(*now == NULL)
		return;

	struct studentNode *deleteNode = *now;
	*now = deleteNode->next;
	free(deleteNode);
}

void LinkedList::GoNext() {

	if(*now != NULL)
		now = &((*now)->next);
}

void LinkedList::GoFirst() {
	now = &start;
}

void LinkedList::GoLast() {

	struct studentNode **cursor = &start;

	while(*cursor != NULL && (*cursor)->next != NULL)
		cursor = &((*cursor)->next);

	now = cursor;
}

void LinkedList::ShowAll() {

	struct studentNode *cursor = start;

	while(cursor != NULL) {
		printf("%s %d %c %.2f\n",
		       cursor->name,
		       cursor->age,
		       cursor->sex,
		       cursor->gpa);
		cursor = cursor->next;
	}
}

int LinkedList::FindNode(char n[]) {

	now = &start;

	while(*now != NULL) {

		if(strcmp((*now)->name, n) == 0)
			return 1;

		now = &((*now)->next);
	}

	return 0;
}

struct studentNode* LinkedList::NowNode() {
	return *now;
}

void LinkedList::EditNode(char n[], int a, char s, float g) {

	if(*now == NULL)
		return;

	strcpy((*now)->name, n);
	(*now)->age = a;
	(*now)->sex = s;
	(*now)->gpa = g;
}

void AddData(LinkedList *ll) {

	char name[20];
	int age;
	char sex;
	float gpa;

	printf("Name : ");
	scanf("%s", name);

	printf("Age : ");
	scanf("%d", &age);

	printf("Sex : ");
	scanf(" %c", &sex);

	printf("GPA : ");
	scanf("%f", &gpa);

	ll->InsNode(name, age, sex, gpa);
}

void EditData(LinkedList *ll) {

	char searchName[20];
	char newName[20];
	int age;
	char sex;
	float gpa;

	printf("Search name : ");
	scanf("%s", searchName);

	if(ll->FindNode(searchName)) {

		printf("New name : ");
		scanf("%s", newName);

		printf("Age : ");
		scanf("%d", &age);

		printf("Sex : ");
		scanf(" %c", &sex);

		printf("GPA : ");
		scanf("%f", &gpa);

		ll->EditNode(newName, age, sex, gpa);
	}
	else {
		printf("Not found\n");
	}
}

void FindData(LinkedList *ll) {

	char searchName[20];

	printf("Search name : ");
	scanf("%s", searchName);

	if(ll->FindNode(searchName)) {

		struct studentNode *node = ll->NowNode();

		printf("%s %d %c %.2f\n",
		       node->name,
		       node->age,
		       node->sex,
		       node->gpa);
	}
	else {
		printf("Not found\n");
	}
}

void readfile(LinkedList *ll) {

	FILE *fp = fopen("student.txt", "r");

	if(fp == NULL)
		return;

	char name[20];
	int age;
	char sex;
	float gpa;

	while(fscanf(fp, "%s %d %c %f",
	             name, &age, &sex, &gpa) == 4) {

		ll->InsNode(name, age, sex, gpa);
	}

	fclose(fp);
}

void writefile(LinkedList *ll) {

	FILE *fp = fopen("student.txt", "w");

	if(fp == NULL)
		return;

	struct studentNode *cursor = ll->NowNode();
	ll->GoFirst();
	cursor = ll->NowNode();

	while(cursor != NULL) {

		fprintf(fp, "%s %d %c %.2f\n",
		        cursor->name,
		        cursor->age,
		        cursor->sex,
		        cursor->gpa);

		ll->GoNext();
		cursor = ll->NowNode();
	}

	fclose(fp);
}