#include <stdio.h>
#include <stdlib.h>

struct student {
    char name[50];
    int age;
};

struct student (*GetStudent(int *room))[10];

int main() {
    struct student (*children)[10];
    int group;
    children = GetStudent(&group);
    return 0;
}

struct student (*GetStudent(int *room))[10] {
    int i,j;
    struct student (*result)[10];
    printf("Enter number of classrooms: ");
    scanf("%d", room);
    result = (struct student (*)[10])malloc(*room * 10 * sizeof(struct student));
    for(i=0;i<*room;i++) {
        printf("Classroom %d:\n",i+1);
        for(j=0;j<10;j++) {
            printf("Enter name student %d: ",j+1);
            scanf("%s",result[i][j].name);
            printf("Enter age student %d: ",j+1);
            scanf("%d",&result[i][j].age);
        }
    }
    return result;
}