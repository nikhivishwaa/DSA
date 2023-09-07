/* Write a program to delete an element in an array
at a specific position */
#include<stdio.h>

void show_Elements(int arr[], int nel){
    int i;
    printf("Elements of Array: ");
    for(i=0; i<nel; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}

int delete_Elements(int arr[], int nel){
    int i, position;
    if(nel>0){
        printf("Enter the position from 1 to %d: ",nel);
        scanf("%d", &position);
        if(position>=1 &&  position<nel){
            for(i=position; i<nel; i++){
                arr[i-1] = arr[i];
            }
            nel--;
            printf("Element Deleted Successfully\n");
        }
        else if(position == nel){
            nel--;
            printf("Element Deleted Successfully\n");
        }
        else printf("Invalid Position\n");
    }
    else {
        printf("Array UnderFlow\n");
    }
    show_Elements(arr,nel);
    return nel;
}


int main(){
    int size = 10, n_ = 9, arr[size];
    arr[0] = 11;
    arr[1] = 8;
    arr[2] = 41;
    arr[3] = 18;
    arr[4] = 84;
    arr[5] = 27;
    arr[6] = 9;
    arr[7] = 10;
    arr[8] = 21;
    while(size!=n_){
        show_Elements(arr,n_);
        n_ = delete_Elements(arr,n_);
        printf("no of elements : %d\n\n",n_);
        if(n_ == 0)break;
    }
    return 0;
}