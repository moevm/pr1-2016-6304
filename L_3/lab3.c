#include <stdio.h>
void print(char* arr, int len);
int main(){
    char* arr2;
    char ch; 
    char* arr=NULL;
    int m = 0, n = 0, len = 0, i = 0;
    while ((ch = getchar()) != '!')
    {
        switch (ch)
        {
        case '.':  print(arr, len); printf("%c\n", ch); i = 0; m++; n++; break;
        case ';':  print(arr, len); printf("%c\n", ch); i = 0; m++; n++; break;
        case '?':  i = 0; n++;  break;
        case '\n': i = 0;   break;
        case '\t': i = 0;   break;
        default:
        {
            len = ++i;
            arr2= (char*)realloc(arr, i * sizeof(char));
            if (arr2!=arr) free(arr);
            arr=arr2;
            
            arr[i - 1] = ch; 
        }
        }
    }
    printf("Количество предложений до %d и количество предложений после %d", n, m);
    return 0;
    free(arr);
}
void print(char* arr, int len)
{   for (int i = (arr[0] == ' ') ? 1 : 0; i < len; i++)

        printf("%c", arr[i]);
}
