#include<iostream>
using namespace std;

int factorial(int n) {
    // Iterative approach

    if (n == 0) return 0;
    if (n == 1) return 1;
   
    int first = 0;
    int second = 1;
    int third;
    int i = 1;
    while (i < n) {
        third = first + second; 
        first = second;
        second = third;
        i++;
    }
    return third;
}

// 0 1 1 2 3 5 8 13

int main() {
    int n  = 6;
    int ans = factorial(n);
    cout << "Factorial of " << n << " is : " << ans;
    return 0;
}