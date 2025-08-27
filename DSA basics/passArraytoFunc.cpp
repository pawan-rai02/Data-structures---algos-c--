#include<iostream>
using namespace std;
//arrays are always passed by address.
//  void array(int *A, int n){
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         cout<<A[i]<<", ";
//     }
    
//  }
//    int main(){ 
//     int n;
//     int A[100];

//     cin>>n;
//     cout<<"enter array elements"<<endl;
//     for (int i = 0; i < n; i++)
//     {
//         /* code */
//         cin>>A[i];
//     }
//     //array(A,n);
    
//     return 0;
// }
#include<iostream>
using namespace std;
int * func(int size){
    int *p;
    p=new int[size];
    for (int i = 0; i < size; i++)
    {
        /* code */
        cout<<"enter array at "<<i+1<<" index";
        cin>>p[i];
    }
    return p;
    }
 void array(int *A, int n){
    for (int i = 0; i < n; i++)
    {
        /* code */
        cout<<A[i]<<", ";
    }
}
   int main(){ 
    int size=6;
    int *ptr=func(size);
    array(ptr,size);
    return 0;
}