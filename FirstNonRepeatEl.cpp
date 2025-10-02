#include<iostream>
#include<unordered_map>
using namespace std;


int firstNRE(string str) {
    unordered_map<char, int> charCount;

    // calculate character count;
    for (int i = 0; i < str.length(); i++) {
        charCount[i]++;
    }

    // Return the answer
    for (int i = 0; i < str.length(); i++) {
        if (charCount[i] == 1) {
            return str[i];
        }
    }

    return -1;
}


int main() {
    string str = "hello";
    char ans = firstNRE(str);
    cout << "The first non repeating element is: " << ans;
    return 0;
}