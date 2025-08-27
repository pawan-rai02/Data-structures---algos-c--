#include<iostream>
using namespace std;
class lowerTri
{
    private:
        int n,*A;
    public:
        lowerTri()
        {
           n=2;
            A=new int[2*(2+1)/2];
        }
        lowerTri(int n)
        {
            this->n=n;
            A=new int[n*(n+1)/2];
        }
        void set(int i, int j , int x);
        int get(int i, int j);
        void Display();
        ~lowerTri(){
            delete []A;
        }

};

void lowerTri:: set(int i,int j,int x){
    if(i==j)A[i-1]=x;
}

int lowerTri:: get(int i , int j){
    if(i>=j)return A[i*(i-1)/2+j-1];
    else return 0;
}

void lowerTri:: Display(){
    for(int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++){
            if(i>=j)cout<<A[i*(i-1)/2+j-1]<<" ";
            else cout<<'0';
        }cout<<endl;
    }
}
   int main(){ 
   int d;
   cout<<"enter dimensions";
   cin>>d;
   lowerTri lm(d);
   int x;
   cout<<"enter all elements";
   for(int i=1;i<=d;i++){
    for(int j=1; j<=d;j++){
        cin>>x;
        lm.set(i,j,x);
    }
   }
   lm.Display();
    return 0;
}