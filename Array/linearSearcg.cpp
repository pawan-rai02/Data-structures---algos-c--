#include<iostream>
using namespace std;
struct Array{
    int A[20];
    int length;
}arr;
int Linears(struct Array *arr, int key){
    int i;
    for (i=0;i<arr->length;i++){
        if(key==arr->A[i]){
            return i;
        }}
        
        return -1;
    
}
   int main(){ 
    struct Array arr = {{1,5,6,7},4};
    int key = 6;
    cout<<Linears(&arr,key);
    cout<<endl;

    return 0;
}