#include <stdlib.h>
#include <stdio.h>

int main(){
    int a,b,c=1;
    printf("Введите число и степень\n");
    scanf("%d %d", &a, &b);
    while(b>0){
        c=c*a;
        b--;
    }
    printf("%d", c);
    return 0;
}
