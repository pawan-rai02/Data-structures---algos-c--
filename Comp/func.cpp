#include<bits/stdc++.h>
using namespace std;
void swapp(int a,int b){
    int temp=a;
    a=b;
    b=a;

}
int main(){
    int x,y;
    cin>>x>>y;
    cout<<"call by value"<<endl;
    swapp(x,y);
    cout<<x<<y;
  string s="jdh";
    cout<<"minimum of x and y is "<<min(x,y)<<"\n";   /////inbuilt functions
       cout<<"max of x and y is "<<max(x,y)<<"\n";
         cout<<endl<<"refrence"<<endl;
    swap(x,y);cout<<"x="<<x<<"y="<<y;
}