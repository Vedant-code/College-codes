/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;

struct node{
    int data;
    struct node *left, *right;
    
};

node* newNode(int data){
    node* temp=new node;
    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

void printInorder(struct node* a ){
    if(a==NULL) return;
    printInorder(a->left);
    cout<<a->data<<" ";
    printInorder(a->right);
}

void printPreorder(struct node* a){
    if(a==NULL) return;
    cout<<a->data<<" ";
    printPreorder(a->left);
    printPreorder(a->right);
}

void printPostorder(struct node* a){
    if(a==NULL) return;
    
    printPostorder(a->left);
    printPostorder(a->right);
    cout<<a->data<<" ";
}




int main()
{
    struct node* root=newNode(1);
    root->left=newNode(2);
    root->right=newNode(3);
    root->left->left=newNode(4);
    root->left->right=newNode(5);
    
    
    cout<<"Inorder traversal \n";printInorder(root);
    cout<<"\nPreorder traversal\n";printPreorder(root);
    cout<<"\nPostorder traversal\n";printPostorder(root);

    return 0;
}
