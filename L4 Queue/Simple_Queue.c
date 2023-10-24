// Enqueue & Dequeue in Simple Queue

#include<stdio.h>
#define size 5

int queue[size], data, front = -1, rear = -1;


void display_Queue(){
    int i;
    if(front > -1){
        printf("\n\tElements of Queue: \n\t\t");
        for(i = front; i <= rear; i++){
            printf("  %d  ",queue[i]);
            if(i != rear)printf("<<<");
        }
        printf("\n");
    }
    else printf("\n\tUnderFlow\n");
}

void dequeue(){
    if(front == rear && rear > -1){
        data = queue[front];
        rear = -1;
        front = -1;
        printf("\t%d Dequeued Successfully\n", data);
    }
    else if(front <= rear && rear > -1){
        data = queue[front];
        front++;
        printf("\t%d Dequeued Successfully\n", data);
    }
    else {
        printf("\tQueue UnderFlow\n");
    }
}

void enqueue(){
    int num;
    if(front == rear && rear == -1){
        printf("\n\tEnter the Element to Enqueue : ");
        scanf("%d",&num);
        rear++;
        front++;
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
    else {
        printf("\n\tQueue OverFlow\n");
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
