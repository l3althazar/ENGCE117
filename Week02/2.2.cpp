#include<stdio.h>
#include<stdlib.h>

char* reverse(char a[]);

int main(){
    char txt[50];
    char*ans;
    
    fgets(txt,50,stdin);
    
    int p=0;
    while(txt[p]!='\n'&&txt[p]!='\0'){
        p++;
    }
    txt[p]='\0';
    
    ans=reverse(txt);
    printf("%s",ans);
    
    if(ans!=NULL){
        free(ans);
    }
    return 0;
}

char* reverse(char a[]){
    int cnt=0;
    while(a[cnt]!='\0'){
        cnt++;
    }
    
    char*b=(char*)malloc(cnt+1);
    if(b==NULL)return NULL;
    
    int i=0;
    while(i<cnt){
        b[i]=a[cnt-1-i];
        i++;
    }
    b[cnt]='\0';
    
    return b;
}