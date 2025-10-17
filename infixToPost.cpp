#include<iostream>
#include<stack>
using namespace std;

bool isOprnd(char el) {
    // Check if el is an alphabet (A-Z or a-z) OR a digit (0-9)
    return (el >= 'A' && el <= 'Z') || 
        (el >= 'a' && el <= 'z') || 
        (el >= '0' && el <= '9');
}

bool isOprtr(char el) {
    return (el == '+' || el == '-' || el == '*' || el == '/' || el == '^');
}


int preced(char el) {
    if (el == '^') {
        return 3;
    } else if (el == '*' || el == '/') {
        return 2;
    } else if (el == '+' || el == '-') {
        return 1;
    }

    return -1;
}


string infixToPost(string infix) {
    string postfix = "";
    stack<char> st;

    for (int i = 0; i < infix.length(); i++) {
        if (isOprnd(infix[i])) {
            postfix.push_back(infix[i]); // n
        } else if (infix[i] == '(') {
            st.push(infix[i]); // 1
        } else if (infix[i] == ')') {
            char el = st.top();
           while (el != '(') { // n
                st.pop();
                postfix.push_back(el);
                el = st.top();
            }
            st.pop(); // 1
            // lets assume input is a valid infix
        } else { // we have operator here
            while (!st.empty()) { // n-4, 5, 6
                char tp = st.top();
                if (isOprtr(tp)) {
                    if (infix[i] == '^' && tp == '^') {
                         break;
                    }
                    if (preced(infix[i]) <= preced(tp)) {
                        st.pop();
                        postfix.push_back(tp); // 1
                    } else {
                        break;
                    }
                } else {
                    break;
                }
            }

            st.push(infix[i]); // 1
                    
            
        } 
    }


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