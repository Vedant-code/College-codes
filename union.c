#include<stdio.h>
#include<stdlib.h>
void unionofarray(int a[], int n, int b[], int m);
void intersection(int a[], int n, int b[], int m);
void differenceA(int a[], int n, int b[], int m);
void differenceB(int a[], int n, int b[], int m);
void symmetricdiff(int a[], int n, int b[], int m);


int main(){
  int a[50], b[50];
  int i, j, n, m, k;
  printf("Enter the size of array a:");
  scanf("%d", &n);
  printf("Enter the elements of array a:");
  for(i=0; i<n; i++)
  {
    scanf("%d", &a[i]);
  }
  printf("Enter the size of array b:");
  scanf("%d", &m);
  printf("Enter the elements of array b:");
  for(j=0; j<m; j++)
  {
    scanf("%d", &b[j]);
  }
  printf("Array a[]:{");
  for(i=0; i<n; i++)
  {
    printf("%d ", a[i]);
  };printf("}");

  printf("\nArray b[]:{");
  for(j=0; j<m; j++)
  {
    printf("%d ", b[j]);
  };printf("}");
  while(n>0 && m>0){
  printf("\n\n1.Union\n2.Intersection\n3.DifferenceA-B\n4.DifferenceB-A\n5.Symmetric difference\n6.Exit\n");
  scanf("%d", &k);
  if (k == 6){
    printf("Program  ended");
  break;}
    switch(k){
      case(1):printf("\nUnion of arrays\n");
        unionofarray(a, n, b, m);
        break;
        case(2):printf("\nIntersection of arrays\n{");
        intersection(a, n, b, m);
        printf("}");
        break;
        
        case(3):printf("\nDifference\na-b:{");
        differenceA(a, n, b, m);
        printf("}");
        break;
        case(4):printf("\nDifference\nb-a:{");
        differenceA(b, m, a, n);
        printf("}");
        break;
        case(5):symmetricdiff(a, n, b, m);
        break;
        default:printf("Invalid input");
        break;
    }
  }
  
  return 0;
}

void unionofarray(int a[], int n, int b[], int m)
{
  int i, j, flag;
  printf("{");
  for(i = 0;i < n;i++){
printf("%d, ",a[i]);}
for(i = 0;i < m;i++)
{
for(j = 0;j < n;j++)
{
if(b[i] == a[j])
{
flag = 1;
}
}
if(flag == 0)
{
printf("%d, ",b[i]);
}
flag = 0;
}
printf("}");
}

void intersection(int a[], int n, int b[], int m)
{
  int i, j, flag;
  for(i = 0;i < n;i++)
{
for(j = 0;j < m;j++)
{
if(b[i] == a[j])
{
flag = 1;
}
}
if(flag == 1)
{
printf("%d ", b[i]);
}
flag = 0;
}
}

void differenceA(int a[], int n, int b[], int m)
{
  int i, j, flag=1, k=0;
  int c[k];
  for (i=0; i<n; i++){
    flag=0;
    for(j=0; j<m; j++){
      if(a[i]==b[j]){
        flag=1;
        break;
      }
    }
    if(flag==0){
      c[k]=a[i];
      k++;
    }
  }
  for(i=0; i<k; i++){
    printf("%d", c[i]);
  }
}

void symmetricdiff(int a[], int n, int b[], int m)
{
 int k=0;
 int i, j, flag;
 int d[k];

 for(i=0;i<n;i++)
 {
 flag=0;
 for(j=0;j<m;j++)
 {
 if(a[i]==b[j])
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 d[k]=a[i];
 k++;
 }
 }
 for(i=0;i<m;i++)
 {
 flag=0;
 for(j=0;j<n;j++)
 {
 if(b[i]==a[j])
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 d[k]=b[i];
 k++;
 }
 }
 
 printf("\n(A-B)U(B-A):{");
 for(i=0;i<k;i++)
 {
 printf("%d ",d[i]);

 }
 printf("}");
}

void differenceB(int a[], int n, int b[], int m)
{
  int i, j, flag;
  int k=0;
  int d[k];
  for(i=0;i<m;i++)
 {
 flag=0;
 for(j=0;j<n;j++)
 {
 if(b[i]==a[j])
 {
 flag=1;
 break;
 }
 }
 if(flag==0)
 {
 d[k]=b[i];
 k++;
 }
 }
 for(i=0; i<k; i++){
   printf("%d ", d[i]);
 }
}
