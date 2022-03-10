#include <stdio.h>
#include <stdlib.h>

struct abc
{
   int data;
   struct abc *left, *right;
};

struct abc* create(int);
void inorder(struct abc*);
void preorder(struct abc*);
void postorder(struct abc*);
struct abc* create(int d)
{
  struct abc *temp;
  temp=(struct abc*)malloc(sizeof(struct abc));
  temp->data=d;
  temp->left=NULL;
  temp->right=NULL;
  return temp;
}

void inorder(struct abc* root)
{
    if(root==NULL)
    return;
    
    inorder(root->left);
    printf("%d", root->data);
    inorder(root->right);
}

void preorder(struct abc* root)
{
    if(root==NULL)
    return;
    
    
    printf("%d", root->data);
preorder(root->left);
preorder(root->right);
}

void postorder(struct abc* root)
{
    if(root==NULL)
    return;
    postorder(root->left);
postorder(root->right);

    
    printf("%d", root->data);
}




int main()
{
  struct abc *root;
  root=create(1);
  root->left=create(2);
  root->right=create(3);
  root->left->left=create(4);
  root->left->right=create(5);
  printf("Inorder:"); 
  inorder(root);
  printf("\n");
  printf("Preorder:"); 
  preorder(root);
 printf("\n");
  printf("Postorder:"); 
  postorder(root);
printf("\n");
return 0;
    
}
