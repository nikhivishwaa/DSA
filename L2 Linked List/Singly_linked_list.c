#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node * link;
};

struct node *start = NULL;
struct node *temp;
struct node *ptr; 
struct node *ptr1;
int n_nodes = 0;

void insert_first(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)printf("\nOVERFLOW\n");
    else {
        int c;
        printf("\nEnter Data to be Inserted: ");
        scanf("%d",&c);
        ptr->data = c;
        ptr->link = start; 
        start = ptr;
        n_nodes++;
        printf("\t* Element Inserted in the Beginning\n");
    }
}

void insert_last(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)printf("\nOVERFLOW\n");
    else if(start==NULL)insert_first();
    else {
        int c;
        printf("\nEnter Data to be Inserted: ");
        scanf("%d",&c);
        ptr->data = c;
        ptr->link = NULL; 
        ptr1 = start;
        while(ptr1->link!=NULL){
            ptr1 = ptr1->link;
        }
        ptr1->link = ptr;
        n_nodes++;
        printf("\t* Element Inserted at the End\n");
    }
}

void insert_bypos(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr==NULL)printf("\nOVERFLOW\n");
    else {
        int c,pos;
        printf("\nEnter Position to Insert Data: ");
        scanf("%d",&pos);
        if(pos>0 && pos<=n_nodes+1){
            if(pos==1)insert_first();
            else if(pos==n_nodes+1)insert_last();
            else {
                printf("\nEnter Data to be Inserted: ");
                scanf("%d",&c);
                ptr->data = c;
                ptr1 = start;
                for(int x = pos-1; x>0; x--){
                    temp = ptr1;
                    ptr1 = ptr1->link;
                }
                ptr->link = ptr1; 
                temp->link = ptr;
                n_nodes++;
                printf("\t* Element Inserted at %dth Position\n",pos);
            }
        }
    else printf("\n\t* Invalid Position");
    }
}

void delete_first(){
    if(start==NULL)printf("\nUNDERFLOW\n");
    else {
        ptr = start;
        start = start->link;
        free(ptr);
        n_nodes--;
        printf("\t*Element Deleted from the Beginning");
    }
}
void delete_last(){
    if(n_nodes<=1) delete_first();
    else {
        ptr = start;
        while(ptr->link != NULL){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = NULL;
        free(ptr);
        n_nodes--;
        printf("\t*Element Deleted at the End");
    }
}
void delete_bypos(){
    if(start==NULL)printf("\nUNDERFLOW\n");
    else {
        int c,pos;
        printf("\nEnter Position to Delete Data: ");
        scanf("%d",&pos);
        if(pos>0 && pos<=n_nodes){
            if(pos==1)delete_first();
            else if(pos==n_nodes)delete_last();
            else {
                ptr = start;
                c = pos;
                while(c-1>0){
                    ptr1 = ptr;
                    ptr = ptr->link;
                    c--;
                }
                ptr1->link = ptr->link;
                free(ptr);
                n_nodes--;
                printf("\t* Element Deleted at %dth Position\n",pos);
            }
        }
    else printf("\n\t* Invalid Position");
    }
}

void display_list(){
    if(start==NULL)printf("\nUNDERFLOW\n");
    else {
        printf("List Elements are: \n");
        for(temp = start; temp!=NULL; temp = temp->link){
            printf("%d",temp->data);
            if(temp->link != NULL)printf(" -> ");
        }
    }
}

int main(){
    int x = 1,y;
    while(x){
        switch(x){
            case 1:
                printf("\t****** Insert a Node ******");
                printf("\n\t1. At the Beginning");
                printf("\n\t2. At the End");
                printf("\n\t3. At Specified Position\n\t\t>> ");
                scanf("%d",&y);
                switch (y)
                {
                case 1:
                    insert_first();
                    break;
                case 2:
                    insert_last();
                    break;
                case 3:
                    insert_bypos();
                    break;
                
                default:
                    printf("\t* Invalid Choice\n");
                    break;
                }
                break;
            case 2:
                display_list();
                break;
            case 3:
                printf("\t****** Delete a Node ******");
                printf("\n\t1. At the Beginning");
                printf("\n\t2. At the End");
                printf("\n\t3. At Specified Position\n\t\t>> ");
                scanf("%d",&y);
                switch (y)
                {
                case 1:
                    delete_first();
                    break;
                case 2:
                    delete_last();
                    break;
                case 3:
                    delete_bypos();
                    break;
                
                default:
                    printf("\t* Invalid Choice\n");
                    break;
                }
                break;
            default:
                printf("\t* Invalid Choice\n");
                break;
        }
        printf("\n***** Linked List Operations *****");
        printf("\n1. Insert a Node");
        printf("\n2. Display Linked List");
        printf("\n3. Delete a Node");
        printf("\n0. Exit");
        printf("\n\tEnter Your Choice >>> ");
        scanf("%d",&x);
    }
    printf("\n\n\t****** Thanks For Using ******");
    return 0;
} 
