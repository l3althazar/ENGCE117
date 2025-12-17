#include<stdio.h>

struct student{
    char name[20];
    int age;
    char sex;
    float gpa;
};

void upgrade(struct student *c);

int main(){
    struct student a;
    a.sex='M';
    a.gpa=3.00;
    
    upgrade(&a);
    
    printf("%.2f",a.gpa);
    
    return 0;
}

void upgrade(struct student *c){
    if(c->sex=='M'){
        c->gpa=c->gpa*1.10;
    }
    if(c->sex=='F'){
        c->gpa=c->gpa*1.20;
    }
}