/*Department of Information Technology has a student's club named 'Pinnacle Club'. Students of the
Second, third and final year of the department can be granted membership on request. Similarly,
one may cancel the membership of the club. The first node is reserved for the president of the club
and the last node is reserved for the secretary of the club. Write C program to maintain club
member’s information using a singly linked list. Store student PRN and Name. Write functions to
a) Add and delete
b) Compute the total number of members of the club
c) Display members of the club
Display list in reverse order using recursion
________________________________________________________
                             Name|PRN|Roll no.|Address
1st node store inf o of president abc |250|2
We have 4- 5 members intermidiate nodes
last node of secretary
Create 1st singlelink list
Perform-
 1.Add members2.Delete 3.Reverse

struct node{
  int prn, roolno;
  char name[20];
  struct node *next
}

int main(){

   //menu driven program in do while lop

   int a(choice);
  //Create
  void creat()// func to create linked list
  {
    int p, r;//p=prn, r=roll, n=name
    char n[20]
    struct node *head
    head=(struct node*)malloc(sizeof(struct node))
    Input rolno, prn, name of president of a club
    head->prn=p
    head->roolno=r
    strcpy(head->name,n)
    head->next=NULL
    

  }

}

void add(){
  create a a node and connect to previous node
  sruct node*temp, *q;
  int p, r;//p=prn, r=roll, n=name
    char n[20]
    for(i=0,iN,;i++){
      temp=(struct node*)malloc(sizeof(struct node))
      Input name rooll, prn;
    temp->prn=p
    temp->roolno=r
    strcpy(temp->name,n)
    //newly created node ko head mew dalna hai
    
    haed abc|2112|64|NULL
       temp adrs 80
    temp xyz|112|32|Null
    
    to connect write head next me temp node ka address likhna hai

    haed abc|2112|64|80
    temp will become head now and connect it to new temp

   **save the head node in a pointer 

    q->next=temp;
    q=temp;
    
    }
}

void diplay(){
   while(head!=Null){
     print ("%d%d%s",head->prn, head->rollno, head->name)
     
     head=head->next
   }

}
//secretary node should be T END
void addS(struct node*head){
  struct node* new;
  new=(struct node*)malloc(sizeof(struct node))
  Input name rooll, prn;
  new->prn=p
  new->roolno=r
  strcpy(new->name,n)
  new->next=NULL
  while(head!=Null && head->next!=NULL){
    head=head->next;
  }
  head->next=new
} 

case 7:
Enter prn member to be deleted:prn1
scanf(head->next)
deletem(prn1, head)

void deletem(struct node*head, int prn1){
  struct node* q;
  while(head->prn!=prn1){
   q=head;
   head=head->next

  }
  q->next=head->next
  free(head);
}


*/




#include <stdio.h>
#include<stdlib.h>
#include<string.h>

struct node* create();
void add(int m, struct node*head );
void display(struct node*head);
void addS(struct node*);
struct node* delete(struct node*);
struct node* deleteS(struct node* head);


struct node{
  int prn, rollno;
  char name[20];
  struct node *next;
};

int main(void) {
  int a, m;
  struct node* head;
  char ch;
  

  do{
    printf("Enter your choice for 1.create\n2.Add members \n3.Delete president \n4.add secretary\n5.Delete secretary\n6.Display\n7.End\nOption:-");
  scanf("%d", &a);
    switch(a){ 
    case 1:{
      head=create();
      
      break;
    } 
    case 2:{
      
      printf("\nEnter the number of memebers:");
      scanf("%d", &m);
      add(m, head);
      break;
    }

    case 3:{
      printf("Club members without president\n");
      head=delete(head);
      display(head);
      break;
    }
    case 4:{
      addS(head);
      break;
    }
    case 5:{
      printf("\nClub members without secretary\n");
      deleteS(head);
      display(head);
      break;
    }
    case 6:{
      display(head);
      break;
    }
    default:{
      printf("End");
    }
    }
    
  }while(a!=7);
  return 0;
}
 
struct node* create(){
  int p, r;
  char n[20];
  struct node *head;
    head=(struct node*)malloc(sizeof(struct node));
    printf("\nEnter the prn, roll no and name of the club's president:");
    scanf("%d %d ", &p, &r);
    scanf("%s", n);
    head->prn=p;
    head->rollno=r;
    strcpy(head->name,n);
    head->next=NULL;
    return head;
}

void add(int m, struct node *head)
{
 struct node *temp, *q;
 int p, r;
 char n[30];
 q=head;
 for(int i=0;i<m;i++)
 {
   temp=(struct node*)malloc(sizeof(struct node));
   printf("\nEnter PRN, RollNo., name of member of the club:\n");
   scanf("%d%d",&p,&r);
   scanf("%s",n);
   temp->prn=p;
   temp->rollno=r;
   strcpy(temp->name, n);
   q->next=temp;
   q=temp;
 }
}

void display(struct node* head){
  
   while(head!=NULL){
     printf("%d\t%d\t%s",head->prn, head->rollno, head->name);
     
     head=head->next;
     printf("\n");
   }
}

void addS(struct node*head){
  struct node* new;
  int p, r;
  char n[20];
  new=(struct node*)malloc(sizeof(struct node));
  printf("\nEnter the prn , roll no, name of secretary\n");
  scanf("%d", &new->prn);
  scanf("%d", &new->rollno);
  scanf("%s", n);
  strcpy(new->name, n);
  new->next=NULL;
  while(head!=NULL && head->next!=NULL){
    head=head->next;
  }
  head->next=new;
}

struct node* delete(struct node*head){
  struct node* p;
  p=head->next;
  free(head);
  return p;

}

struct node* deleteS(struct node* head){
  struct node* prv;

  while(head!=NULL && head->next!=NULL){
    prv=head;
    head=head->next;

  }
  prv->next=NULL;
  free(head);
  return head;
}
