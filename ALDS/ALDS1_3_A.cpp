//Stack
#include <iostream>

using namespace std;

int top, S[1000];

void push(int x) {
    top += 1;
    S[top] = x;
}

int pop() {
    int x = S[top];
    top -= 1;
    return x;
}

int main() {
    char s[100];
    int a, b;

    while(cin >> s) {
        switch(s[0]) {
            case '+':
                b = pop();
                a = pop();
                push(a + b);
                break;
            case '-':
                b = pop();
                a = pop();
                push(a - b);
                break;
            case '*':
                b = pop();
                a = pop();
                push(a * b);
                break;
            default:
                push(int(strtol(s, NULL, 10)));
        }
    }
    cout << pop() << endl;
}
