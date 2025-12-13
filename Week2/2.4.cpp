#include<stdio.h>

void explode(char a[],char b,char c[][10],int*d);

int main(){
    char res[20][10];
    int n;
    
    explode("I/Love/You",'/',res,&n);
    
    int i;
    for(i=0;i<n;i++){
        printf("str2[%d] = \"%s\"\n",i,res[i]);
    }
    printf("count = %d\n",n);
    
    return 0;
}

void explode(char a[],char b,char c[][10],int*d){
    int i=0;
    int j=0;
    int k=0;
    
    while(a[i]!='\0'){
        if(a[i]==b){
            c[j][k]='\0';
            j++;
            k=0;
        }
        else{
            c[j][k]=a[i];
            k++;
        }
        i++;
    }
    
    c[j][k]='\0';
    *d=j+1;
}