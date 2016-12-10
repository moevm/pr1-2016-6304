#include <stdio.h>

void print_sentence (char* sentence, int len_sentence)
{
  int i=0;
	while (sentence[i]==' ' || sentence[i]=='\n')
	{
		i++;
	}
  for (i; i < len_sentence; i++)
  {
    printf("%c", sentence[i]);
  }
}

int main()
{
  char c, sentence[1024];
  int lenght = 0, i=0;
	int sentence_count_before=0, sentence_count_after=0;
  while ((c = getchar()) != '!')
  {
    switch (c)
    {
      case '\t': break;
      case '.': 
      case ';':
			{
				sentence_count_before++;
				sentence_count_after++;
				sentence[i] = c;
				i++;
				sentence[i] = '\n';
				i++;
				print_sentence (sentence,i);
				i = 0; 
				break;
			}
      case '?': 
			{
				sentence_count_before++;
				i = 0; 
				break;
			}

      default:
      {
        sentence[i] = c;
        i++;
      }
    }
  }
printf("Количество предложений до %d и количество предложений после %d\n",sentence_count_before, sentence_count_after);
return 0;
}
