#include <iostream>
using namespace std;


struct Node {
    struct Node *lchild;
    int data, height;
    struct Node *rchild;
} *root = NULL;


// Function to calculate the height of a node
int NodeHeight(struct Node *p) {
    int hLeft, hRight;
    hLeft = (p && p->lchild) ? p->lchild->height : 0;
    hRight = (p && p->rchild) ? p->rchild->height : 0;
    return 1 + max(hLeft, hRight);
}


// Function to calculate the balance factor of a node
int BalanceFactor(struct Node *p) {
    int hLeft, hRight;
    hLeft = (p && p->lchild) ? p->lchild->height : 0;
    hRight = (p && p->rchild) ? p->rchild->height : 0;
    return hLeft - hRight;
}


// Perform a right rotation
struct Node *LLrotation(struct Node *p) {
    struct Node *x = p->lchild;
    struct Node *T2 = x->rchild;

    // Perform rotation
    x->rchild = p;
    p->lchild = T2;

    // Update heights
    p->height = NodeHeight(p);
    x->height = NodeHeight(x);

    return x; // New root
}


// Perform a left rotation
struct Node *RRrotation(struct Node *x) {
    struct Node *y = x->rchild;
    struct Node *T2 = y->lchild;

    // Perform rotation
    y->lchild = x;
    x->rchild = T2;

    // Update heights
    x->height = NodeHeight(x);
    y->height = NodeHeight(y);

    return y; // New root
}


// Insert a node into the AVL tree
struct Node *RInsert(struct Node *p, int key) {
    if (p == NULL) {
        struct Node *t = new Node();
        t->data = key;
        t->lchild = t->rchild = NULL;
        t->height = 1; // New node is initially at height 1
        return t;
    }

    if (key < p->data)
        p->lchild = RInsert(p->lchild, key);
    else if (key > p->data)
        p->rchild = RInsert(p->rchild, key);

    // Update height of current node
    p->height = NodeHeight(p);

    // Calculate balance factor
    int balance = BalanceFactor(p);

    // Perform rotations if the node is unbalanced
    // Left Left Case
    if (balance > 1 && key < p->lchild->data)
        return LLrotation(p);

    // Right Right Case
    if (balance < -1 && key > p->rchild->data)
        return RRrotation(p);

    // Left Right Case
    if (balance > 1 && key > p->lchild->data) {
        p->lchild = RRrotation(p->lchild);
        return LLrotation(p);
    }

    // Right Left Case
    if (balance < -1 && key < p->rchild->data) {
        p->rchild = LLrotation(p->rchild);
        return RRrotation(p);
    }

    return p; // Return unchanged node
}


int main() {
    root = RInsert(root, 10);
    root = RInsert(root, 20);
    root = RInsert(root, 30);
    root = RInsert(root, 25);
    root = RInsert(root, 28);

    cout << "Root Node: " << root->data << endl;

    return 0;
}
