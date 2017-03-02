int get_count_first_el (int arr[], int n)
{
        int i = 0, a = 0;
        int s = arr [i++];
        while (i < n)
        {
                if (arr [i] == s)
                        ++a;
                ++i;
        }
        return a;
}

