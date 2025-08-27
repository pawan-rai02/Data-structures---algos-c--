#include<iostream>
using namespace std;
template<class T>
class Arithmetic{
    private:
    T a;
    T b;
    public:
    Arithmetic(T a, T b);
    T add();
    T sub();
};
template<class T>
Arithmetic<T>::Arithmetic(T a, T b){
    this ->a=a;
    this ->b= b;

};
template<class T>
    T Arithmetic<T> ::add(){
        T c;
        c=a+b;
        return c;
    }
template<class T>
T Arithmetic<T>:: sub(){
    T c;
    c= a-b;
    return c;
}

int main(){ 
  int a , b;
  cout<<"enter both numbers :"<<endl;
  cin>>a>>b;
  Arithmetic<int> ar(a,b);
  cout<<"addition :"<<ar.add()<<endl;
  cout<<"subtraction :"<<ar.sub()<<endl;
  cout<<"enter decimal values :"<<endl;
  cin>>a>>b;
  Arithmetic<double> arr(a,b);
  cout<<"add :"<<arr.add()<<endl;
  cout<<"subtract :"<<arr.sub()<<endl;
    return 0;
}