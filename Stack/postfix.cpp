#include<iostream>
using namespace std;


struct Stack {
    int size, top, *S;
} *st = nullptr;


void create() {
    st = new Stack;  // Initialize the stack pointer
    cout << "Enter the size: ";
    cin >> st->size;
    st->top = -1;
    st->S = new int[st->size];
}


void display() {
    if (st == nullptr) {
        cout << "Stack not created yet!" << endl;
        return;
    }
    cout << "Stack is: ";
    for (int i = st->top; i >= 0; i--) {
        cout << st->S[i] << " ";
    }
    cout << endl;
}


void push(int x) {
    if (st->top == st->size - 1) 
        cout << "Stack Overflow" << endl;
    else {
        st->top++;
        st->S[st->top] = x;
    }
}


int pop() {
    int x = -1;
    if (st->top == -1) 
        cout << "Stack Underflow" << endl;
    else {
        x = st->S[st->top--];
    }
    return x;
}


int peek(int index) {
    int x = -1;
    if (st->top - index + 1 < 0)
        cout << "Invalid Index" << endl;
    else 
        x = st->S[st->top - index + 1];
    return x;
}


int isEmpty() {
    return st->top == -1;
}


int isFull() {
    return st->top == st->size - 1;
}


int stackTop() {
    if (!isEmpty()) 
        return st->S[st->top];
    return -1;
}


int isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}


int eval(const char *postfix) {
    int x1, x2, r;
    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isOperand(postfix[i])) 
            push(postfix[i] - '0'); // Convert char to int
        else {
            x2 = pop();  
            x1 = pop();
            switch (postfix[i]) {
                case '+': r = x1 + x2;  break;
                case '-': r = x1 - x2;  break;
                case '*': r = x1 * x2;  break;
                case '/': r = x1 / x2;  break;
            }
            push(r);
        }
    }
    return stackTop();
}


int main() {
    create(); // Initialize stack size
    const char *postfix = "234*+82/-";
    cout << "Result is: " << eval(postfix) << endl;
    delete[] st->S; // Clean up allocated memory
    delete st;
    return 0;
}