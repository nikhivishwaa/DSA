/* Write a program to insert an element into an array
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
int insert_Elements(int arr[], int nel, int size){
    int i, num, position, element;
    if(nel<size){
        printf("Enter the element to be inserted: ");
        scanf("%d", &element);
        printf("Enter the position from 1 to %d: ",nel+1);
        scanf("%d", &position);
        if(position>=1 &&  position<=nel){
            for(i=nel; i!=position-1; i--){
                arr[i] = arr[i-1];
            }
            arr[i] = element;
            nel++;
            printf("Element Inserted Successfully\n");
        }
        else if(position == nel+1){
            arr[position-1] = element;
            nel++;
            printf("Element Inserted Successfully\n");
        }
        else printf("Invalid Position\n");
    }
    else {
        printf("Array OverFlow\n");
    }
    show_Elements(arr,nel);
    return nel;
}


int main(){
    int size = 10, n_ = 3, arr[size];
    arr[0] = 11;
    arr[1] = 8;
    arr[2] = 21;
    while(size!=n_){
        show_Elements(arr,n_);
        n_ = insert_Elements(arr,n_,size);
        printf("no of elements : %d\n\n",n_);
        if(n_ == size)break;
    }
    return 0;
}