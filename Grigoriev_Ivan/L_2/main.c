int get_max(int arr[], int n){
    int i;
    int max=arr[0];
    for (i=0;i<n;i++){
        if (arr[i] > max)
            max = arr[i];
    }
    return max;
}

int get_min(int arr[], int n){
    int i;
    int min=arr[0];
        for (i=0;i<n;i++) {
        if (arr[i] < min)
            min = arr[i];
    }
    return min;
}

int get_sum(int arr[], int n){
    int sum=0;
    int i;
    for (i=0;i<n;i++) {
        if (arr[i] % 2 == 0)
            sum+=arr[i];
    }
    return sum;
}

int get_count_first_el(int arr[], int n){
    int i;
    int firstel=-1;
    for (i=0;i<n;i++){
        if (arr[i] == arr[0])
            firstel=firstel+1;
    }
    return firstel;
}

void menu(int ch, int arr[], int n){
    switch (ch) {
    case 0:
        printf("%d", get_max(arr, n));
        break;
    case 1: 
        printf("%d", get_min(arr, n));
        break;
    case 2:
        printf("%d", get_sum(arr, n));
        break;
    case 3:
        printf("%d", get_count_first_el(arr,n));
        break;
    default:
        printf("Данные некорректны");
        break;
        
    }

}
