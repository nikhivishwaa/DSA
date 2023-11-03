// Binary Search Program
#include <stdio.h>
#define size 10

int arr[size], key = 0, item = 0;

int sort(){
    int hold = 0;
    for(int i = 0; i<item-1; i++){
        if(arr[i]<=arr[i+1])continue;
        else{
            hold = arr[i];
            arr[i] = arr[i+1];
            arr[i+1] = hold;
        }
        // printf("%d\t",arr[i]);
    }
    return 0;
}
int binarySearch(){
    int lb = 0, ub = size -1, mid = 0;
    do{
        mid = (lb + ub)/2;
        // printf("%d\t",mid);
        if(arr[mid]==key){
            printf("Search Successful\t Pos: %d",mid+1);
            break;
        }
        else if(arr[mid]<key)lb = mid + 1;
        else if(arr[mid]>key)ub = mid - 1;
    } while(!(lb>ub));
    return 0;
}

int main() {
    int i,j;
    printf("Enter Elements of Array:\n");
    for(i=0; i<size; i++){
        printf("[%d] : ",i+1);
        scanf("%d",&arr[i]);
        item++;
        sort();
    }
    sort();
    do{
        printf("\n\t1 to search\n\t0 to exit\n\t\t>> ");
        scanf("%d",&j);
        switch(j){
            case 1:
                printf("\n\nEnter Key to Search: ");
                scanf("%d",&key);
                binarySearch(); 
                break;
            default:
                printf("Invalid Input");
                break;
        }
    }while(j);
    return 0;
}
