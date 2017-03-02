// Laba_3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdio.h>
#include <stdlib.h>

void print_sentence(char* buf, int lenth, int count);		// ������ �����������

int main()
{
	char* buffer = (char*)malloc(sizeof(char) * 100);		// ������ ��� �������� �����

	int count = 0;			// ����� ������ �����
	/* ���������� ��������� �������� �������, ��� ���������� ����� ������� ������������� � ��� ���� */
	int im_count = 100;

	int n = 0;				// ���������� ����������� � ����������� ������ 
	int m = 0;				// ���������� ����������� � ����������������� ������
	int buf = 0;
	int lenth = 0;			// ����� �������� �����������

	/* ������������ ���������� ��������� ������ �� ����� "!" */
	while ((buf = getchar()) != '!')
	{
		if (count == im_count)
		{
			im_count *= 2;
			buffer = (char*)realloc(buffer, sizeof(char)*im_count);
		}
		buffer[count++] = (char)buf;
	}

	/* �������������� ������ */
	for (int i = 0; i < count; i++)
	{

		if ((buffer[i] == '.') || (buffer[i] == ';'))
		{
			print_sentence(buffer, lenth, i);		// �������� ��������� �����������

			n++; m++;		// ����������� ��� ��������
			lenth = 0;		// �������� ����� �������� �����������
		}

		else if (buffer[i] == '?')
		{
			n++;		// ����������� ������ �������  ����������� ��
			lenth = 0;		// �������� ����� �������� �����������
		}

		/* ���������� �������� � ������� � ������ ����������� � ������ ����� ������ */
		else if (((buffer[i] == '\t') && (lenth == 0)) || (buffer[i] == '\n') || ((buffer[i] == ' ') && (lenth == 0)));

		/* ��� ������� ������� ����������� ����� �������� ����������� */
		else
			lenth++;

	}

	printf("���������� ����������� �� %d � ���������� ����������� ����� %d \n", n, m);

	free(buffer);

	system("pause");

	return 0;
}

void print_sentence(char* buf, int lenth, int i)
/* ������ �����������. lenth - ����� �������� ����������, i - ������� ������� ��� ������� �� ������� */
{
	for (int g = i - lenth; g <= i; g++)
		printf("%c", buf[g]);
	printf("\n");
}