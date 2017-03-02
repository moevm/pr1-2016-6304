int get_max (int arr [], int n)
{
        int i = 0;
        int a = arr [i++];
        while (i < n)
        {
                if (arr[i] >= a)
                        a = arr[i];
                ++i;
        }
        return a;
}
