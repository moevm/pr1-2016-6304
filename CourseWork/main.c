#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define PATH_SOURSE "files/sourse.txt"
#define PATH_AMOUNT "files/amount.txt"
#define PATH_RESULT "files/result.txt"
void print(char *buffer, FILE *file_result, int len, char c){

	for (int i = 0; i < len; i++){
					fprintf(file_result, "%c", buffer[i]);
			}
	fprintf(file_result,"%c", c);

}

int main()
{
	FILE *file_for_reading, *file_result, *file_amount;
	file_for_reading=fopen(PATH_SOURSE,"r");
	file_result=fopen(PATH_RESULT,"w");
	file_amount=fopen(PATH_AMOUNT,"w");
	if (file_for_reading==NULL) printf("Ошибка");
	char c;
	int i=0;
	char buffer[80];
	int amount=0;
	int con, vow;
	con=vow=0;
	int len=0;
	while (!feof(file_for_reading)){
        c=fgetc(file_for_reading);
		switch (c){
			case ' ':
			if (con>=vow){
			print(buffer, file_result, len,c);	
			}	
			i=0;
			amount++;
			con=vow=0;
			break;
			case '!':
			if (con>=vow){
			print(buffer, file_result, len,c);	
			}
			i=0;
			con=vow=0;
			break;
			case '?':
			if (con>=vow){
			print(buffer, file_result, len,c);	
			}
			i=0;
			con=vow=0;
			break;
			case '.':
			if (con>=vow){
			print(buffer, file_result, len,c);	
			}
			i=0;
			con=vow=0;
			break;
			case '\n':
			fprintf(file_result,"%c", c);
			i=0;
			con=vow=0;
			break; 	
			default:
				if ((c>='A'&& c<='Z') || (c>='a'&& c<='z')){
				if(c == 'e'|| c=='u' || c == 'i' || c == 'o' || c=='a' || c=='y' || c=='E' || c=='U'|| c=='I' || c=='Y'||  c=='O' || c=='A' ) {
				vow++;
			}
				
				else {
					con++;
				}
				}
			 
			i++;
			buffer[i-1]=c;
			len = i;
			break;
	}
}
	fprintf(file_amount,"%i", amount+1); //учитывая последнее слово
	fclose(file_for_reading);
	fclose(file_result);
	fclose(file_amount);
	return 0;
}
