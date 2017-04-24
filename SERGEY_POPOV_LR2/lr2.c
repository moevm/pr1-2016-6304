#include <stdio.h>
#include <string.h>

typedef struct tag
{
	char value[300];
} tag;

typedef struct tag_list
{
	tag list[3000];
	int count;
}	tag_list;


int parse_html(char html[])
{
// initialize stack for list of tags	
	tag_list t_list;
	t_list.count = 0;
	
	int len = strlen(html);
	int i,j;
	tag temp_tag;
	for (i = 0; i < len; i++)
	{
// close brackets are not allowed without open bracket
		if (html[i] == '>')
			return 1; // error

		if (html[i] == '<')
		{
			j = 0;
// add "<" to tag
			temp_tag.value[j] = html[i];
			j++;
			i++;
// missing close bracket
			if (i >= len)
				return 1; // error

// read tag body
			while (html[i] != '>')
			{
// open brackets are not allowed in tag body
				if (html[i] == '<')
					return 1; // error

				temp_tag.value[j] = html[i];
				j++;
				i++;
			}
// add ">" and trailing "\0" to tag	
			temp_tag.value[j] = html[i];
			temp_tag.value[j+1] = '\0';

// tag found, if it's closing, check if it matches last open tag
			if (is_closing(&temp_tag))
			{
				if (are_tags_matched(&(t_list.list[t_list.count-1]), &temp_tag))
				{
					t_list.count--; // pop tag from a list
				}
				else
				{
					return 1; // error, closing tag doesn't match open one
				}
			}
			else
			{
// skip void tags like <br>, <hr>
				if (is_tag_void(&temp_tag) == 0)
				{
// push new open tag to the list
					strcpy(t_list.list[t_list.count].value, temp_tag.value);
					t_list.count++;
				}			
			}
		}
	}
	if (t_list.count != 0)
		return 1; // error, tags mismatch

	return 0; // success
}

int is_tag_void(tag* test_tag)
{
	if (strcmp(test_tag->value,"<br>") == 0)
		return 1;
	if (strcmp(test_tag->value,"<hr>") == 0)
		return 1;

	return 0;
}

int is_closing(tag* test_tag)
{
	if (test_tag->value[1] == '/')
	{
		return 1; // closing
	}
	else
	{
		return 0; // not closing
	}
}

int are_tags_matched(tag* open_tag, tag* close_tag)
{
	if (strcmp(&(open_tag->value[1]), &(close_tag->value[2])) == 0)
		return 1;

	return 0;			
}

int main()
{
// read html
	int i = 0;
	char html[3000];
	char temp;
	while((temp = getchar()) != '\n')
	{
		html[i] = temp;
		i++;
	}
	html[i] = '\0';

// parse html
	int result = parse_html(html);
	if (result != 0)
	{
		printf("wrong\n");
		return 0;
	}
	printf("correct\n");

	return 0;
}
