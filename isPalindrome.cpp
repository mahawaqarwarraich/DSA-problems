#include<iostream>
using namespace std;




bool checkPalindrome(string x) {
    int left = 0;
    int right = x.size()-1;

    while (left < right) {
        if (x[left] != x[right]) {
            return false;
        }
        left++;
        right--;
    }

    return true;


}

// see you there in the middle of chaose i see you the last glossign o laptop may i love my app the i love myself 
int main () {
    string x = "aabbaa";
    int res = checkPalindrome(x);
    if (res) {
        cout << "yes a damn palindrome";
    } else {
        cout << "not a palindrom bro";
    }
    return 0;
}