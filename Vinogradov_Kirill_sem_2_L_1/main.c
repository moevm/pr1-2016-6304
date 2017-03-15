#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp(const void* p1, const void* p2)	//ðåàëèçàöèÿ ôóíêöèè ñðàâíåíèÿ äëÿ
{								//ñòðîê
    return strcmp((char*)p1, (char*)p2);	
}

int main()
{
    int counter=0;
    int i=0;					//ñ÷å÷èêè è ïåðåìåííûå
    int max=0;

    char text[1000];			//ìàññèâ äëÿ òåêñòà íà ââîä
    char str[30];				//ìàññèâ äëÿ èñêîìîãî ñëîâà
    char words[500][1000];		//ìàññèâ äëÿ ðàçáèåíèÿ òåêñòà íà ñëîâà

    fgets(text, 1000, stdin);		//ñ÷åò ñ âõîäíîãî ïîòîêà â ïåðâûå
    (*strstr(text, "\n"))='\0';		//äâà ìàññèâà
    fgets(str, 30, stdin);

    char* token=strtok(text, " .");		//ðàçäåëåíèå òåêñòà íà ñëîâà
    while(token!=NULL)
    {
        int numb=strlen(token);			//ïîäñ÷åò äëèíû êàæäîãî ñëîâà
        strncpy(words[i], token, numb);		//êîïèðîâàíèå â ìàññèâ ñëîâ
        token=strtok(NULL, " ,");
        i++;
    }

    qsort(words, i, 1000, cmp);			//ôóíêöèÿ áûñòðîé ñîðòèðîâêè

    char* pointer=(char*)bsearch(str, words, i, 1000, cmp);	//ôóíêöèÿ áèíàðíîãî
											//ïîèñêà
    if(pointer!=NULL)
    {
        printf("exists\n");
    }
    else								//âûâîä ðåçóëüòàòà ïîèñêà
    {
        printf("doesn't exist");
    }

    return 0;
}
