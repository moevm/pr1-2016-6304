#include<stdio.h>
#include<stdlib.h>

int main(){
	int res=0;
	int x,n,i;
	double y,resf;
	printf("Vvedite chislo i stepen\n");
	scanf("%d%d", &x, &n);
	if (x==1)
		{ 
	 	  printf("%d",res=1);
		}
	 else if (n==0)
			{
			 printf("%d",res=1);
			}
	  else if (x==0) 
			 {
			  printf("%d",res=0);
	}  
	else if (n>0){
			 res=x;
			 for (i=1;i<n;i++)
				{
				 res=res*x;
				}
			 printf("%d",res);
			}
	 else if (n<0) {
	                y=1.0/(x);
			resf=y;
                        for (i=1;i<abs(n);i++)
                                {
                                 resf=resf*y;
                                }
                         printf("%f",resf);
                        } return 0;
}

				 
