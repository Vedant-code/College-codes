/*Implement a sparse matrix with operations like initialize empty sparse matrix, insert an element, add two matrices, transpose a matrix*/
#include <stdio.h>
#include<stdlib.h>

void sparsematrix( int r, int c,int a[r][c]);
void input_matrix(int r, int c, int a[r][c]);
void transpose(int a[][3], int b[][3]);
void readsparse(int a[][3]);
void add(int a[][3], int b[][3], int d[][3]);
int main()
{
    int r1, c1, r2, c2;
    int A[3][20];
    int t=0;
    printf("Enter array rows and columns for matrix A:");
    scanf("%d %d", &r1, &c1);
    int a[r1][c1];
    input_matrix(r1, c1, a);
    printf("\nEnter array rows and columns for matrix B:");
    scanf("%d %d", &r2, &c2);
    int b[r2][c2];
    input_matrix(r2, c2, b);
    int option;
    while(r1>0 && c1>0 && r2>0 && c2>0){
      printf("\n1.Print sparse matrix of A\n2.Print sparse matrix of B\n3.insert an element\n4.add two matrices\n5.transpose of matrixA\n6.Exit\nOption: ");
    scanf("%d", &option);
    if(option==6){
      printf("program ended");
    }
    else{
    switch(option){
      case 1:{printf("\n___________");
        sparsematrix(r1, c1, a);
        printf("\n___________");
        break;
      }
    case 2:{printf("\n___________");
        sparsematrix(r2, c2, b);
        printf("\n___________");
        break;}
    case 3:{
      break;
    }
  case 4:
    {
    int r1, c1, v1, r2, c2, v2;
    int a[20][3], b[20][3], d[20][3];
    readsparse(a);
    printf("\n_________________________\n");

    readsparse(b);
    add(a, b, d);
    printf("__________________________________");
    int t=d[0][2];
    printf("\nRow Col Value");
    for(int i=1;i<t;i++){
    printf("\n%d\t%d\t%d", d[i][0], d[i][1], d[i][2]);
    }
      break;
  }
    case 5:{
      int a[20][3], b[20][3];
      readsparse(a);
      transpose(a, b);
      int t= b[0][2];
      printf("Transpose of matrix A :");
      printf("\nRow Col Value");
      for(int i=0;i<=t;i++){
    printf("\n%d\t%d\t%d", b[i][0], b[i][1], b[i][2]);
    }

      break;
    }
    default:{
      printf("Invalid option");
    }
    }
    }
    }
    return 0;
}

void input_matrix(int r, int c, int a[r][c]){

  int i, j;
  printf("Enter the elemnts:\n");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            scanf("%d", &a[i][j]);
        }
    }
}

void sparsematrix( int r, int c,int a[r][c]){
  int i, j;
printf("\nR\t");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(a[i][j]!=0){
                printf("%d ", i);
            }
        }
    }
    printf("\nC\t");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(a[i][j]!=0){
                printf("%d ", j);
            }
        }
    }
    
    printf("\nV\t");
    for(i=0; i<r; i++){
        for(j=0; j<c; j++){
            if(a[i][j]!=0){
                printf("%d ", a[i][j]);
            }
        }
    }
}

void readsparse(int a[][3]){
  int r1, c1, v1;
  printf("Enter the above tripletA row column and value :\n");
    scanf("%d %d %d", &r1, &c1, &v1);
    a[0][0]=r1;
    a[0][1]=c1;
    a[0][2]=v1;

    for(int i=1;i<=v1; i++){
    printf("Enter the triples<row, column, value>:");
    scanf("%d%d%d", &a[i][0], &a[i][1], &a[i][2]);
    }
}
 void transpose(int a[][3], int b[][3]){
  int i,j,k,n;
b[0][0]=a[0][1];
b[0][1]=a[0][0];
b[0][2]=a[0][2];
k=1;
n=a[0][2];
for(i=0;i<a[0][1];i++){
  for(j=1;j<=n;j++){
    if(i==a[j][1])
    {
      b[k][0]=i;
      b[k][1]=a[j][0];
      b[k][2]=a[j][2];
      k++;
    }
  }
}

}

void add(int a[][3], int b[][3], int d[][3]){
 int t1, t2, i, j, k;
    if(a[0][0]!=b[0][0] || a[0][1]!=b[0][1]){
    printf("\nYou have entered invalid matrix!! Size must be equal");
     exit(0);
   }
    t1= a[0][2];
    t2= b[0][2];
    i=j=k=0;
    d[0][0]=a[0][0];
    d[0][1]=a[0][1];
  
    while(i<=t1 && j<=t2){
    if(a[i][0]<b[i][0]){
    d[k][0]=a[i][0];
    d[k][1]=a[0][1];
    d[k][2]=a[i][2];
    k++;
    i++;
    }
    else if(b[j][0]<a[i][0]){
    d[k][0]=b[j][0];
    d[k][1]=b[j][1];
    d[k][2]=b[j][2];
    k++;
    j++;
    }
    else if(b[j][1]<a[i][1]){
    d[k][0]=b[j][0];
    d[k][1]=b[j][1];
    d[k][2]=b[j][2];
    k++;
    j++;
    }
    else {
    d[k][0]=a[i][0];
    d[k][1]=a[i][0];
    d[k][2]= a[i][2]+b[j][2];
    k++;
    i++;
    j++;
    }
    }
    while (i<=t1){
    d[k][0]=a[i][0];
    d[k][1]=a[0][1];
    d[k][2]=a[i][2];
    k++;
    i++;
   }
   while(j<=t2){
   d[k][0]=b[j][0];
    d[k][1]=b[j][1];
    d[k][2]=b[j][2];
    k++;
    j++;

   }
    d[0][2]=k-1;
}
