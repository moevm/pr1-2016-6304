#include <stdio.h>			
#include <stdlib.h>			
#include <string.h>			

void pop(int* stack, int j)         
{
    stack[j]=0;
    
}

void push(int* stack, int* old, int j, int k)     
{
    stack[j]=old[k];
    pop(stack, j+1);
}

void pushplus(int* stack, int* old, int j, int k)   
{
    stack[j]+=old[k];
    pop(stack, j+1);
}

void pushminus(int* stack, int* old, int j, int k)  
{
    stack[j]-=old[k];
    pop(stack, j+1);
}

void pushumn(int* stack, int* old, int j, int k)   
{
    stack[j]*=old[k];
    pop(stack, j+1);
}

void pushdel(int* stack, int* old, int j, int k)    
{
    stack[j]/=old[k];
    pop(stack, j+1);
}

int top(int* stack, int j)              
{
    return stack[j];
}

int size(int* stack, int i)            
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
    int i=0;			
    int j=0;			
    int k=0;			
    int m=0;		
    char plus[2]="+";			
    char minus[2]="-";			
    char umn[2]="*";			
    char del[2]="/";			
    char origin[100];		
    char nums[100][100];		
    int inums[100];		
    int stack[100];		
    fgets(origin, 100, stdin);	
    char* token=strtok(origin, " ");	
    while(token!=NULL)				
    {							
        int numb=strlen(token);		
        strncpy(nums[i], token, numb);	
        token=strtok(NULL, " ");		
        i++;					
    }
    
    for(j=0;j<i;j++){
	if((strcmp(nums[j], plus)!=0)&&(strcmp(nums[j], minus)!=0)&&(strcmp(nums[j], umn)!=0)&&(strcmp(nums[j], del)!=0)){
	stack[k]=atoi(nums[j]);
       
        k++;
    }
        else if(strcmp(nums[j], plus)==0){	
                if(k>=2){					
                pushplus(stack, stack, k-2, k-1); 
                       
                k-=1;						
                    
                
                }							
                else{					
                    m=1;				
                    j=i;				
                }						
            }						
            else if(strcmp(nums[j], minus)==0){	
                if(k>=2){					
                pushminus(stack, stack, k-2, k-1);
                    
                k-=1;						
                 
                
                }							
                else{						
                    m=1;					
                    j=i;					
                }						
            }							
            else if(strcmp(nums[j], umn)==0){		
                if(k>=2){					
                pushumn(stack, stack, k-2, k-1);
                    
                k-=1;						
                  
               					
                }							
                else{						
                    m=1;					
                    j=i;					
            }
}							
            else if(strcmp(nums[j], del)==0){		
                if(top(stack, k-1)!=0){
                if(k>=2){
                pushdel(stack, stack, k-2, k-1);
                   
                k-=1;						
                   
               						
                }						
                else{						
                    m=1;					
                    j=i;					
                }							
            }
	}					
            
	} 
    					
    if(size(stack, i)!=1)               
             m=1;							
    if(m==0){						
        printf("\n%d", stack[0]);			
    }								
    else{							
        printf("error");				
    }								
  return 0;						
} 
