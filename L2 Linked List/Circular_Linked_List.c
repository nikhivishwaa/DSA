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
int item = 0;

int isoverflow(){
    ptr = (struct node*)malloc(sizeof(struct node));
    if(ptr == NULL)return 1;
    else return 0;
}

void display_list(){
    int i = 1;
    if(start==NULL)printf("\n\tUnderFlow\n");
    else {
        printf("\n\tList Data is: \n");
        if(item == 1)printf("\t[%d]  %d ", i, start->data);
        else{
            for(temp = start; temp->link != start; temp = temp->link){
                printf("\t[%d]  %d ", i, temp->data);
                if(temp->link->link == start){
                printf("\t[%d] %d", i+1, temp->link->data);
                }
                i++;
            }
        }
        printf("\n");
    }
}
void insert_first(){
    int c;
    printf("\n\tEnter the Data to be Inserted: ");
    scanf("%d",&c);
    ptr->data = c;
    if(item == 0){
        start = ptr;
        ptr->link = start;
        item++;
        printf("\n\tThe First Node Inserted\n");
    }
    else{
        ptr->link = start; 
        start = ptr;
        item++;
        printf("\n\tNode Inserted in the Beginning\n");
    }
}

void insert_last(){
    int c;
    printf("\n\tEnter the Data to be Inserted: ");
    scanf("%d", &c);
    ptr->data = c;
    ptr->link = start; 
    ptr1 = start;
    while(ptr1->link != start){
        ptr1 = ptr1->link;
    }
    ptr1->link = ptr;
    item++;
    printf("\n\tNode Inserted at the End\n");
    display_list();
}

void insert_bypos(){
    int c,pos;
    c = isoverflow();
    if(c)printf("\n\tOverFlow\n");
    else{
        if(item == 0)insert_first();
        else{
            display_list();
            printf("\n\tEnter Position on which New Data to be Inserted: ");
            scanf("%d",&pos);
            if(pos>0 && pos<=item+1){
                if(pos==1){
                    temp = start;
                    insert_first();
                    ptr1 = temp;
                    while(ptr1->link != temp){
                        ptr1 = ptr1->link;
                    }
                    ptr1->link = start;
                    display_list();
                    }
                else if(pos == item+1)insert_last();
                else {
                    printf("\n\tEnter Data to be Inserted: ");
                    scanf("%d",&c);
                    ptr->data = c;
                    ptr1 = start;
                    for(int x = pos-1; x>0; x--){
                        temp = ptr1;
                        ptr1 = ptr1->link;
                    }
                    ptr->link = ptr1; 
                    temp->link = ptr;
                    item++;
                    printf("\n\tNode Inserted at %d th Position\n",pos);
                    display_list();
                }
            }
            else printf("\n\t* Invalid Position\n");
        }
    }
}

void delete_first(){
    if(item == 1){
        ptr = start;
        start = NULL;
        free(ptr);
        item--;
        printf("\n\tNode Deleted from the First Position\n");
    }
    else {
        ptr = start;
        start = start->link;
        ptr1 = ptr;
        while(ptr1->link != ptr){
            ptr1 = ptr1->link;
        }
        ptr1->link = start;
        free(ptr);
        item--;
        printf("\n\tNode Deleted from the First Position\n");
    }
}
void delete_last(){
        ptr = start;
        while(ptr->link != start){
            ptr1 = ptr;
            ptr = ptr->link;
        }
        ptr1->link = start;
        free(ptr);
        item--;
        printf("\n\tNode Deleted from the End Position\n");
}
void delete_bypos(){
    if(start == NULL)printf("\n\tUnderFlow\n");
    else {
        int c, pos;
        display_list();
        printf("\n\tEnter Position of Data to be Deleted: ");
        scanf("%d",&pos);
        if(pos>0 && pos<=item){
            if(pos==1)delete_first();
            else if(pos==item)delete_last();
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
                item--;
                printf("\n\tNode Deleted from the %d th Position\n",pos);
            }
        }
    else printf("\n\t* Invalid Position\n");
    }
}


int main(){
    int c;
    do{
        printf("\n\t****** Perform Operations on Circular Linked List ******\n");
        printf("\t\t1. Traverse Circular Linked List\n");
        printf("\t\t2. Insert a Node in Linked List\n");
        printf("\t\t3. Delete a Node from Linked List\n");
        printf("\t\t0. Exit\n");
        printf("\n\t\t\t>>> ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            display_list();
            break;
        case 2:
            insert_bypos();
            break;
        case 3:
            delete_bypos();
            break;
        default:
            if(c!=0)printf("\n\t* Invalid Choice\n");
            break;
        }
    } while(c);
   return 0;
} 
