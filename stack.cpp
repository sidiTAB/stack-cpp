#include <iostream>
#include <string>
using namespace std;

#define SIZE 10

class Stack {
    int arr[SIZE];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == SIZE - 1;
    }

    void push(int x) {
        if (isFull()) {
            cout << "Stack is full!" << endl;
            return;
        }
        top++;
        arr[top] = x;
        cout << x << " pushed." << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << arr[top] << " popped." << endl;
        top--;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Top = " << arr[top] << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty!" << endl;
            return;
        }
        cout << "Stack (top to bottom): ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};


// Application 1: reverse a string using a stack of chars
void reverseString() {
    string word;
    cout << "Enter a word: ";
    cin >> word;

    // small char stack just for this function
    char s[100];
    int t = -1;

    // push every character
    for (int i = 0; i < word.size(); i++) {
        t++;
        s[t] = word[i];
    }

    // pop them back -> reversed
    cout << "Reversed: ";
    while (t >= 0) {
        cout << s[t];
        t--;
    }
    cout << endl;
}


// Application 2: check if parentheses are balanced
void checkParentheses() {
    string expr;
    cout << "Enter expression: ";
    cin >> expr;

    char s[100];
    int t = -1;
    bool balanced = true;

    for (int i = 0; i < expr.size(); i++) {
        char c = expr[i];

        if (c == '(' || c == '[' || c == '{') {
            // opening -> push
            t++;
            s[t] = c;
        }
        else if (c == ')' || c == ']' || c == '}') {
            // closing -> stack must not be empty AND top must match
            if (t == -1) {
                balanced = false;
                break;
            }
            char open = s[t];
            t--;
            if ((c == ')' && open != '(') ||
                (c == ']' && open != '[') ||
                (c == '}' && open != '{')) {
                balanced = false;
                break;
            }
        }
    }

    // if anything left in stack, not balanced
    if (t != -1) balanced = false;

    if (balanced) cout << "Balanced :)" << endl;
    else cout << "Not balanced :(" << endl;
}


int main() {
    Stack st;
    int choice, value;

    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Display" << endl;
        cout << "5. Reverse a word" << endl;
        cout << "6. Check parentheses" << endl;
        cout << "7. Exit" << endl;
        cout << "Choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Value to push: ";
                cin >> value;
                st.push(value);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                st.peek();
                break;
            case 4:
                st.display();
                break;
            case 5:
                reverseString();
                break;
            case 6:
                checkParentheses();
                break;
            case 7:
                cout << "Bye." << endl;
                break;
            default:
                cout << "Invalid choice." << endl;
        }
    } while (choice != 7);

    return 0;
}
