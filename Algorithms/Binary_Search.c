// Binary Search Program
#include <stdio.h>
#define size 10

int arr[size], key = 0, item = 0;

void ascending(){
    int hold = 0;
    for(int i = item - 1; i>0; i--){
        if(arr[i]>=arr[i-1])break;
        else{
            hold = arr[i];
            arr[i] = arr[i-1];
            arr[i-1] = hold;
        }
    }
}
void binarySearch(){
    int lb = 0, ub = size -1, mid = 0;
    do{
        mid = (lb + ub)/2;
        if(arr[mid]==key){
            printf("\n\tSearch Successful\t Pos: %d",mid+1);
            break;
        }
        else if(arr[mid]<key)lb = mid + 1;
        else if(arr[mid]>key)ub = mid - 1;
    } while(!(lb>ub));
    if(lb>ub)printf("\n\tSearch Unsuccessful");
}

int main() {
    int i,j;
    printf("Enter Elements of Array:\n");
    for(i=0; i<size; i++){
        printf("[%d] : ",i+1);
        scanf("%d",&arr[i]);
        item++;
        ascending();
    }
    printf("\n");
    for(i=0; i<item;i++)printf("\t%d",arr[i]);
    do{
        printf("\n\t***** Welcome to Binary Search Program *****");
        printf("\n\t\t1 to search\n\t\t0 to exit\n\t\t\t>> ");
        scanf("%d",&j);
        switch(j){
            case 1:
                printf("\n\tEnter Key to Search: ");
                scanf("%d",&key);
                binarySearch(); 
                break;
            default:
                printf("\n\tInvalid Input");
                break;
        }
    }while(j);
    return 0;
}
