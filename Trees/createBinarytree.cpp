#include <iostream>
using namespace std;

struct Node {
    Node *lchild;
    int data;
    Node *rchild;
};

struct Queue {
    int size, front, rear;
    Node **Q; // Array of pointers to Node
};

void Create(struct Queue *q, int size) {
    q->size = size + 1; // For circular queue, we need an extra slot
    q->front = q->rear = 0;
    q->Q = new Node*[q->size]; // Allocate memory for an array of Node pointers
}

void enqueue(struct Queue *q, Node *x) {
    if ((q->rear + 1) % q->size == q->front)
        cout << "Queue is full" << endl;
    else {
        q->rear = (q->rear + 1) % q->size;
        q->Q[q->rear] = x; // Store the Node pointer
    }
}

Node* dequeue(struct Queue *q) {
    Node *x = nullptr;
    if (q->front == q->rear)
        cout << "Queue is empty" << endl;
    else {
        q->front = (q->front + 1) % q->size;
        x = q->Q[q->front]; // Retrieve the Node pointer
    }
    return x;
}

int isEmpty(struct Queue *q) {
    return q->front == q->rear;
}

struct Node *root = NULL;

void create() {
    struct Node *p, *t;
    int x;
    struct Queue q;
    Create(&q, 100);
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = NULL;
    enqueue(&q, root);

    while (!isEmpty(&q)) {
        p = dequeue(&q);
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->lchild = t;
            enqueue(&q, t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node();
            t->data = x;
            t->lchild = t->rchild = NULL;
            p->rchild = t;
            enqueue(&q, t);
        }
    }
}

void preorder(struct Node *p) {
    if (p) {
        cout << p->data << " ";
        preorder(p->lchild);
        preorder(p->rchild);
    }
}

void postorder(struct Node *p){
    if(p){
        postorder(p->lchild);
        postorder(p->rchild);
        cout<<p->data<<" ";
    }
}

int main() { 
    create();
    cout << "Preorder traversal: ";
    preorder(root);
    cout << "Postorder traversal: ";
    postorder(root);
    return 0;
}
