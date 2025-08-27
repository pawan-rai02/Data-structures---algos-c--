#include<iostream>
using namespace std;

struct Node {
    struct Node *lchild;
    int data;
    struct Node *rchild;
} *root = NULL;


void Insert(int key) {
    struct Node *t = root;
    struct Node *r, *p;

    if (root == 0) {
        p = new Node;
        p->lchild = p->rchild = 0;
        p->data = key;
        root = p;
        return;
    }
    while (t != 0) {
        r = t;
        if (key < t->data) t = t->lchild;
        else if (key > t->data) t = t->rchild;
        else return;
    }
    p = new Node;
    p->lchild = p->rchild = 0;
    p->data = key;

    if (key < r->data) r->lchild = p;
    else r->rchild = p;
}


struct Node *RInsert(struct Node *p, int key) {
    if (p == 0) {
        struct Node *t = new Node;
        t->data = key;
        t->lchild = t->rchild = 0;
        return t;
    }
    if (key < p->data) p->lchild = RInsert(p->lchild, key);
    else if (key > p->data) p->rchild = RInsert(p->rchild, key);
    return p;
}


struct Node *search(int key) {
    struct Node *t = root;
    while (t != NULL) {
        if (key == t->data) return t;
        else if (t->data > key) t = t->lchild;
        else t = t->rchild;
    }
    return NULL;
}


void inorder(struct Node *p) {
    if (p) {
        inorder(p->lchild);
        cout << p->data << " ";
        inorder(p->rchild);
    }
}


struct Node *InPre(struct Node *p) {
    while (p && p->rchild) p = p->rchild;
    return p;
}


struct Node *InSucc(struct Node *p) {
    while (p && p->lchild) p = p->lchild;
    return p;
}


int Height(struct Node *p) {
    int x, y;
    if (p == NULL) return 0;
    x = Height(p->lchild);
    y = Height(p->rchild);
    return x > y ? x + 1 : y + 1;
}


struct Node *Delete(struct Node *p, int key) {
    if (p == NULL) return NULL;
    if (p->lchild == NULL && p->rchild == NULL) {
        if (p == root) root = NULL;
        delete p;
        return NULL;
    }
    struct Node *q = NULL;
    if (key < p->data) p->lchild = Delete(p->lchild, key);
    else if (key > p->data) p->rchild = Delete(p->rchild, key);
    else {
        if (Height(p->lchild) > Height(p->rchild)) {
            q = InPre(p->lchild);
            p->data = q->data;
            p->lchild = Delete(p->lchild, q->data);
        } else {
            q = InSucc(p->rchild);
            p->data = q->data;
            p->rchild = Delete(p->rchild, q->data);
        }
    }
    return p;
}


int main() {
    root = RInsert(root, 10);
    RInsert(root, 12);
    Insert(9);
    Insert(88);
    Insert(1);
    inorder(root);
    cout << "\n";
    struct Node *temp = search(10);
    if (temp != NULL) cout << temp->data << " is found\n";
    else cout << "element not found\n";
    Delete(root, 10);
    inorder(root);
    cout << "\n";

    return 0;
}
