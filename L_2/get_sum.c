int get_sum (int arr[], int n)
{
        int i = 0, a = 0;
        while (i < n)
        {
                if ((arr[i]%2) == 0)
                        a+=arr[i];
                ++i;
        }
        return a;
}


