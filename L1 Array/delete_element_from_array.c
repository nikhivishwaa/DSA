/* Write a program to delete elements from an array */
#include<stdio.h>

void show_Elements(int arr[], int nel){
    int i;
    printf("Elements of Array: ");
    for(i=0; i<nel; i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
int delete_Elements(int arr[], int size, int nel){
    int num;
    if(nel>0){
        nel--;
        printf("Last Element Deleted\n");
    }
    else {
        printf("Array UnderFlow\n");
    }
    show_Elements(arr,nel);
    return nel;
}

int main(){
    int size = 5, n_ = 4, arr[size];
    arr[0] = 11;
    arr[1] = 8;
    arr[2] = 12;
    arr[3] = 46;
    show_Elements(arr,n_);
    printf("no of elements : %d\n",n_);
    n_ = delete_Elements(arr,size,n_);
    printf("no of elements : %d\n",n_);
    return 0;
}