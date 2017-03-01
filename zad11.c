#include <stdio.h>
#include <stdlib.h>


int main(){
	double res = 1.0;
	int x, a, i;
	printf("vvedite chislo:\n");
	scanf("%d", &x);
	printf("vvedite stepen:\n");
	scanf("%d", &a);	
	if(a>0){
		for(int i = 0; i<a; i++){
			res *= x;
		}
}
	else if (a<0){
		int t = abs(a);	
		for(int i = 1 ; i<t; i++){
			x *= x;
		
		}
	res = 1.0/x;
	}
	else
	res = 1;
	
	printf("%f", res);

return 0;
}
		
