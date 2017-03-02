#include <stdio.h>
#include <stdlib.h>

int main() {
    int a,b;
    int d=1;
    int c=0;
    printf("Vvedite chislo 'a', zatem ego stepen 'b'");
    scanf("%d %d", &a, &b);
    while(c<b) {
        d=d*a;
        c++;
    }
    printf("a^b=%d\n", d);
    return 0;
}
