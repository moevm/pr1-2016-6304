#include <stdio.h>
int get_max(int arr[], int n);
int get_min(int arr[], int n);
int get_sum(int arr[], int n);
int get_count_first_el(int arr[], int n);
void main (int ch, int arr[], int n){
	scanf ("%d %d", &n, &ch);
	int k;
	for (k=0; k<n; ++k)
		scanf (" %d", &arr[k]);
	switch (ch) {
		case 0:
		printf ("%d\n", get_max(arr,n));
		break;
		case 1:
		printf ("%d\n", get_min(arr,n));
		break;
		case 2:
		printf ("%d\n", get_sum(arr,n));
		break;
		case 3:
		printf ("%d\n", get_count_first_el(arr,n));
		break;
		default:
		printf ("Данные некорректны");
		}
	}

int get_max(int arr[], int n){
	int k;
	int S=0;
	for (k=0; k<n; ++k){
		if (arr[k]>S)
		S=arr[k];
		}
	return S;
	}

int get_min(int arr[], int n){
	int k;
	int S=arr[0];
	for (k=0; k<n; ++k){
		if (arr[k]<S)
		S=arr[k];
		}		
	return S;
	}	


int get_sum(int arr[], int n){
	int k;
	int S=0;
	for (k=0; k<n; ++k){
		if (arr[k]%2==0)
		S=S+arr[k];
		}
	return S;
	}	


int get_count_first_el(int arr[], int n){
	int k;
	int S=0;
	for (k=0; k<n; ++k){
		if (arr[k]==arr[0])
		++S;
		}
	return S;
	}

