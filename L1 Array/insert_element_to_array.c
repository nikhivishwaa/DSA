/* Write a program to insert elements in an array */
#include<stdio.h>

void show_Elements(int arr[], int nel){
    int i;
    printf("Elements of Array: ");
    for(i=0; i<nel; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int insert_Elements(int arr[], int size, int nel){
    int num;
    if(nel<size){
        printf("Enter a no. to insert: ");
        scanf("%d",&num);
        arr[nel] = num;
        nel++;
        printf("Element Inserted in the Last\n");
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
    show_Elements(arr,n_);
    n_ = insert_Elements(arr,size,n_);
    printf("no of elements : %d\n",n_);
    return 0;
}