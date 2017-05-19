/*  
������������ ������ �2 �� ������������� ����� � �������������� �������
���������: �������� �. �.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKLEN 100 //����� ����� �����

void addBlock (int stackBlock, int* stackArray){ //������� ��������� ������ ��� ��� ������  ����� �����
	stackBlock+=1;   //����������� ���������� ������
        stackArray = (int*)realloc(stackArray, sizeof(int*)*STACKLEN*stackBlock); //������������ ������
}

int* pop(int* stackArray, int* num) //������� ���
{
        printf("%d\n", stackArray[*(num)-1]);
 	(*num)-=1;
return stackArray;
}

int* push (int* stackArray, int* num, int value) //������� push
{
    stackArray[(*num)] = value;
    (*num)++;
    printf("ok\n");
    return stackArray;
}
int size(int num) //������� size
{
printf("%d\n", num); 
return 0;
}

void bye(int* stackArray){ //������� ������ � ������������ ������
	printf("bye\n");
    free(stackArray);
}

void top(int* stackArray, int num) //������� top
{
	printf("%d\n", stackArray[num-1]);
}

void errorMessage(){ //������� ������ ������
	fprintf(stdout, "error\n");
}
int commandCheck(char* StrForCommand, int* valueToPush){ //������� �������� ������
	
	if(strcmp(StrForCommand, "pop") == 0) //���������� 2, ���� ������� ���
            return 2;
	if(strcmp(StrForCommand, "top") == 0) //���������� � ���������
            return 3;
	if(strcmp(StrForCommand, "size") == 0)
            return 4;
	if(strcmp(StrForCommand, "exit") == 0)
            return 5;
        else if (strstr(StrForCommand, "push ") && strlen(StrForCommand) >= 6) //���� ������� push 
	{
		StrForCommand = StrForCommand + 5*sizeof(char); // ������� push � �������� �� ��������
		*valueToPush = atoi(StrForCommand); //�������������� char � int
		return 1;
    }
    return 0;
}

int main() {
  int stackBlock = 1; //���������� ������, ���������� ����� 1
  int valueToPush = 0; //�������, ������� ����� ������������ �� ����
  int num = 0; //����� �������
  int* stackArray = (int*)malloc(STACKLEN*sizeof(int)); //�������� ������ ��� ������ �����
  char* StrForCommand = (char*)malloc(100*sizeof(char)); //�������� ������ �� ������ ������
    while(1) { //����������� ����, ���� �� "exit"
        if (num == STACKLEN*stackBlock){ //���� ���������� ��������� ��� ����� ������� �����
        addBlock(stackBlock, stackArray); //��������� ��� ����
        } 
      
        fgets(StrForCommand, 30, stdin); //������ �������
        if(strchr(StrForCommand, '\n')) { //������� ������� ������ 
        *strchr(StrForCommand, '\n') = '\0';
        }
        
        switch (commandCheck(StrForCommand, &valueToPush)) { //������� ������� � ���������� ��������
            case 1: //���� 1, �� ��������� �������
            stackArray = push(stackArray, &num, valueToPush);
				break;
            case 2: //���� 2, �� ������� ��������� ������� � ������� ���
            if (num!=0){
                stackArray=pop(stackArray, &num);
            }
            else { 
                errorMessage();
                return 0; 
            } break;
            case 3: //���� 3, �� ������� ��������� �������
            if (num!=0)
               top(stackArray, num);
            else { 
                errorMessage();
                return 0; 
            } break;
            case 4: //���� 4, ������� ����� �������
            size(num);
            break;
            case 5: //���� 5, �� ��������� � ������� ������
            bye(stackArray);
            return 0;
            break;
            case 0: //� ����� ������ ������ - ������� ������
            errorMessage();
                return 0; 
            break;
    }
    }
  return 0;
}