#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int *stack;
int t = 0;

void push (int n)
{
    stack = (int*)realloc(stack, sizeof(int)*(t+1));
	*(stack+(t++)) = n;
	printf ("ok\n");
}

int pop ()
{
	if (!t)
		return 1;
	printf ("%d\n", *(stack+(--t)));
	return 0;
}

int top ()
{
	if (!t)
		return 1;
	printf ("%d\n", *(stack+t-1));
	return 0;
}

void size ()
{
    printf ("%d\n", t);
}

int main ()
{
	stack = (int*)malloc(sizeof(int));
	char cmds[5000];
	char *cmd = (char*)malloc(sizeof(char)*30);
	do
	{
		fgets(cmd, 30, stdin);	
		strcat(cmds, cmd);
	}while (strcmp(cmd, "exit\n"));
	int err_f = 0;
	cmd = strtok (cmds, " \n");
	do
	{
		if (!(strcmp(cmd, "push")))
		{
			cmd = strtok (NULL, " \n");
			for (int i = (*cmd == '-') ? 1 : 0; *(cmd+i) != '\0'; i++)
				if (!isdigit(*(cmd+i)))
					err_f = 1;
			if (!err_f)
				push(atoi(cmd));
		}
		else if (!(strcmp(cmd, "pop")))
			err_f = pop();
		else if (!(strcmp(cmd, "top")))
			err_f = top();
		else if (!(strcmp(cmd, "size")))
			size();
		else if (strcmp(cmd, "exit"))
			err_f = 1;
	}while ((cmd = strtok(NULL, " \n")) && !err_f);
	(err_f) ? printf("error") : printf("bye");
    free(stack);
	return 0;
}
