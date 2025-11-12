#include<iostream>
#include<vector>
using namespace std;

void selectionSort(vector<int>& arr) {
    int minIndex;
    int target1 = arr.size()-1;
    int target2 = arr.size();
    for (int i = 0; i < target1; i++) {
        minIndex = i;
        for (int j = i+1; j < target2; j++) {
            if (arr[j] < arr[i]) {
                minIndex = j;
            }
        }
        swap(arr[i], arr[minIndex]);

    }
}

void displayArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2};
    selectionSort(arr);
    displayArr(arr);

    return 0;
}