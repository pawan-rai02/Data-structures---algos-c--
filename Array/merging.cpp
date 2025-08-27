#include<iostream>
using namespace std;

   int main(){
    int A[6], B[6], C[12]; 
    cout<<"enter elements of array 1"<<endl;
    for (int i = 0; i < 6; i++)
    {
        cin>>A[i];
    }
    cout<<"enter elements of array 2"<<endl;
        for (int i = 0; i < 6; i++)
    {
        cin>>B[i];
    }
    cout<<"first array is"<<endl;
    for(int i: A){
        cout<<i<<" ";
    }
    cout<<"second array is"<<endl;
    for(int i: B){
        cout<<i<<" ";
    }
    for(int i=0;i<6;i++){
        C[i]=A[i];
    }
    for (int i = 0; i < 6;i++)
    {int key = B[i];
        for(int j=0;j<6;j++){
           if (key == B[j])
                break;
           else
                C[i+6]=key;

        }
    }
    cout<<"3rd arry"<<endl;
    for(int i:C)
    cout<<i<<" ";
    return 0;
}