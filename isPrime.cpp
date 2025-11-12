#include<iostream>
using namespace std;

bool isPrime(int num) {
    int count = 0;
    for (int i = 1; i*i <= num; i++) {
        if (num%i == 0) {
            count++;
            if (num/i != i) {
                count++;
            }
        }
        if (count > 2) {
            return false;
        }
    }
    return true;
}


int main() {
    int res = isPrime(8);
    if (res) {
        cout << "yes";
    } else {
        cout << "no";
    }
    return 0;
}