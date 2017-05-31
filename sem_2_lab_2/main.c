#include <stdio.h>			// 
#include <stdlib.h>			// подключение стандартных библиотек
#include <string.h>			//

void push(int* stack, int* old, int j, int k)       //функция запушивания в стек
{
    stack[j]=old[k];
}

void pushnull(int* stack, int j)                    //функция запушивания нуля в стек
{
    stack[j]=0;
}

void pushplus(int* stack, int* old, int j, int k)   //функция запушивания результата сложения двух элементов в стек
{
    stack[j]+=old[k];
}

void pushminus(int* stack, int* old, int j, int k)  //функция запушивания результата вычитания двух элементов в стек
{
    stack[j]-=old[k];
}

void pushumn(int* stack, int* old, int j, int k)    //функция запушивания результата умножения двух элементов в стек
{
    stack[j]*=old[k];
}

void pushdel(int* stack, int* old, int j, int k)    //функция запушивания результата деления двух элементов в стек
{
    stack[j]/=old[k];
}

int pop(int* stack, int j)              //функция вызова элемента из стека
{
    return stack[j];
}

int size(int* stack, int i)             //функция вызова размера стека
{
    int j=0;
    int k=0;
    for(j=0;j<i;j++){
        if(stack[j]!=0)
            k++;
    }
    return k;
}

int main() {
    int i=0;			//
    int j=0;			// счетчики
    int k=0;			//
    int m=0;			// триггер
    char plus[2]="+";			//
    char minus[2]="-";			// массивы с символами операций
    char umn[2]="*";			// (для использования в strcmp)
    char del[2]="/";			//
    char origin[100];		// массив для исходной последовательности
    char nums[100][100];		// массив для токенов из origin
    int inums[100];		// массив для токенов, преобразованных в int
    int stack[100];		// стековый массив
    fgets(origin, 100, stdin);	// счет с потока ввода
    char* token=strtok(origin, " ");	//
    while(token!=NULL)				//
    {							//
        int numb=strlen(token);		// деление массива origin 
        strncpy(nums[i], token, numb);	// на токены
        token=strtok(NULL, " ");		//
        i++;					//
    }							//
    for(j=0;j<=i;j++){				// цикл перевода цифр из 
        inums[j]=atoi(nums[j]);		// типа char в int
    }					// (символы операций переводятся как 0)
    for(j=0;j<=i;j++){			//
        if(pop(inums, k)!=0){   //выявление символов операций
            push(stack, inums, j, k);	// (если число, то записывается в стек,
            k++;				// иначе – символ операции)
        }					//
        else{
            if(strcmp(nums[k], plus)==0){	// (*) обращаемся к токену ===
                if(j>=2){					// проверка элементов
                pushplus(stack, stack, j-2, j-1);       // производим сложение элементов
                pushnull(stack, j-1);					// обнуление ненужного
                j-=2;						// откат счетчика
                k++;						// 
                }							//
                else{					// иначе
                    m=1;				// переключение триггера
                    j=i;				// завершение цикла
                }						// 
            }						// (*) ======================
            else if(strcmp(nums[k], minus)==0){	// ===================
                if(j>=2){					// идентично (*)
                pushminus(stack, stack, j-2, j-1);
                pushnull(stack, j-1);				//
                j-=2;						//
                k++;						//
                }							//
                else{						//
                    m=1;					//
                    j=i;					//
                }							//
            }							// =======================
            else if(strcmp(nums[k], umn)==0){		// =======================
                if(j>=2){					// идентично (*)
                pushumn(stack, stack, j-2, j-1);
                pushnull(stack, j-1);				//
                j-=2;						//
                k++;						//
                }							//
                else{						//
                    m=1;					//
                    j=i;					//
            }							// =====================
            else if(strcmp(nums[k], del)==0){		// =====================
                if(pop(stack, j-1)!=0){
                if(j>=2){
                pushdel(stack, stack, j-2, j-1);
                pushnull(stack, j-1);
                j-=2;						//
                k++;						//
                }							//
                else{						//
                    m=1;					//
                    j=i;					//
                }							//
            }							// =====================
                }
    }									//
    if(size(stack, i)!=1)               //проверка размера стека
             m=1;							//
    if(m==0){						//
        printf("\n%d", stack[0]);			// вывод результата
    }								//
    else{							//
        printf("error");				//
    }								//
  return 0;						// завершение работы программы
}							
