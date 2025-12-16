/*
 * Infix to Postfix Conversion (Shunting Yard Algorithm)
 *
 * Input:  a+b*(c^d-e)^(f+g*h)-i
 * Output: abcd^e-fgh*+^*+i-
 */

#include <iostream>
#include <stack>
#include <string>

using namespace std;

// Precedence of operators
int prec(char c) {
    if (c == '^') return 3;
    if (c == '/' || c == '*') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

// Associativity of operators
// Left to right: +, -, *, /
// Right to left: ^
char associativity(char c) {
    if (c == '^') return 'R';
    return 'L';
}

string infixToPostfix(string s) {
    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];

        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9')) {
            result += c;
        }
        else if (c == '(') st.push('(');
        else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result += st.top();
                st.pop();
            }
            if (!st.empty()) st.pop();
        }
        else {
            while (!st.empty() && prec(s[i]) < prec(st.top()) ||
                  (!st.empty() && prec(s[i]) == prec(st.top()) && associativity(s[i]) == 'L')) {

                result += st.top();
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result += st.top();
        st.pop();
    }

    return result;
}

int main() {
    string exp = "a+b*(c^d-e)^(f+g*h)-i";

    cout << "Infix:   " << exp << endl;
    cout << "Postfix: " << infixToPostfix(exp) << endl;

    return 0;
}