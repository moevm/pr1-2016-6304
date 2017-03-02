#include <stdio.h>
#include <stdlib.h>
	
void readtext (char**, int*);
void deltabs (char**);
void delquest (char**);
char* addlines (char*);
void writelines (char*, int);

int main ()
{
	char *text;
	int lc1;	
	readtext(&text, &lc1);
	deltabs (&text);
	delquest (&text);
	text = addlines (text);
	writelines (text, lc1); 
	return 0;
}

void readtext (char **text, int *lc)
{
	char c;
	int i;
	*lc=0;
	*text = (char*)malloc(sizeof(char));
	for (i=0; (c=getchar())!='!'; i++)
	{	
		*text = (char*)realloc(*text, (i+1)*sizeof(char));
		*(*text+i) = c;
		if (c == '.' || c ==';' || c == '?')
			(*lc)++;
	}
	*text = (char*)realloc(*text, (i+1)*sizeof(char));
	*(*text+(i++)) = '!';
	*text = (char*)realloc(*text, (i+1)*sizeof(char));
	*(*text+i) = '\0';
}

void deltabs (char** text)
{
	int i=0, j=0;
	for (i=0, j=0; *(*text+i)!='\0'; i++, j++)
	{
		if (i!=0 && *(*text+i)==' ' && (*(*text+i-1)=='.'|| *(*text+i-1)==';' || *(*text+i-1)=='?'))
			i++;
		while (*(*text+i) == '\t' || *(*text+i) == '\n')
                        i++;
                *(*text+j) = *(*text+i);
	}
	*text = (char*)realloc(*text,(j+1)*sizeof(char));
	*(*text+j) = '\0';
}


void delquest (char** text)
{
        int i=0, j=0;
        for (i=0, j=0; *(*text+i)!='\0' ; i++, j++)
	{
		if (*(*text+i)=='?' || *(*text+i)=='!')
                {
                        int k;
                        for(k=0; *(*text+j-(k+1))!=';' && *(*text+j-(k+1))!='.' && k<j; k++)
                                ;
                        j-=k;
			i++;
                }
                *(*text+j) = *(*text+i);
		if (*(*text+i) == '\0') i--;
		
	}
	*text=(char*)realloc(*text, j*sizeof(char));
}


char* addlines (char* str)
{
	char *text;
	int i=0, j=0;
	text = (char*)malloc(sizeof(char));
	for (i=0, j=0; *(str+i)!='\0'; i++, j++)
    	{
		text = (char*)realloc(text, (j+1)*sizeof(char*));
		*(text+j)=*(str+i);
		if (*(str+i) == ';' || *(str+i) == '.')
                {
                         text = (char*)realloc(text,((++j)+1)*sizeof(char*));
                         *(text+j)='\n';
		}
        }
	text = (char*)realloc(text, (j+1)*sizeof(char*));
	*(text+j) = '\0';
        return text;
}

void writelines (char* str, int ln1)
{
	int ln2=0;
	for (int i=0; *(str+i)!='\0'; i++)
		if (*(str+i) == ';' || *(str+i) == '.')
			ln2++;
	printf ("%s", str);
	printf ("Количество предложений до %d и количество предложений после %d\n", ln1, ln2);
}
