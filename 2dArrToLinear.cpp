#include<iostream>
using namespace std;

int getOffset(int i, int j, int rows, int cols) {
    // for row major as in c, c++, java
    return i * cols + j;

    // for col major it would be
    // return j * rows + i;
}

int main() {
    int rows = 2;
    int cols = 3;
    int i = 1;
    int j = 1;

    int val = getOffset(i, j, rows, cols);

    cout << "the offset is : " << val;
    return 0;
}