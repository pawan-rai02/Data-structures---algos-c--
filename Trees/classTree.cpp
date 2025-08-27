#include <iostream>
using namespace std;

// Node class for tree nodes
class Node {
public:
    Node *lchild, *rchild;
    int data;
};


// Queue class for managing nodes during tree creation
class Queue {
private:
    int front, rear, size;
    Node **Q; // Array of pointers to nodes
public:
    Queue() { front = rear = -1; size = 10; Q = new Node*[size]; }
    Queue(int size) { this->size = size; front = rear = -1; Q = new Node*[this->size]; }
    ~Queue() { delete[] Q; } // Destructor to free memory
    void enqueue(Node *x);
    Node* dequeue();
    void Display();
    int isEmpty();
};


// Enqueue method for adding a node to the queue
void Queue::enqueue(Node *x) {
    if ((rear + 1) % size == front)
        cout << "Queue is full" << endl;
    else {
        rear = (rear + 1) % size;
        Q[rear] = x;
    }
}


// Dequeue method for removing a node from the queue
Node* Queue::dequeue() {
    if (front == rear) {
        cout << "Queue is empty" << endl;
        return nullptr;
    } else {
        front = (front + 1) % size;
        return Q[front];
    }
}


// Display the queue contents (for debugging)
void Queue::Display() {
    cout << "The queue is: ";
    int i = (front + 1) % size;
    while (i != (rear + 1) % size) {
        cout << Q[i]->data << " ";
        i = (i + 1) % size;
    }
    cout << endl;
}


// Check if the queue is empty
int Queue::isEmpty() {
    return front == rear;
}


// Tree class for managing the binary tree
class Tree {
public:
    Node *root;
    Tree() { root = nullptr; }
    void createTree();
    void Preorder(Node *p);
    void Postorder(Node *p);
    int count(Node *root);
    int height(Node *root);
};


// Create a binary tree using the queue
void Tree::createTree() {
    Node *p, *t;
    int x;
    Queue q(100);

    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->lchild = root->rchild = nullptr;
    q.enqueue(root);

    while (!q.isEmpty()) {
        p = q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->lchild = t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if (x != -1) {
            t = new Node;
            t->data = x;
            t->lchild = t->rchild = nullptr;
            p->rchild = t;
            q.enqueue(t);
        }
    }
}


// Preorder traversal (root, left, right)
void Tree::Preorder(Node *p) {
    if (p) {
        cout << p->data << " ";
        Preorder(p->lchild);
        Preorder(p->rchild);
    }
}


// Postorder traversal (left, right, root)
void Tree::Postorder(Node *p) {
    if (p) {
        Postorder(p->lchild);
        Postorder(p->rchild);
        cout << p->data << " ";
    }
}


int Tree ::count(Node *root){
    if(root)    return count(root->lchild)+count(root->rchild)+1;
    return 0;
}


int Tree:: height(Node *root){
    int x=0, y=0;
    if(root==0) return 0;
    x=height(root->lchild);
    y=height(root->rchild);
    if(x>y)     return x+1;
    else return y+1;
}


// Main function
int main() {
    Tree t;
    t.createTree();
    cout << "Preorder: ";
    t.Preorder(t.root);
    cout << "\nPostorder: "<<"\n";
    t.Postorder(t.root);

    cout<<"Number of nodes are :"<<t.count(t.root)<<"\n";
    cout<<"Height of the tree is :"<<t.height(t.root)<<"\n";
    return 0;
}
