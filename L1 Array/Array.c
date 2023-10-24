/* Write a program to Insert and Delete elements in array */

#include<stdio.h>
#define size 10

int arr[size], item = 0; 

void show_Elements(){
    int i;
    printf("\n\tElements of Array: \n");
    if(item>0){
        for(i=0; i<item; i++){
            printf("\t[%d] %d ",i+1,arr[i]);
        }
        printf("\n");
    }
    else printf("\n\tUnderFlow\n");
}

void insert_Last_Element(){
    int num;
    if(item < size){
        printf("\n\tEnter the Element to be inserted: ");
        scanf("%d",&num);
        arr[item] = num;
        item++;
        printf("\tElement Inserted in the Last\n");
    }
    else {
        printf("\n\tArray OverFlow\n");
    }
    show_Elements();
}

void insert_First_Element(){
    int num;
    if(item < size){
        printf("\n\tEnter the Element to be inserted: ");
        scanf("%d",&num);
        for(int i = item; i>0; i--){
            arr[i] = arr[i-1];
        }
        arr[0] = num;
        item++;
        printf("\tElement Inserted in the Beginning\n");
    }
    else {
        printf("\n\tArray OverFlow\n");
    }
    show_Elements();
}

void insert_Pos_Element(){
    int pos, num, p;
    if(item == 0)insert_First_Element();
    else if(item < size){
        show_Elements();
        printf("\n\tEnter Position on which New Element to be Inserted : ");
        scanf("%d",&pos);
        p = pos;
        if(pos>1 && pos <= item){
            for(int i = item; i>pos-1; i--){
                arr[i] = arr[i-1];
            }
            printf("\n\tEnter the Element to be inserted: ");
            scanf("%d",&num);
            arr[pos-1] = num;
            item++;
            printf("\tElement Inserted Seccesfully at %d th Position\n", p);
            show_Elements();
        }
        else if(pos == 1)insert_First_Element();
        else if(pos == item + 1)insert_Last_Element();
        else printf("\tInvalid Position\n");
    }
    else {
        printf("\n\tArray OverFlow\n");
    }
}
void delete_First_Element(){
    if(item > 0){
        for(int i = 0; i<item; i++){
            arr[i] = arr[i+1];
        }
        item--;
        printf("\tElement Deleted in the Beginning\n");
    }
    else {
        printf("\n\tArray UnderFlow\n");
    }
}

void delete_Pos_Element(){
    int pos, p;
    if(item > 0){
        show_Elements();
        printf("\n\tEnter Position of Element to Delete : ");
        scanf("%d",&pos);
        p = pos;
        if(pos>1 && pos < item){
            for(int i = pos-1; i<item; i++){
                arr[i] = arr[i+1];
            }
            item--;
            printf("\tElement Deleted Seccesfully from %d th Position\n",p);
        }
        else if(pos == 1)delete_First_Element();
        else if(pos == item)delete_Last_Element();
        else printf("\tInvalid Position\n");
    }
    else {
        printf("\n\tArray UnderFlow\n");
    }
}


void delete_Last_Element(){
    if(item>0){
        item--;
        printf("\tLast Element Deleted\n");
    }
    else {
        printf("\tArray UnderFlow\n");
    }
}

int main(){
    int n, i, c;
    printf("\t**** Welcome to Array Program ****\n");
    printf("\tEnter No. of Element To Be Inserted : ");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        if(i<size){
            printf("\t\tEnter Element [%d] : ",i+1);
            scanf("%d",&arr[i]);
            item++;
        }
        else {
            printf("\n\tArray OverFlow\n");
            break;
        }
    }
    printf("\n");
    show_Elements();
    do{
        printf("\n\t****** Perform Operations on Array ******\n");
        printf("\t\t1. Traverse Array\n");
        printf("\t\t2. Insert an Element in Array\n");
        printf("\t\t3. Delete an Element in Array\n");
        printf("\t\t4. Exit\n");
        printf("\n\t\t\t>>> ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            show_Elements();
            break;
        case 2:
            insert_Pos_Element();
            break;
        case 3:
            delete_Pos_Element();
            break;
        default:
            if(c!=0)printf("\tInvalid Choice\n");
            break;
        }
    } while(c);
    return 0;
}