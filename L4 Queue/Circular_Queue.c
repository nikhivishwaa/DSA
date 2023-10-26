// Enqueue & Dequeue in Circular Queue

#include<stdio.h>
#define size 5

int queue[size], data, front = -1, rear = -1;


void display_Queue(){
    int i;
    if(front > -1){
        printf("\n\tElements of Queue: \n\t\t");
        for(i = front; i < size; i++){
            printf("  %d  ",queue[i]);
            if(i != rear)printf("<<<");
            else break;
        }
        if(front > rear){
            for(i = 0; i <= rear; i++){
                printf("  %d  ",queue[i]);
                if(i != rear)printf("<<<");
        }
        printf("\n");
        }
    }
    else printf("\n\tUnderFlow\n");
}

void dequeue(){
    if(front > -1){
        if(front == rear){
            data = queue[front];
            rear = -1;
            front = -1;
            printf("\t%d Dequeued Successfully\n", data);
        }
        else if(front < size && rear > front){
                data = queue[front];
                front++;
                printf("\t%d Dequeued Successfully\n", data);
            }
        else if(front < size && rear < front){
                data = queue[front];
                if(front == size - 1)front = 0;
                else front++;
                printf("\t%d Dequeued Successfully\n", data);
            }
        }
    else {
        printf("\tQueue UnderFlow\n");
    }
}

void enqueue(){
    int num;
    if(rear > -1 && (rear == front - 1 || (front == 0 && rear == size - 1))){
        printf("\n\tQueue OverFlow\n");
    }
    else {
        if(front == rear && rear == -1){
            printf("\n\tEnter the Element to Enqueue : ");
            scanf("%d",&num);
            rear++;
            front++;
            queue[rear] = num;
            printf("\t%d Enqueued Successfully\n", num);
        }
        else if(rear == size - 1){
            printf("\n\tEnter the Element to Enqueue : ");
            scanf("%d",&num);
            rear = 0;
            queue[rear] = num;
            printf("\t%d Enqueued Successfully\n", num);
        }
        else if(rear < size - 1){
            printf("\n\tEnter the Element to Enqueue : ");
            scanf("%d",&num);
            rear++;
            queue[rear] = num;
            printf("\t%d Enqueued Successfully\n", num);
        }
    }
    display_Queue();
}



int main(){
    int c;
    do{
        printf("\n\t****** Perform Operations on Queue ******\n");
        printf("\t\t1. Traverse Queue\n");
        printf("\t\t2. Enqueue the Element\n");
        printf("\t\t3. Dequeue the Element\n");
        printf("\t\t0. Exit\n");
        printf("\n\t\t\t>>> ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            display_Queue();
            break;
        case 2:
            enqueue();
            break;
        case 3:
            dequeue();
            break;
        default:
            if(c!=0)printf("\tInvalid Choice\n");
            break;
        }
    } while(c);
    return 0;
}