#include<iostream>
#include<vector>
using namespace std;

void bubbleSort(vector<int>& arr) {
   for (int i = 0; i < arr.size()-1; i++) {
    for (int j = 0; j < arr.size()-i-1; j++) {
        if (arr[j] > arr[j+1]) {
            swap(arr[j], arr[j+1]);
        }
    }
   }

   
}

void displayArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2};
    bubbleSort(arr);
    displayArr(arr);

    return 0;
}