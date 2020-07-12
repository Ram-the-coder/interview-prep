#include<bits/stdc++.h>
using namespace std;
/**************************************** Stack ****************************************/

/******************** Using Array ********************/
class Stack_Using_Array {
    int a[1000];
    int max_stack_size, top;

public:

    Stack_Using_Array(int size) : max_stack_size(size), top(-1) {}

    bool push(int data) {
        if(top == max_stack_size-1) return false; // stack overflow
        a[++top] = data;
        return true;
    }

    int pop() {
        if(top == -1) return -1; // stack empty
        return a[top--];
    }

    int peek() {
        return (top == -1) ? -1 : a[top];
    }
};

/******************** Using SLL ********************/
class SLL_Node {
public:
    int data;
    SLL_Node* next;

    SLL_Node(int val) : data(val), next(NULL) {}
};

class Stack_Using_SLL {
    int max_stack_size, elements_count;
    SLL_Node* top;

public:

    Stack_Using_SLL() : max_stack_size(INT_MAX), top(NULL), elements_count(0) {}
    Stack_Using_SLL(int size) : max_stack_size(size), top(NULL), elements_count(0) {}

    bool push(int data) {
        if(elements_count == max_stack_size) return false; // stack overflow
        SLL_Node *new_top = new SLL_Node(data);
        new_top->next = top;
        top = new_top;
        ++elements_count;
        return true;
    }

    int pop() {
        if(elements_count == 0) return -1; // stack empty
        SLL_Node *to_be_deleted = top;
        int data = top->data;
        top = top->next;
        delete(to_be_deleted);
        --elements_count;
        return data;
    }

    int peek() {
        if(elements_count == 0) return -1; // stack empty
        return top->data;
    }
};


/**************************************** Queue ****************************************/

/******************** Using Array ********************/

class Queue_Using_Array {
    int a[1000];
    int max_size, front, back;

public:
    Queue_Using_Array(int n) : max_size(n), front(-1), back(-1) {}

    bool enqueue(int data) {
        if(back == max_size-1) return false; // queue full

        a[++back] = data;
        if(front == -1) front = 0;

        return true;
    }

    int dequeue() {
        if(front == -1) return -1; // queue empty

        int data = a[front];

        if(front == back) front = back = -1;
        else ++front;

        return data;
    }
};

/******************** Using SLL ********************/

class Queue_Using_SLL {
    SLL_Node *front, *back;
    int max_size, elements_count;

public:

    Queue_Using_SLL() : front(NULL), back(NULL), max_size(INT_MAX), elements_count(0) {}
    Queue_Using_SLL(int n) : front(NULL), back(NULL), max_size(n), elements_count(0) {}

    bool enqueue(int data) {
        if(elements_count == max_size) return false; // queue full

        SLL_Node *newEntry = new SLL_Node(data);
        if(front == NULL) front = back = newEntry;
        else {
            back->next = newEntry;
            back = newEntry;
        }

        ++elements_count;
        return true;
    }

    int dequeue() {
        if(elements_count == 0) return -1; // queue empty

        SLL_Node *to_be_deleted = front;
        int data = to_be_deleted->data;

        if(front == back) front = back = NULL;
        else front = front->next;

        delete(to_be_deleted);
        --elements_count;

        return data;
    }
};

/**************************************** Test ****************************************/
int main() {
    int choice = 1;
    while(choice) {
        cout << "1. Stack using array\n2. Stack using SLL\n3. Queue using array\n4. Queue using SLL\n";
        cin >> choice;
        switch(choice) {
            case 1: {
                int ch = 1, data;
                cout << "Enter size of stack: ";
                cin >> data;
                Stack_Using_Array stk_arr(data);
                while(ch) {
                    cout << "1. Push\n2.Pop\n3. Peek\n";
                    cin >> ch;
                    switch(ch) {
                        case 1: cout << "Data: ";
                                cin >> data;
                                cout << stk_arr.push(data) << '\n';
                                break;
                        case 2: cout << stk_arr.pop() << '\n'; 
                                break;
                        case 3: cout << stk_arr.peek() << '\n';
                                break;
                        default: ch = 0;
                    }
                }
                break;
            }
            case 2: {
                int ch = 1, data;
                cout << "Enter size of stack: ";
                cin >> data;
                Stack_Using_SLL stk_sll(data);
                while(ch) {
                    cout << "1. Push\n2.Pop\n3. Peek\n";
                    cin >> ch;
                    switch(ch) {
                        case 1: cout << "Data: ";
                                cin >> data;
                                cout << stk_sll.push(data) << '\n';
                                break;
                        case 2: cout << stk_sll.pop() << '\n'; 
                                break;
                        case 3: cout << stk_sll.peek() << '\n';
                                break;
                        default: ch = 0;
                    }
                }
                break;
            }
            case 3: {
                int ch = 1, data;
                cout << "Enter size of queue: ";
                cin >> data;
                Queue_Using_Array qa(data);
                while(ch) {
                    cout << "1. EnQ\n2.DQ\n";
                    cin >> ch;
                    switch(ch) {
                        case 1: cout << "Data: ";
                                cin >> data;
                                cout << qa.enqueue(data) << '\n';
                                break;
                        case 2: cout << qa.dequeue() << '\n'; 
                                break;
                        default: ch = 0;
                    }
                }
                break;
            }
            case 4: {
                int ch = 1, data;
                cout << "Enter size of queue: ";
                cin >> data;
                Queue_Using_SLL qs(data);
                while(ch) {
                    cout << "1. EnQ\n2.DQ\n";
                    cin >> ch;
                    switch(ch) {
                        case 1: cout << "Data: ";
                                cin >> data;
                                cout << qs.enqueue(data) << '\n';
                                break;
                        case 2: cout << qs.dequeue() << '\n'; 
                                break;
                        default: ch = 0;
                    }
                }
                break;
            }
            default: choice = 0;
        }
    }
}