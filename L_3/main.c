#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char* DeleitePlz(char* arr);

int OddSent(char* arr);

int main(){
   char* a;
   char* c;
   a=(char*)malloc(1*sizeof(char)); 
   c=(char*)malloc(1*sizeof(char));
   char b;
    int i=0, j=0, n=0, m=0;
    while((b=getchar())!='!'){
        a=(char*)realloc(a, (i+3)*sizeof(char));
        a[i++]=b;
      }
    a[i++]='!';
    a[i]='\0';
    i=0;
    while(i<strlen(a)){  
        while((a[i]!='.') && (a[i]!='?') && (a[i]!=';') && (a[i]!='!')){
            c=(char*)realloc(c, (i+3)*sizeof(char));
            c[j++]=a[i];
            i++;
        }
        c[j++]=a[i];
        c[j]='\0';
        j=0;
        if(OddSent(c)==0){
            printf("%s\n", DeleitePlz(c));
            m++;
        }
        n++;
        i++;   
      }
    printf("Количество предложений до %d и количество предложений после %d\n", n-1, m);
    return 0;
}

char* DeleitePlz(char* arr){
    int i;
    while((arr[0]=='\t') || (arr[0]==' ') || (arr[0]=='\n')){
        for(i=0;i<(strlen(arr)-1);i++){
            arr[i]=arr[i+1];
        }
        arr[strlen(arr)-1]='\0';
    }
    return arr;
}
  
int OddSent(char* arr){
    int i, j=0;
    for(i=0;i<strlen(arr);i++){
        if((arr[i]=='?') || (arr[i]=='!')){
            j=1;
        }
    }
    return j;
}
