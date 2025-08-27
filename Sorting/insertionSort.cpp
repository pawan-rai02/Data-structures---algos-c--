#include<iostream>
using namespace std;


void InsertionSort(int A[], int n){
    for(int i=1;i<n;i++){
        int j=i-1;
        int x=A[i];
        while(j>=0 && A[j]>x){
            A[j+1]=A[j];
            j--;
        }
        A[j+1]=x;
    }
}
   int main(){ 
    int A[]={2, 4, 7, 1, 8, 102, 220, 111, 100};
    InsertionSort(A, 9);
    for(int i: A) cout<<i<<" ";
    return 0;
}