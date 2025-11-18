#include<iostream>
#include<vector>
using namespace std;

void countingSort(vector<int>& arr) {
   // find the max from the input array
   int max = arr[0];
   for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
   }

   // create array with max+1 size
   vector<int> count(max+1, 0);

   // traverse the input array, value become index
   for (int i = 0; i < arr.size(); i++) {
        int idx = arr[i];
        count[idx]++;
   }

   // traverse the count array, rebuild sorted array
   int idx = 0;
   for (int i = 0; i < count.size(); i++) {
    while (count[i] > 0) {
        arr[idx] = i;
        idx++;
        count[i]--;
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
    countingSort(arr);
    displayArr(arr);

    return 0;
}