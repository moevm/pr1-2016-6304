#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Stack {
	char tag[100];
	struct Stack * next;
}Stack_t;

void push(Stack_t **head,char *tag)
{
	Stack_t *tmp = (Stack_t*)malloc(sizeof(Stack_t));
	tmp->next = *head;	
	strcpy(tmp->tag, tag);
	*head=tmp;
}

int headnull(Stack_t ** head) {
	return *head == NULL;
}

char* head(Stack_t **head){
	if (!headnull(head))
		return (*head)->tag;
	else
		return NULL;
}

void pop(Stack_t **head) {
	Stack_t *node;
	node = *head;
	*head=(*head)->next;
	free(node);
}


int main() {
	Stack_t *tags = NULL;
	char *buf, c;
	int i;
	buf = (char *)malloc(sizeof(char) * 100);
	c = getchar();
	while (c != '\n') {
			while (c != '<')
		{
			if (c == '\n')
		{
			if (head(&tags) == NULL)
		{
			printf("correct\n");
            free(buf);
			return 0;
		}
			else
		{
			printf("wrong\n");
            free(buf);
			return 0;
		}
			
		}
		c = getchar();
		}
		i = 0;
		
		c= getchar();
		while (c != '>')
		{
			buf[i] = c;
			i++;
			c = getchar();
		}
		buf[i] = '\0'; //
		if ((strcmp(buf, "br") != 0) && 
		(strcmp(buf, "hr") != 0) && 
		(buf[0] != '/'))
		{
			char sl[25];
			strcpy(sl,"/");
			char *str;
			str = strcat(sl, buf);
			push(&tags, str);   
		}
		else if (buf[0] == '/' && 
		(head(&tags) != NULL) &&
		(strcmp(head(&tags), buf)==0))
			pop(&tags);	
        else if (buf[0] == '/' && (head(&tags) == NULL))
        {
            printf("wrong\n");
            free(buf);
            return 0;
        }
		c = getchar();
	}
	if (!headnull(&tags)) {
	printf("wrong\n");
    free(buf);
    }
    else {printf("correct\n");
    free(buf);}
	return 0;

}
