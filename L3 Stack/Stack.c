#include<stdio.h>
#define top 5

int stack[top], item = 0, data;

void pop(){
    if(item>0){
        item--;
        data = stack[item];
        printf("\t%d Poped Succesfully\n",data);
    }
    else {
        printf("\tStack UnderFlow\n");
    }
}

void display_Stack(){
    int i;
    printf("\n\tElements of Stack: \n");
    if(item>0){
        for(i = item; i > 0; i--){
            printf("\t\t[%d] %d \n",i,stack[i-1]);
        }
        printf("\n");
    }
    else printf("\n\tUnderFlow\n");
}

void push(){
    int num;
    if(item < top){
        printf("\n\tEnter the Element to be Pushed into Stack : ");
        scanf("%d",&num);
        stack[item] = num;
        item++;
        printf("\t%d Pushed Successfully\n", num);
    }
    else {
        printf("\n\tstack OverFlow\n");
    }
    display_Stack();
}



int main(){
    int n, i, c;
    printf("\t**** Welcome to Stack Program ****\n");
    printf("\tEnter No. of Element To Be Pushed : ");
    scanf("%d",&n);
    for(i = 0; i<n; i++){
        if(i<top){
            printf("\t\tEnter Element [%d] : ", i+1);
            scanf("%d",&stack[i]);
            item++;
        }
        else {
            printf("\n\tStack OverFlow\n");
            break;
        }
    }
    printf("\n");
    display_Stack();
    do{
        printf("\n\t****** Perform Operations on Stack ******\n");
        printf("\t\t1. Traverse Stack\n");
        printf("\t\t2. Push Element into Stack\n");
        printf("\t\t3. Pop Element from Stack\n");
        printf("\t\t0. Exit\n");
        printf("\n\t\t\t>>> ");
        scanf("%d",&c);
        switch (c)
        {
        case 1:
            display_Stack();
            break;
        case 2:
            push();
            break;
        case 3:
            pop();
            break;
        default:
            if(c!=0)printf("\tInvalid Choice\n");
            break;
        }
    } while(c);
    return 0;
}