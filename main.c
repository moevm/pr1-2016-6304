#include "stdio.h"

void menu(int ch, int arr[], int n){        //���������� ������� ����

scanf("%d%d", n, ch);
	for (int i = 0;i < n ;i++)
		scanf("%d", arr[i]);

	switch (ch)            //�������� Switch (�������� �������������� ������ ��� ���������� ch)
	{
	case 0: get_max(arr, n); break; // � ������ 0 �������� ��������� ������� ������ ������������� �������� �������

	case 1: get_min(arr, n); break; //� ������ 1 �������� ��������� ������� ������ ������������ �������� �������

	case 2: get_sum(arr, n); break; // � ������ 2 �������� ��������� ������� �������� ����� ������ ��������� �������

	case 3: get_count_first_el(arr, n); break; // � ������ 3 �������� ��������� ������� �������� ������� �������� �������� �������

	default: printf("������ �����������"); //� ��������� ������ ������ ��������� � �������������� ������
	}
}

int get_max(int arr[], int n){ // ���������� ������� ������ ������������� �������� �������
	int i;
	int max = arr[0];
	for (i = 0;i < n; i++)
	{
		if (arr[i] >= max) max = arr[i];
	}
	printf("%d", max);
}

int get_min(int arr[], int n){ // ���������� ������� ������ ������������ �������� �������
int i;
	int min = arr[0];
	for (i = 0;i < n; i++)
	{
		if (arr[i] <= min) min = arr[i];
	}
	printf("%d", min);
}

int get_sum(int arr[], int n){ // ���������� ������� �������� ����� ������ ���������
int s = 0;
	int i;
	for (i = 0;i < n;i++) {
		if (arr[i] % 2 == 0)
			s = s + arr[i];
	}
	printf("%d", s);
}

int get_count_first_el(int arr[], int n){  // ���������� ����� � ���������� �������
int i;
int k=0;
	for (i = 0;i < n;i++)
	{
		if (arr[i] == arr[0]) k++;
	}
	printf("%d", k-1);
}
