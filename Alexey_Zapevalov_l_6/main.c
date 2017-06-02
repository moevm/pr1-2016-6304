#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int push(int* array, int j, char* a)
{
    array[j]=atoi(a);
    printf("ok\n");
    return j+1;
}

void size(int j)
{
    printf("%d\n", j);
}

int printexit()
{
    printf("bye\n");
    return 1;
}

int pop(int* array, int j)
{
    printf("%d\n", array[j-1]);
    return j-1;
}

void top(int* array, int j)
{
    printf("%d\n", array[j]);
}

int main()
{
    int i=0, c=1, n, j=0, flag=0;   // c - input strings counter, n - result strings amount counter
    char del[]="\n ";               // i - strtok counter, j - result counter
    char vvod[200][20];             // del - dividing symbols array, vvod - input array
    char mas[200][20];              // mas - in-between result counter
    int array[200];                 // array - result counter
    vvod[0][0]='0';                 //checking previous result needs array to begin with 1
    while(strcmp(vvod[c-1], "exit\n")!=0)   //reading strings
    {
            fgets(vvod[c], 20, stdin);
            //printf("%s\n", vvod[c]);
            c++;
    }
    for (n=1; n<c; n++)
    {
    char *p=strtok(vvod[n], del); // Divides words from input strings
    while (p != NULL)
    {
        strcpy(mas[i], p);
        p = strtok (NULL, del);
        i++;
    }
    }
    for (n=0; n<i; n++)
    {
        if (flag==0)
        {
            if (strcmp(mas[n], "push")==0)
            {
                j=push(array, j, mas[n+1]);
                n++;
            }
            else if (strcmp(mas[n], "size")==0)
            {
                size(j);
            }
            else if (strcmp(mas[n], "exit")==0)
            {
                flag=printexit();
            }
            else if (j!=0)
            {
                if (strcmp(mas[n], "pop")==0)
                {
                    j=pop(array, j);
                }
                else if (strcmp(mas[n], "top")==0)
                {
                    top(array, j-1);
                }
            }
            else
            {
                printf("error\n");
                flag=1;
            }
        }
    }
    return 0;
}
