#include<stdio.h>
#include<stdlib.h>
#define size 20

int arr[size], item, key, success;

void search(){
    printf("Enter Element to Search: ");
    scanf("%d", &key);
    if(item == 0)printf("\n\tElement not Found\n");
    else if(item > 0){
        success = 0;
        for(int i = 0; i < item; i++){
            if(arr[i] == key){
                printf("\n\tElement Found at %d th Position\n", i+1);
                success = 1;
                break;
            }
        }
        if(success == 0)printf("\n\tElement not Found\n");
    }
}

int main(){
    int c;
    printf("\tEnter How many Element to be Inserted: ");
    scanf("%d", &c);
    for(int i = 0; i < c; i++){
        printf("[%d] : ", i+1);
        scanf("%d", &arr[i]);
        item++;
        if(i == size - 1){
            printf("\n\tArray OverFlow\n");
            break;
        }
    }
    do{
        printf("\n\t****** Linear Search Program *******");
        printf("\n\t\t1. Search an Element");
        printf("\n\t\t2. Exit");
        printf("\n\t\t\t>>> ");
        scanf("%d", &c);
        switch (c)
        {
        case 1:
            search();
            break;
        case 2:
            c = 0;
            break;
        default:
            printf("\n\tInvalid Choice\n");
            break;
        }
    }while (c);
    
    return 0;
}