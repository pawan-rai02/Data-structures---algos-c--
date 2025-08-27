#include <iostream>
using namespace std;

struct Element {
    int i, j, x; // Row index, Column index, Value
};

struct Sparse {
    int m, n, num; // Rows, Columns, Number of non-zero elements
    Element *e;    // Pointer to non-zero elements
};

void create(Sparse *s) {
    cout << "Enter dimensions (rows and columns):" << endl;
    cin >> s->m >> s->n;
    cout << "Enter number of non-zero elements:" << endl;
    cin >> s->num;

    // Allocate memory for non-zero elements
    s->e = new Element[s->num];
    cout << "Enter non-zero elements (row, column, value):" << endl;
    for (int i = 0; i < s->num; i++) {
        cin >> s->e[i].i;cin>> s->e[i].j;cin>> s->e[i].x;
    }
}

void display(const Sparse &s) {
    int k = 0;
    for (int i = 0; i < s.m; i++) {
        for (int j = 0; j < s.n; j++) {
            if (k < s.num && s.e[k].i == i && s.e[k].j == j) {
                cout << s.e[k++].x << " "; // Print the value and move to the next non-zero element
            } else {
                cout << "0 "; // Print zero for empty spaces
            }
        }
        cout << endl;
    }
}

struct Sparse *add(struct Sparse *s1, struct Sparse *s2){
    struct Sparse *sum;
    sum=new Sparse;
    sum->e=new Element[s1->num+s2->num];
    int i,j,k;i=k=j=0;
    while(i<s1->num && j<s2->num){
        if(s1->e[i].i<s2->e[j].i) sum->e[k++]=s1->e[i++];  // comparing rows
        else if(s1->e[i].i>s2->e[j].i) sum->e[k++]=s2->e[j++];
        else {
            if(s1->e[i].j<s2->e[j].j) sum->e[k++]=s1->e[i++];  // comparing columns
            else if(s1->e[i].j>s2->e[j].j) sum->e[k++]=s2->e[j++];
            else {
                sum->e[k]=s1->e[i]; //rows and columns copied
                sum->e[k++].x= s1->e[i++].x+s2->e[j++].x ;
            }
        }
    }
    for(;i<s1->num;i++)sum->e[k++]=s1->e[i];
    for(;j<s2->num;j++)sum->e[k++]=s2->e[j];
    sum->m=s1->m; sum->n=s1->n;sum->num=k;
};




int main() {
    Sparse s1,s2,*s3;
    create(&s1);
    create(&s2);
    s3=add(&s1,&s2);
    cout<<"first matrix"<<endl;
    display(s1);
    cout<<"second matrix"<<endl;
    display(s2);
    cout<<"sum matrix"<<endl;
    display(*s3);


    // Free allocated memory
    delete[] s1.e; delete[] s2.e;

    return 0;
}
