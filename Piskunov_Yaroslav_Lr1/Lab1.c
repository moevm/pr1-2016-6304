//Main file for Lab 1
//Piskunov Yaroslav Andreevich, gr 6304

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//Function to compare two values with type of char*
//returns 0 if two strings are equal
int comparator (const void* a, const void* b){
 return strcmp ((char*)a, (char*)b);
}

//Main function
int main() {
    int i = 0;
    char text[1000];
    char str[30];
    
    fgets(text, 1000, stdin);
    fgets(str, 30, stdin);
    
    char words[1000][1000];
    
    char* ptr = strtok(text, " ."); //Finding first word using standart function "Strtok"
    while (ptr){
        strcpy(words[i], ptr);
        ptr = strtok(NULL, " ."); //Finding next word
        i++;
    }
    
    qsort(words, i, 1000, comparator); //Sorting Massive of words using standart function "qsort"
    
    char* pointer_on_str = (char*)bsearch(str, words, i, 1000, comparator); //Searching "str" in Massive of words
    
    if (pointer_on_str==NULL)
        printf("doesn't exist\n");
    else printf("exists\n");
    
  return 0;
}

