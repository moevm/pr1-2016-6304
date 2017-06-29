#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_STACK 100 //Определяем максимальный размер массива 
typedef int N; //Тип данных, которые будут храниться в данном массиве

typedef struct index
{
  N a[MAX_STACK]; // Размер типа для того, чтобы в него можно было записать максимальный размер теоретически возможного массива любого типа
  N size; // количество элементов, и вместе с тем указатель на вершину стека
   
  // Вершина будет указывать на следующий элемент массива, в который будет занесено значение.
  
} index;

void push(index *stack, const N value)
{
  stack->a[stack->size] = value; //указатель на структуру
  stack->size++;
}


int pop(index *stack)
{
  stack->size--;
  return stack->a[stack->size];
}

int sizeStack(index  *stack)
  {
  return  stack->size;
  }

int top(const index *stack)
{

    return stack->a[stack->size - 1];
}

int funct(index *stack, char c)
{
  if (stack->size == 0 || stack->size == 1  )
  {
    return 1;
  }
 int a, b;


if(sizeStack(stack) != 0)
{
 a=top(stack);
 pop(stack);

 b=top(stack);
 pop(stack);
}
 int result;
 switch(c)
 {
 	case '+': { 
 		result = b+a; 
 		break;
 		}
 	case '-': { 
 		result = b-a; 
 		break;
 		}
 	case '*': { 
 		result = b*a;
 		break;
 		}
 	case '/': { 
 		result = b/a; 
 		break;
 		}
 }
 push(stack, result);
 return 0;
}


int main()
{
index stack;
stack.size=0;
char str[100];
int control = 1;

fgets(str, 100, stdin);
char* str1 = strtok(str, " "); //разбиение на лексемы

while(str1 != NULL)
{
  if(isdigit(*str1)) //проверяет аргумент, является ли он десятичной цифрой
      push(&stack, atoi(str1));

      else

  if(strlen(str1) > 1) //если число двузначное или больше
  {
      push(&stack, atoi(str1));
  }

      else
  if(strlen(str1) == 1) //если это символ, то 
  {
      if(funct(&stack, *str1) == 1)
      control = 1;
  }

  str1 = strtok(NULL, " \n");
}

if(sizeStack(&stack) == 1)
  printf("%d\n", top(&stack));
else
{
  control = 1;
  printf("error");
  return 0;
}

return 0;
}
