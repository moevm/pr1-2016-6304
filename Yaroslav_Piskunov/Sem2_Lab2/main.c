/* Yaroslav_Piskunov, gr 6304
Lab Work №2 - Stack Model */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STACKSZ 500

void push (int* stak_massive, int ElementToPush, int* size) { //Function for adding new element to stack
 
    stak_massive[*size] = ElementToPush;
            printf("ok\n");
            (*size)++;
}

void pop (int* stak_massive, int* size) { //Function for deleting last element and printig it
 
     printf("%d\n",  stak_massive [(*size)-1]);
                (*size)--; 
            
    
}

void razmer (int size) { //Founction for printing size of stack
 printf("%d\n", size);   
}


void top (int* stak_massive, int* size) { //Function for printing last element without deleting
 
    printf("%d\n", stak_massive[(*size)-1]);
    
}

int main() {
  int STACKSZ_Ammount = 1; //Ammount of stack blocks with size STACKSZ
  int ElementToPush = 0;
  int size = 0;
  int* stak_massive = (int*)malloc(STACKSZ*sizeof(int));
  char* commandLine = (char*)malloc(100*sizeof(char));
  int commandNumber = 404;
    while(1==1) { 
        if (size == STACKSZ*STACKSZ_Ammount){ //Addnig new block of memory if needed
         STACKSZ_Ammount++;   
        stak_massive = (int*)realloc(stak_massive, sizeof(int)*STACKSZ*STACKSZ_Ammount);
        } 
        
        fgets(commandLine, 100, stdin);
        if(strchr(commandLine, '\n')) 
        *strchr(commandLine, '\n') = '\0';

      
    //Reading comand and interpretating it to number
	    if(strcmp(commandLine, "pop") == 0)
            commandNumber = 2;
	    if(strcmp(commandLine, "top") == 0)
            commandNumber = 3;
	    if(strcmp(commandLine, "size") == 0)
            commandNumber = 4;
	    if(strcmp(commandLine, "exit") == 0)
            commandNumber = 5;
        
        else if (strstr(commandLine, "push ") && strlen(commandLine) >= 6) //Taking argument for command "Push"
	{
		commandLine = commandLine + 5*sizeof(char);
		ElementToPush = atoi(commandLine);
		commandNumber = 1;
    }
                
        
        switch (commandNumber) {
            case 1: //In case of command "Push"
            push(stak_massive, ElementToPush, &size);
				break;
            case 2: //In case of command "Pop"
            if (size!=0)
               pop (stak_massive, &size);
            else { 
                printf("error\n");
                return 0; 
            } break;
            case 3: //In case of command "Top"
            if (size!=0)
                top(stak_massive, &size);
            else { 
                printf("error\n");
                return 0; 
            } break;
            case 4: //In case of command "Size"
            razmer(size);
            break;
            case 5: //In case of command "Exit"
            printf("bye\n");
            free(stak_massive);
            return 0;
            break;
            case 404: //In case of wrong command
            printf("error\n");
                return 0; 
            break;
    }
    }   
  return 0;
}
