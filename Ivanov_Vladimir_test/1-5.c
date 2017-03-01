#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{   
    int a,b;
    int len;
    printf("Ведите длину массива: ");
    scanf("%d",&len);
    int* s=(int*)malloc(sizeof(int)*len);
    for(int i=0;i<len;i++)
        scanf("%d", &s[i]);
    a=s[0]; b=s[0];
    for(int i=0;i<len;i++){
        if(a>s[i]) a=s[i];
        if(b<s[i]) b=s[i];}
	printf("%d", b-a);
	return 0;

}
