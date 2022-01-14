/*Implement stack as an abstract data type using linked list and use this ADT for conversion of infix
expression to postfix, prefix, and evaluation of postfix and prefix expression.

Stack has basic operations
1. Push - insert
2.Pop - delete
3. pick
Last in first out concept follow -> Stack
LIFO

|_|
|1| <- top
push (3)
top++
push (20)
top++
push (40)
|40|
|20|
| 3|
| 1|
 We makeke 3 function


 int satck[100], top=0;

 void push();
 void pop();
 void pick();




int main(void) {
   int ch, y;
   do{
     printf(enter chsoice 1, 2, 3)
     scanf ch
     switch(ch):
     case 1: printf (enter for push)
             scanf(p)
             push(p, top++);
             break;
    caase 2:
    pop();
    break;
    case 3:show()
    break;
    default:
    printf()
   }
  return 0;
}

void push(int p, int top){
  stack [top]=p
  top++;
}

void pop(){
  if(top<=-1){
    printf("underflow")
  }
  else{
    top=top-1;
    printf("done";)
  }
}

void show(){
  for(int i=top-1; i>0; i--){
    printf(%d, stack[i]); 
  }
}

*/

#include <stdio.h>
int stack[100],i, p, top=0;
void push(void);
 void pop(void);
 void pick(void);
 void show(void);
int main(void) {
   int ch,p, y;
   printf("Enter choice for 1.PUSH 2.POP 3.Show 4.End\n");
   do
    {
        printf("\n Enter the Choice:");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
        {
            push();
            break;
        }
        case 2:
        {
            pop();
            break;
        }
        case 3:
        {
            show();
            break;
        }
        case 4:
        {
            printf("\n\t End");
            break;
        }
        default:
        {
            printf("\n\t Please Enter a Valid Choice(1/2/3/4)");
        }
        }
    } while (ch != 4);
  return 0;
}

void push(){
  printf ("enter for push:");
      scanf("%d\n", &p);
  stack [top]= p;
  top++;
}

void pop(){
  if(top<=-1){
    printf("underflow");
  }
  else{
    top=top-1;
    printf("done");
  }
}

void show(){
  for(int i=top-1; i>0; i--){
    printf("%d", stack[i]); 
  }
}
