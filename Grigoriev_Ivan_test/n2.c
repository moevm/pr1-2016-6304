#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char *s;
    int n;
    printf("Vvedite kol-vo simvolov stroki: ");
    scanf("%d", &n);
    s=(char*)malloc(sizeof(char)*n);
    printf("Vvedite stroku: ");
    scanf("%s", s);
    for(int i=0;i<n; i++) {
        if(i%2==1)
        printf("%c\n", s[i]);
    }
    return 0;
}
