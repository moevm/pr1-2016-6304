void menu(nt ch, int arr[], int n){ 
if (n<=0) 
{ 
  printf("Данные некорректны"); 
  return; 
} 
else 
{
  switch (ch) { 
  case 0: printf("%d\n",get_max(arr,n)); 
  return; 
  case 1: printf("%d\n",get_min(arr,n)); 
  return; 
  case 2: printf("%d\n",get_sum(arr,n)); 
  return; 
  case 3: printf("%d\n",get_count_first_el(arr,n)); 
  return; 
  default: printf("Данные некорректны\n"); 
} 

} 

int get_max(int arr[], int n)
{ 
   int max=arr[0]; 
   for(int i=1;i<n;i++) 
   { 
      if(max<arr[i]) 
        max=arr[i]; 
   } 
   return max; 

} 

int get_min(int arr[], int n)
{ 
   int min=arr[0]; 
   for(int i=1;i<n;i++) 
   { 
      if(min>arr[i]) 
        min=arr[i]; 
   } 
   return min; 

} 

int get_sum(int arr[], int n)
{ 
   int sum=0; 
   for (int i=0;i<n;i++) 
   { 
      if (arr[i]%2==0) 
        sum+=arr[i]; 
  } 
   return sum; 

} 

int get_count_first_el(int arr[], int n)
{ 
    int summ=0; 
    for (int i=1;i<n;i++) 
    { 
      if (arr[i]==arr[0]) 
        summ++; 
    } 
   return summ;
}
