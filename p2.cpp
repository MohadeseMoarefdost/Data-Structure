#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class Node {
    string data;
    Node* link;
    friend class StackP;
};

class StackP {
private:
    Node* top;

public:
    StackP() {
        top = nullptr;
    }

    char topS() {
        string t = top->data;
        return t[0];
    }

    void push(char x) {
        Node* newNode = new Node;
        newNode->data = x;
        newNode->link = top;
        top = newNode;
    }
    void push(string y) {
        Node* newNode = new Node;
        newNode->data = y;
        newNode->link = top;
        top = newNode;
    }

    string pop() {
        if (top == nullptr)
            cout << "Stack is empty";
        else {
            string x = top->data;
            Node *p = top;
            top = top->link;
            delete p;
            return x;
        }
    }

    bool isEmpty() {
        if (top == nullptr)
            return true;
        else
            return false;
    }
};

class Expression {
public:
    bool isOperator(char x) {
        if (x=='+' || x=='-' || x=='*' || x=='/' || x=='^' || x=='%' || x=='(' || x==')')
            return true;
        else
            return false;
    }

    int ICP(char c) {
        if (c == '(' || c == ')')
            return 4;
        else if (c == '^')
            return 3;
        else if (c == '/' || c == '*' || c == '%')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }
    int ISP(char c) {
        if (c == '(' || c == ')')
            return 0;
        else if (c == '^')
            return 3;
        else if (c == '/' || c == '*' || c == '%')
            return 2;
        else if (c == '+' || c == '-')
            return 1;
        else
            return -1;
    }

    string postfixToInfix(string postfix) {
        StackP s;
        string res;
        for (int i = 0; i < postfix.length(); i++) {
            if (isOperator(postfix[i])) {
                string op1 = s.pop();
                string op2 = s.pop();
                res = '(' + op2 + postfix[i] + op1 + ')';
                s.push(res);
            } else
                s.push(postfix[i]);
        }
        return s.pop();
    }

    string prefixToInfix(string prefix) {
        StackP s;
        string res;

        for (int i = prefix.length()-1; i >= 0; i--) {
            if (isOperator(prefix[i])) {
                string op1 = s.pop();
                string op2 = s.pop();
                res = '(' + op1 + prefix[i] + op2 + ')';
                s.push(res);
            } else
                s.push(prefix[i]);
        }
        return s.pop();
    }

    string infixToPostfix(string infix) {
        StackP s;
        string  res;

         for(int i=0; i<infix.length(); i++) {
             if(infix[i] == ')') {
                 while (s.topS() != '(')
                     res += s.pop();
                 s.pop();
             }
             else if(isOperator(infix[i])) {
                 while (!s.isEmpty() && ISP(s.topS()) >= ICP(infix[i]))
                     res += s.pop();
                 s.push(infix[i]);
             }
             else
                 res += infix[i];
         }
         while (!s.isEmpty())
             res += s.pop();
         return res;
    }

    string infixToPrefix(string infix) {
        StackP s;
        string  res;

        for(int i=infix.length()-1; i>=0; i--) {
            if(infix[i] == '(') {
                while (s.topS() != ')')
                    res += s.pop();
                s.pop();
            }
            else if(isOperator(infix[i])) {
                while (!s.isEmpty() && ISP(s.topS()) > ICP(infix[i]))
                    res += s.pop();
                s.push(infix[i]);
            }
            else
                res += infix[i];
        }
        while (!s.isEmpty())
            res += s.pop();
        reverse(res.begin(), res.end());
        return res;
    }

    string prefixToPostfix(string prefix) {
        return infixToPostfix(prefixToInfix(prefix));
    }

    string postfixToPrefix(string postfix) {
        return infixToPrefix(postfixToInfix(postfix));
    }
};

int main() {
    string infix, prefix, postfix;
    Expression e;
    int w;

    do {
        cout << "1-Infix To Postfix" << endl;
        cout << "2-Infix To Prefix" << endl;
        cout << "3-Prefix To Postfix" << endl;
        cout << "4-Prefix To Infix" << endl;
        cout << "5-Postfix To Prefix" << endl;
        cout << "6-Postfix To Infix" << endl;
        cout << "0-Exit" << endl;

        cout << "Enter a number: ";
        cin >> w;

        switch (w) {
            case 1:
                cout << "Enter an infix expression: ";
                cin >> infix;
                cout << "Result: " << e.infixToPostfix(infix) << endl;
                break;

            case 2:
                cout << "Enter an infix expression: ";
                cin >> infix;
                cout << "Result: " << e.infixToPrefix(infix) << endl;
                break;

            case 3:
                cout << "Enter a prefix expression: ";
                cin >> prefix;
                cout << "Result: " << e.prefixToPostfix(prefix) << endl;
                break;

            case 4:
                cout << "Enter a prefix expression: ";
                cin >> prefix;
                cout << "Result: " << e.prefixToInfix(prefix) << endl;
                break;

            case 5:
                cout << "Enter a postfix expression: ";
                cin >> postfix;
                cout << "Result: " << e.postfixToPrefix(postfix) << endl;
                break;

            case 6:
                cout << "Enter a postfix expression: ";
                cin >> postfix;
                cout << "Result: " << e.postfixToInfix(postfix) << endl;
                break;
            default:
                if (w != 0)
                    cout << "Error! Enter another number" << endl;
                break;
        }
    } while (w != 0);
    return 0;
}