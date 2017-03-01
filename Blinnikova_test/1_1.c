#include <stdio.h>
#include <stdlib.h>
int main(){
        float res=1.0;
        int a,n;
        printf("enter the number: ");
        scanf("%d", &a);
        printf("enter the power: ");
        scanf("%d", &n);
        res=a;
        if (n>0){
                for(int i=1;i<n;i++)
                 {
                        res=res*a;
                }
                printf("\n%.3f", res);
                return 0;

                }
        else if (n=0)
                {
                printf("res=1");
                }
        else if (n<0)
                {
                        for (int i=1;i<abs(n);i++)
                        {
                                res=res*a;
                        }
                        res=1.0/res;
                        printf("%f", res);
                }
return 0;
}

