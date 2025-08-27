#include<iostream>
using namespace std;
struct Term
{
    int coeff,exp;
};
struct Poly{
    int  n;
    struct Term *terms;
};
void create(struct Poly *p){
    cout<<"Number of terms?";
    cin>>p->n;
    //p->terms= (struct Term*)malloc(p->n*sizeof(struct Term));
    p->terms=new Term[p->n];
    cout<<"enter terms";
    for(int i=0;i<p->n;i++){
        cin>>p->terms[i].coeff>>p->terms[i].exp;
    }
}

void display(struct Poly p){
    int i;
    for(i=0;i<p.n;i++)
    {cout<<p.terms[i].coeff<<"x"<<p.terms[i].exp<<" + ";}cout<<endl;

}

struct Poly *add(struct Poly *p1,struct Poly *p2){
    struct Poly *sum;
   // sum=(struct Poly*)malloc(sizeof(struct Poly));
    sum = new Poly;
    sum->terms=new Term[p1->n+p2->n];
    int i=0,j=0,k=0;
    while(i<p1->n&&j<p2->n){
        if(p1->terms[i].exp>p2->terms[j].exp)
            sum->terms[k++]=p1->terms[i++];
            else if(p1->terms[i].exp<p2->terms[j].exp)
                sum->terms[k++]=p2->terms[j++];
            else{
                sum->terms[k].exp=p1->terms[i].exp;
                sum->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
            }

    }
    for(;i<p1->n;i++) sum->terms[k++]=p1->terms[i];
    for(;j<p2->n;i++) sum->terms[k++]=p2->terms[j];
    sum->n=k;
    return sum;
}
   int main(){ 
    struct Poly p1,p2,*p3;
    create(&p1); create(&p2);p3=add(&p1,&p2);
    cout<<endl;
    display(p1);
    cout<<endl;
    display(p2);
    cout<<endl;
    display(*p3);
    return 0;
}