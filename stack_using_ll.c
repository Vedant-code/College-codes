/*
#include <stdio.h>
struct abc
{
  int data;
  struct abc * next;
}
struct abc *top=NULL;
int isempty();
int isfull();
void show(struct abc*)
void push(int );
void pop();

int main(void) {
  
  return 0;
}

int isempty()
{
  if(top==NULL){
    return 1;
  }
  else{
    return 0;
  }
}
int isfull()
{
  struct abc *temp;
  temp=(struct abc*)malloc(sizeof(struct abc));
  if(temp==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

struct abc* push(int x){
  if(isfull){
    printf("can't inset stack is full");
  }
  else{
    struct abc *temp;
     temp=(struct abc*)malloc(sizeof(struct abc));
     temp->data=x;
     temp->next=top;
     top=temp;
     printf("inserted");
  }
  return top;
}

void show(struct abc* top)[
  struct abc* p;
  p=top;
  while(p->next!=NULL){
    printf("\n%d", p->data);
    p=p->next;
  }
]

*/



#include <stdio.h>
#include <stdlib.h>
struct abc
{
  int data;
  struct abc * next;
};
struct abc *top=NULL;
int isempty();
int isfull();
void show(struct abc*);
struct abc* push(int );
void pop();

int main(void) {
  push(40);
  push(30);
  push(20);
  show(top);
  pop(40);
  printf("\nAfter popping");
  show(top);

  return 0;
}

int isempty()
{
  if(top==NULL){
    return 1;
  }
  else{
    return 0;
  }
}
int isfull()
{
  struct abc *temp;
  temp=(struct abc*)malloc(sizeof(struct abc));
  if(temp==NULL){
    return 1;
  }
  else{
    return 0;
  }
}

struct abc* push(int x){
  if(isfull()){
    printf("can't inset stack is full");
  }
  else{
    struct abc *temp;
     temp=(struct abc*)malloc(sizeof(struct abc));
     temp->data=x;
     temp->next=top;
     top=temp;
     printf("\ninserted");
  }
  return top;
}

void show(struct abc* top){
struct abc * p;
  p=top;
  while(p!=NULL){
    printf("\n%d", p->data);
    p=p->next;
  }
}
  
void pop(){
 if(isempty()){
   printf("Stack is already empty");
 }
 else{
   struct abc * p;
  p=top;
  top=top->next;
  free(p);
 }
}
