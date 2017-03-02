#include "stdio.h" 

void fun(char* a, int strlen)
{	int i, k;
        int p = 0;
        if (a[i] == ' ' || a[i] == '\t')  //Если нулевой элемент строки равен пробелу или табуляции, то считываем строку с первого элемента, иначе с нулевого элемента.
        p = 1;
        else
        p = 0;
        for (i = p; i < strlen;i++)
                printf("%c", a[i]);
}
int main(){
	char c;
	char* str=NULL;
	int m = 0, n = 0, strlen = 0;
	while ((c = getchar()) != '!')
	{
		switch (c)
		{
		case '.': 
			fun(str, strlen); 
			printf("%c\n", c); 
			strlen = 0; 
			m++; 
			n++; 
			break;
		case ';':  
			fun(str, strlen); 
			printf("%c\n", c); 
			strlen = 0; 
			m++; 
			n++; 
			break;
		case '?':  
			strlen = 0; 
			m++;    
			break;
		case '\n': 
			strlen = 0;    	    
			break;
		case '\t': 
			strlen = 0;    	    
			break;
		default:
		{       strlen++;
			str = (char*)realloc(str, strlen * sizeof(char));
			str[strlen - 1] = c; 
		}
		}
	}
	printf("Количество предложений до %d и количество предложений после %d", m, n);
	return 0;
}    
