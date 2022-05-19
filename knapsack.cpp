// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
float capacity;
void knapsack_p(float p[], float w[], int n);
void knapsack_w(float p[], float w[], int n);
int main() {
    // Write C++ code here
    int n;
    float p[10], w[10];
    cout<<"\nEnter n:";
    cin>>n;
    cout<<"\nEnter profit array:";
    for(int i=0;i<n;i++){
        cin>>p[i];
    }
    cout<<"\nEnter weight array:";
    for(int i=0;i<n;i++){
        cin>>w[i];
    }
    cout<<"\nEnter capacity : ";
    cin>>capacity;
    knapsack_p(p, w, n);
    knapsack_w(p, w, n);
    return 0;
}

void knapsack_p(float p[], float w[], int n){
    int i, j;
    float u, x[10], tp=0.0, temp;
    for(i=0;i<n;i++)
{
    x[i]=0.0;
}
    u=capacity;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(p[i]<p[j]){
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
            }
        }
    }
        for(i=0;i<n;i++){
            if(w[i]>u) break;
            else{
                x[i]=1;
                tp=tp+p[i];
                u=u-w[i];
            }
        }
        if(i<n){
            x[i]=u/w[i];
            p[i]=p[i]*x[i];
            tp=tp+p[i];
        }
    
    cout<<"Total profit based on individual profit:"<<tp;
    
}

void knapsack_w(float p[], float w[], int n){
    int i, j;
    float u, x[10], tp=0.0, temp;
    for(i=0;i<n;i++)
{
    x[i]=0.0;
}
    u=capacity;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(w[i]>w[j]){
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
            }
        }
    }
        for(i=0;i<n;i++){
            if(w[i]>u) break;
            else{
                x[i]=1;
                tp=tp+p[i];
                u=u-w[i];
            }
        }
        if(i<n){
            x[i]=u/w[i];
            p[i]=p[i]*x[i];
            tp=tp+p[i];
        }
    
    cout<<"\nTotal profit based on weight:"<<tp;
}
