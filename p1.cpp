#include <iostream>
#include <math.h>
using namespace std;

struct Node {
    int data;
    Node* link;
};

class StackP {
private:
    Node* top;

public:
    StackP() {
        top = nullptr;
    }

    void push(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->link = top;
        top = newNode;
    }

    void pop() {
        if(top == nullptr)
            cout << "Stack is empty" << endl;
        else {
            Node* p = top;
            top = top->link;
            delete p;
        }
    }

    void printS() {
        Node* p = top;
        if(p == nullptr)
            cout << "Stack is empty" << endl;
        else {
            cout << "Result: ";
            while (p != nullptr) {
                cout << p->data << ' ';
                p = p->link;
            }
        }
    }
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = rear = nullptr;
    }

    void addQ(int x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->link = nullptr;


        if(front == nullptr)
            front = rear = newNode;
        else {
            rear->link = newNode;
            rear = newNode;
        }
    }

    void deleteQ() {
        if(front == nullptr)
            cout << "Queue is empty" << endl;
        else {
            Node *p = front;
            front = front->link;
            delete p;
        }
    }

    void printQ() {
        Node* p = front;
        if(p == nullptr)
            cout << "Queue is empty" << endl;
        else {
            cout << "Result: ";
            while (p != nullptr) {
                cout << p->data << ' ';
                p = p->link;
            }
        }
    }
};

class CircularLinkedList {
private:
    Node* first;

public:
    CircularLinkedList() {
        Node *newNode = new Node;
        first = newNode;
        first->link = first; //point to itself
    }

    void insert(int x) {
        Node *newNode = new Node;
        newNode->data = x;
        Node *p = first;

        while (p->link != first)
            p = p->link;
        p->link = newNode;
        newNode->link = first;
    }

    void mergeSortLinkedList(CircularLinkedList l1, CircularLinkedList l2) {
        CircularLinkedList l3;

        Node* last = l3.first;
        Node* p = l1.first->link;
        Node* q = l2.first->link;

        while (p!=l1.first && q!=l2.first) {
            if (p->data <= q->data) {
                last->link = p;
                last = p;
                p = p->link;
            }
            else {
                last->link = q;
                last = q;
                q = q->link;
            }
        }
        if (p != l1.first) {
            last->link = p;
            while (p->link != l1.first)
                p = p->link;
            p->link = l3.first;
        }
        else {
            last->link = q;
            while (q->link != l2.first)
                q = q->link;
           q->link = l3.first;
        }
        cout << "Result: ";
        l3.printList();
    }

    void printList() {
        Node* p = first;

        if (p->link == nullptr)
            cout << "List is empty" << endl;
        else {
            cout << "Result: ";
            do {
                p = p->link;
                cout << p->data << ' ';
            } while (p->link != first);
        }
    }

    bool prime(int num) {
        bool isPrime = true;

        for (int i = 2; i <= sqrt(num); i++)
            if (num % i == 0) {
                isPrime = false;
                break;
            }
            else
                continue;

        if (isPrime && num!=1)
            return true;
        else
            return false;
    }

    void deleteP() {
        Node* p = first->link;
        Node* q = first;

        do {
            if (prime(p->data))
                q->link = p->link;
            else
                q = q->link;
            p = p->link;
        } while(p != first);
    }
};

int main()
{
    int num, w;

    CircularLinkedList l1;
    CircularLinkedList l2;
    CircularLinkedList l3;
    StackP s;
    Queue q;

    cout << "which one?" << endl;
    cout << "1- create a linkedlist" << endl;
    cout << "2- create a stack" << endl;
    cout << "3- create a queue" << endl;
    cout << "enter a number: ";
    cin >> w;

    switch (w) {
        case 1:
            do {
                cout << endl << "1-add" << endl << "2-delete prime nodes" << endl <<
                "3-merge sort linkedlist" << endl << "4-print" << endl << "5-exit" << endl;
                cout << "enter a number: ";
                cin >> w;
                cout << endl;

                switch (w) {
                    case 1:
                        cout << "Enter numbers: ";
                        while (1) {
                            cin >> num;
                            if (num != -1)
                                l1.insert(num);
                            else
                                break;
                        }
                        break;
                    case 2:
                        l1.deleteP();
                        break;
                    case 3:
                        cout << "Enter list1: ";
                        while (1) {
                            cin >> num;
                            if (num != -1)
                                l1.insert(num);
                            else
                                break;
                        }
                        cout << "Enter list2: ";
                        while (1) {
                            cin >> num;
                            if (num != -1)
                                l2.insert(num);
                            else
                                break;
                        }
                        l3.mergeSortLinkedList(l1, l2);
                        break;
                    case 4:
                        l1.printList();
                        break;
                    default:
                        if (w != 5)
                            cout << "Error! Enter another number";
                        break;
                }
            } while (w != 5);
            break;

        case 2:
            do {
                cout << endl << "1-push" << endl << "2-pop" << endl << "3-print" << endl << "4-exit" << endl;
                cout << "enter a number: ";
                cin >> w;
                cout << endl;

                switch (w) {
                    case 1:
                        cout << "Enter numbers: ";
                        while (1) {
                            cin >> num;
                            if (num != -1)
                                s.push(num);
                            else
                                break;
                        }
                        break;
                    case 2:
                        s.pop();
                        break;
                    case 3:
                        s.printS();
                        break;
                    default:
                        if (w != 4)
                            cout << "Error! Enter another number";
                        break;
                }
            } while (w != 4);
            break;

        case 3:
            do {
                cout << endl << "1-add" << endl << "2-delete" << endl << "3-print" << endl << "4-exit" << endl;
                cout << "enter a number: ";
                cin >> w;
                cout << endl;

                switch (w) {
                    case 1:
                        cout << "Enter numbers: ";
                        while (1) {
                            cin >> num;
                            if (num != -1)
                                q.addQ(num);
                            else
                                break;
                        }
                        break;
                    case 2:
                        q.deleteQ();
                        break;
                    case 3:
                        q.printQ();
                        break;
                    default:
                        if (w != 4)
                            cout << "Error! Enter another number";
                        break;
                }
            } while (w != 4);
            break;
        default:
            cout << "wrong number!";
            break;
    }
    return 0;
}