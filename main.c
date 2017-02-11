#include "stdio.h"

void print(char* a, int len) //�������� ������� ������ �����������
{	for (int i = (a[0] == ' ') ? 1 : 0; i < len; i++) //�������� ����������� �� ������� ������� �������
		printf("%c", a[i]);
}

int main()
{
	char c;
	char* buf=NULL;
	int m = 0, n = 0, len = 0;
	while ((c = getchar()) != '!') //��������� ��� ������� �� (!)
	{
		switch (c) //���������� ������ ����������
		{
		case '.':  print(buf, len); printf("%c\n", c); len = 0; m++; n++; break;
		case ';':  print(buf, len); printf("%c\n", c); len = 0; m++; n++; break;
		case '?':  len = 0; m++;    break;
		case '\n': len = 0;    	    break;
		case '\t': len = 0;    	    break;
		default: // ������ ������ �������� ( �� ; . ? \n \t)
            {
                buf = (char*)realloc(buf, (++len) * sizeof(char)); // �������� ������ ��� ������ ������
                buf[len - 1] = c;
            }
		}
	}
	printf("���������� ����������� �� %d � ���������� ����������� ����� %d", m, n); //����� ����������
	return 0;
}
