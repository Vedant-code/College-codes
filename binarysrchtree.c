#include <stdio.h>
#include <stdlib.h>

struct abc
{
    int data;
    struct abc *left, *right;
};

struct abc *insert(struct abc *, int);
struct abc *create(int);
int bst(struct abc *, int);

void inorder(struct abc *);
void preorder(struct abc *);
void postorder(struct abc *);

void inorder(struct abc *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    printf("%d\t", root->data);
    inorder(root->right);
}

void preorder(struct abc *root)
{
    if (root == NULL)
        return;
    printf("%d\t", root->data);
    preorder(root->left);

    preorder(root->right);
}

void postorder(struct abc *root)
{
    if (root == NULL)
        return;
    postorder(root->left);

    postorder(root->right);
    printf("%d\t", root->data);
}

struct abc *create(int d)
{
    struct abc *temp;
    temp = (struct abc *)malloc(sizeof(abc));
    temp->data = d;
    temp->left = NULL;
    temp->right = NULL;
}

int main()
{
    struct abc *root;
    root = insert(root, 45);
    root = insert(root, 15);
    root = insert(root, 79);
    root = insert(root, 90);
    root = insert(root, 10);
    root = insert(root, 55);
    root = insert(root, 12);
    root = insert(root, 20);
    root = insert(root, 50);

    printf("Inorder: ");
    inorder(root);
    printf("\nPreorder: ");
    preorder(root);
    printf("\nPostorder: ");
    postorder(root);
    bst(root, 8);
    return 0;
}

struct abc *insert(struct abc *root, int d)
{
    if (root == NULL)
    {
        root = create(d);
    }
    else if (root->data > d)
    {
        root->left = insert(root->left, d);
    }
    else
        root->right = insert(root->right, d);
    return root;
}

int bst(struct abc *root, int key){
if(root==NULL){printf("\nKey not found");}
if(root->data==key){ printf("\nKey is present in bt : %d", root->data); return 0;}
else if(root->data<key) bst(root->right, key);
else bst(root->left, key);

}
