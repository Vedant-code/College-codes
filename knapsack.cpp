// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
float capacity;
float knapsack_p(float p[], float w[], int n);
float knapsack_w(float p[], float w[], int n);
float knapsack_pw(float p[], float w[], int n);
int main() {
    // Write C++ code here
    int n;
    float a, b, c;
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
    a=knapsack_p(p, w, n);
    b=knapsack_w(p, w, n);
    c=knapsack_pw(p, w, n);
    float greatest = a > b ? (a > c ? a : c) : (b > c ? b : c) ;
    cout<<"The maximum profit we get is "<<greatest;
    return 0;
}

float knapsack_p(float p[], float w[], int n){
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
    
    return tp;
    
}

float knapsack_w(float p[], float w[], int n){
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
    
    return tp;
}
float knapsack_pw(float p[], float w[], int n){
    int i, j;
    float u, x[10], tp=0.0, temp, pw[10];
    for(i=0;i<n;i++)
{
    x[i]=0.0;
    pw[i]=p[i]/w[i];
}
    u=capacity;
    for(i=0;i<n;i++){
        for(j=i+1;j<n;j++){
            if(pw[i]>pw[j]){
                temp=p[j];
                p[j]=p[i];
                p[i]=temp;
                temp=w[j];
                w[j]=w[i];
                w[i]=temp;
                temp=pw[j];
                pw[j]=pw[i];
                pw[i]=temp;
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
    
    return tp;
    
}
