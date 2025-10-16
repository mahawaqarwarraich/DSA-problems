#include<iostream>
#include<stack>
using namespace std;

bool isOprnd(char el) {
    // Check if el is an alphabet (A-Z or a-z) OR a digit (0-9)
    if ((el >= 'A' && el <= 'Z') || 
        (el >= 'a' && el <= 'z') || 
        (el >= '0' && el <= '9')) 
    {
        return true;
    }
    return false;
}

bool isOprtr(char el) {
    if (el == '+' || el == '-' || el == '*' || el == '/' || el == '^') {
        return true;
    }
    return false;
}


int preced(char el) {
    if (el == '^') {
        return 6;
    } else if (el == '*' || el == '/') {
        return 5;
    } else if (el == '+' || el == '-') {
        return 4;
    }

    return -1;
}


string infixToPost(string infix) {
    cout << "hello1";
    string postfix = "";
    stack<char> st;

    for (int i = 0; i < infix.length(); i++) {
         cout << "hello2";
        if (isOprnd(infix[i])) {
            postfix.push_back(infix[i]);
[p]        } else if (infix[i] == '(') {
            st.push(infix[i]);
        } else if (infix[i] == ')') {
            char el = st.top();
i            while (el != '(') {
                st.pop();
                postfix.push_back(el);
                el = st.top();
            }
            st.pop();
            // lets assume input is a valid infix
        } else {
            char el = st.top();
            char in = infix[i];
            if (isOprtr(el)) {
                while (preced(in) == preced(el) || preced(in) < preced(el)) {
                st.pop();
                postfix.push_back(el);
                el = st.top();
            } else {
                st.push(in);
            }
            } else {
                st.push(in);
            }
            
            
        } 
    }

     cout << "hello3";

    while (!st.empty()) {
        char el = st.top();
        st.pop();
        postfix.push_back(el);
    }

    return postfix;
}

int main() {
    string infix = "(A+B)*(C-D)/E";

    string postfix = infixToPost(infix);

    cout << "Postfix: " << postfix;
    return 0;
}