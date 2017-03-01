// не хватало времени, поэтому некоторые действия не успел, но просто показал, что в состоянии :))

#include <stdio.h>
#include <stdlib.h>

int main(){
	
	int length;
	int amount;
	int number;
	int max;

	scanf("%d", &length);

	int array[100];

	for (int i=0; i<length; i++)
		scanf("%d", &array[i]);

	number=array[0];

	for (int i=1; i<length; i++){
	if (number == array[i])
		amount++;

	else
	{
		if (max < amount )
			max=amount;

			amount=0;
			number=array[i];
	}

	}
	printf("%d", max);
	system("pause");
}
	
