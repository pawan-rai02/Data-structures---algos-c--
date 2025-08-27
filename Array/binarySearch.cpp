#include<iostream>
using namespace std;
int Binary(int *arr,int key,int size){
    int low=0;
    int high=size-1;
    while (low<=high)
    {
    int mid =(high+low)/2;
    if(arr[mid]<key)
    low=mid+1;
    else if (arr[mid]>key)
    {
        high=mid-1;
    }
    else 
    {
        return mid;
    }
    
    }
    return -1;
}
   int main(){ 
    int A[6]={2,10,5,6,6,7};
    int size=sizeof(A)/sizeof(A[0]);
    cout<<Binary(A,10,size);
    return 0;
}