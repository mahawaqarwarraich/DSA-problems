#include<iostream>
#include<vector>
using namespace std;

void insertionSort(vector<int>& arr) {
   for (int i = 1; i < arr.size(); i++) {
    int j = i-1;
    int key = arr[i]; // current value to be inserted

    while (key < arr[j] && j >= 0) {
        arr[j+1] = arr[j];
        j--;
    }

    arr[j+1] = key; // insert

   }
   
}

void displayArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2};
    insertionSort(arr);
    displayArr(arr);

    return 0;
}