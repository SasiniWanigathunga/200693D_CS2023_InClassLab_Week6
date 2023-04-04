#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;

struct Node {
    int data;
    Node* next;
};

class Stack {
    private:
        Node* top;

    public:
        Stack() {
            top = nullptr;
        }

        void Push(int data) {
            Node* newNode = new Node;
            newNode->data = data;
            newNode->next = top;
            top = newNode;
        }

        void Pop() {
            if (isEmpty()) {
                cout << "Stack is Empty!" << endl;
                return;
            }

            Node* temp = top;
            top = top->next;
            delete temp;
        }

        bool isEmpty() {
            return top == nullptr;
        }

        int StackTop() {
            if (isEmpty()) {
                cout << "Stack is Empty!" << endl;
                return -1;
            }

            return top->data;
        }

        void Display() {
            if (isEmpty()) {
                cout << "Stack is Empty!" << endl;
                return;
            }

            Node* temp = top;
            while (temp != nullptr) {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
        }
};

int main() {
    Stack s;

    // Start timer
    auto start = high_resolution_clock::now();

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

    // End timer and calculate elapsed time
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);

    cout << "Execution time: " << duration.count() << " ns" << endl;

    return 0;
}
