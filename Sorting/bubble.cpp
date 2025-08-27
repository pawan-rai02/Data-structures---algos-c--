#include<iostream>
using namespace std;


void Swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}


void BubbleSort(int A[], int n){
    int flag;
    for(int i=0;i<n-1;i++){
        flag=0;
        for(int j=0;j<n-1-i;j++){
            if(A[j]>A[j+1]) {
                Swap(&A[j], &A[j+1]);
                flag=1;
                }
        }if(flag==0) break;
    }
}


   int main(){ 
    int A[]={100, 12, 45, 56, 64, 554};
    int n=6;
    BubbleSort(A,n);
    for(int x:A) cout<<x<<" ";
    return 0;
}