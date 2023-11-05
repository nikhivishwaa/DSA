// WAP to sort N numbers in ascending order using insertion sort.

#include<stdio.h>
#define size 10
int arr[size], hold, item = 0;

int main()
{
    int n, i, j;
    printf("\n\tEnter the number of elements: ");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("\t[%d] : ",i+1);
        scanf("%d",&arr[i]);
        item++;
        if(i == size-1){
            printf("\n\tArray OverFlow\n");
            break;
        }
    }

    for (i = 1; i < item; i++)
    {
        hold = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > hold)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = hold;
    }

    printf("\n\tSorted array in ascending order: \n");
    for (i = 0; i < item; i++)
    {
        printf(" %d ",arr[i] );
    }
    return 0;
}