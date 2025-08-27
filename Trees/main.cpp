#include <iostream>
using namespace std;


// Node structure for tree nodes
struct Node {
    Node *lchild, *rchild;
    int data;
};


// Queue structure for managing nodes during tree creation
struct Queue {
    int front, rear, size;
    Node **Q; // Array of pointers to nodes

    // Constructor to initialize the queue
    Queue(int size) {
        this->size = size;
        front = rear = -1;
        Q = new Node*[size];
    }

    // Destructor to free memory
    ~Queue() {
        delete[] Q;
    }

    // Enqueue a node into the queue
    void enqueue(Node *x) {
        if ((rear + 1) % size == front) {
            cout << "Queue is full" << endl;
        } else {
            rear = (rear + 1) % size;
            Q[rear] = x;
        }
    }

    // Dequeue a node from the queue
    Node* dequeue() {
        if (front == rear) {
            cout << "Queue is empty" << endl;
            return nullptr;
        } else {
            front = (front + 1) % size;
            return Q[front];
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == rear;
    }
};


// Tree structure for managing the binary tree
struct Tree {
    Node *root;

    // Constructor to initialize the tree
    Tree() {
        root = nullptr;
    }

    // Function to create a binary tree
    void createTree() {
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
    void Preorder(Node *p) {
        if (p) {
            cout << p->data << " ";
            Preorder(p->lchild);
            Preorder(p->rchild);
        }
    }


    // Postorder traversal (left, right, root)
    void Postorder(Node *p) {
        if (p) {
            Postorder(p->lchild);
            Postorder(p->rchild);
            cout << p->data << " ";
        }
    }


    // Count the number of nodes in the tree
    int count(Node *root) {
        if (root)
            return count(root->lchild) + count(root->rchild) + 1;
        return 0;
    }


    // Calculate the height of the tree
    int height(Node *root) {
        int x = 0, y = 0;
        if (root == nullptr) return 0;
        x = height(root->lchild);
        y = height(root->rchild);
        return (x > y) ? x + 1 : y + 1;
    }
};


// Main function
int main() {
    Tree t;
    t.createTree();

    cout << "Preorder: ";
    t.Preorder(t.root);
    cout << "\nPostorder: ";
    t.Postorder(t.root);
    cout << "\n";

    cout << "Number of nodes are: " << t.count(t.root) << "\n";
    cout << "Height of the tree is: " << t.height(t.root) << "\n";

    return 0;
}
