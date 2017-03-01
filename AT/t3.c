#include<stdio.h>

int main() 
{
        char s;
        int res=0;
	char a[256];
	printf("Vvedite stroku\n");
	fgets(a,256,stdin);
	printf("Vvedite simvol\n");
	s=getchar();
	int i=0;
	while (a[i]!='\0'){
		if (a[i]==s){
			res++;
		}
		i++;
	}
	printf("%d",res);
return 0;
}
