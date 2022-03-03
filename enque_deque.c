#include <stdio.h>
#include<stdlib.h>


struct abc{
    struct abc*next;
    int data;
    
};
struct abc*front = NULL;
struct abc*rear = NULL;
void enque(int n){
    struct abc*temp;
    temp= (struct abc*)malloc(sizeof(struct abc));
    if(rear==NULL){
        rear= (struct abc*)malloc(sizeof(struct abc));
        rear->data=n;
        rear->next=NULL;
        front=rear;
    }
    else{
        temp->data=n;
        temp->next=NULL;
        rear->next=temp;
        rear=temp;
    }
}

void deque(){
    if(front==NULL) printf("The queue is empty\n");
    else{
        struct abc*temp=front;
        printf("%d is deleted\n", temp->data );
        front=front->next;
        free(temp);
    }
}
void display(){
    
    while(front!=NULL){
        printf("%d ", front->data);
        front=front->next;
    }
    
}

int main()
{
    enque(10);
    enque(20);
    enque(30);
    
    
    deque(10);
    display();

    return 0;
}
