#include<iostream>
using namespace std;


void SelectionSort(int A[], int n){
    int i,j,k;
    for(i=0;i<n-1;i++){
        for(j=k=i;j<n;j++){
            if(A[j]<A[k])  k=j;
        }
        swap(A[i], A[k]);
    }
}


   int main(){ 
    int A[]={2, 19, 22, 332, 228, 2292, 288};
    SelectionSort(A, 7);

    for(int i: A)   cout<<i<<" ";
    return 0;
}