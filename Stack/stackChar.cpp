#include <iostream>
#include <cstring>
using namespace std;

struct Stack {
    int size, top;
    char *S;
} *st = NULL;


void createStack(int size) {
    st = new Stack;
    st->size = size;
    st->top = -1;
    st->S = new char[size];
}


void push(char x) {
    if (st->top == st->size - 1) {
        cout << "Stack Overflow" << endl;
    } else {
        st->S[++st->top] = x;
    }
}


char pop() {
    char x = -1;
    if (st->top == -1) {
        cout << "Stack Underflow" << endl;
    } else {
        x = st->S[st->top--];
    }
    return x;
}


int isEmpty() {
    return st->top == -1;
}


bool isBalanced(const char *exp) {
    for (int i = 0; exp[i] != '\0'; i++) {
        if (exp[i] == '(') {
            push(exp[i]);
        } else if (exp[i] == ')') {
            if (isEmpty()) {
                return false;
            }
            pop();
        }
    }
    return isEmpty();
}


int perf(char x) {
    if (x == '+' || x == '-') return 1;
    else if (x == '*' || x == '/') return 2;
    return 0;
}


int isOperand(char x) {
    return !(x == '+' || x == '-' || x == '*' || x == '/');
}


int stackTop() {
    if (!isEmpty()) return st->S[st->top];
    return -1;
}


char *inTOpost(const char *infix) {
    int len = strlen(infix);
    char *postfix = new char[len + 2];
    int i = 0, j = 0;
    while (infix[i] != '\0') {
        if (isOperand(infix[i])) {
            postfix[j++] = infix[i++];
        } else {
            while (!isEmpty() && perf(infix[i]) <= perf(stackTop())) {
                postfix[j++] = pop();
            }
            push(infix[i++]);
        }
    }
    while (!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';  // Null terminator
    return postfix;
}


int main() {
    char *exp = "a+b-(c+d*d)+a)"; 
   // Initialize stack with a maximum size
    if (isBalanced(exp))     cout << "The expression is balanced." << endl;
    else     cout << "The expression is not balanced." << endl;
    const char *infix = "a+b*c";
    createStack(100);  // Initialize stack with a maximum size
    push('#');  // Add a sentinel value to indicate stack bottom for precedence comparison

    char *postfix = inTOpost(infix);
    cout << "Postfix expression: " << postfix << endl;

    delete[] postfix;
    delete[] st->S;
    delete st;

    return 0;
}