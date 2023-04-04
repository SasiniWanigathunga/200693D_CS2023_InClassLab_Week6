#include <iostream>
using namespace std;
const int MAX_SIZE = 100;

struct Stack {
    int top;
    int stack_array[MAX_SIZE];

    Stack() {
        top = -1;
    }

    void Push(int data) {
        if (isFull()) {
            cout << "Stack Overflow" << endl;
            return;
        }
        top+=1;
        stack_array[top] = data;
    }

    int Pop() {
        if (isEmpty()) {
            cout << "Stack Underflow" << endl;
            return -1;
        }
        top-=1;
        return stack_array[top];
    }

    bool isEmpty() {
        return top <= -1;
    }

    bool isFull() {
        return top >= MAX_SIZE - 1;
    }

    int StackTop() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return -1;
        }
        return stack_array[top];
    }

    void Display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        for (int i = top; i >= 0; i--) {
            cout << stack_array[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack s;
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    for (int i=0; i<5; i++){
        s.Pop(); 
    }
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();

    return 0;
}
