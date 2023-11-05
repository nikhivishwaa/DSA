#include<stdio.h>

int main()
{
    int n, i, j, min_idx;
    printf("\n\tEnter the number of elements: ");
    scanf("%d", &n);
    int arr[n];
    for (i = 0; i < n; i++){
        printf("\t[%d] : ",i+1);
        scanf("%d",&arr[i]);
    }

    for (i = 0; i < n - 1; i++){
        min_idx = i;
        for (j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];

        arr[i] = temp;
    }

    printf("\n\tSorted array in ascending order: \n");
    for (i = 0; i < n; i++)
    {
        printf(" %d ", arr[i]);
    }
    return 0;
}