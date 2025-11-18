#include<iostream>
#include<vector>
using namespace std;

// pivot = start;

int partioningStart(vector<int>& arr, int start, int end) {
    // start is the pivot
   int idx = start;
   for (int j = start+1; j <= end; j++) {
    if (arr[j] <= arr[start]) {
        idx++;
        swap(arr[j], arr[idx]);

    }
   }
   swap(arr[idx], arr[start]);
   return idx;

}

int partioningEnd(vector<int>& arr, int start, int end) {
    // return pivot index
    int idx = start-1;
    for (int j = start; j < end; j++) {
        if (arr[j] <= arr[end]) {
            idx++;
            swap(arr[j], arr[idx]);
        }
    }
    idx++;
    swap(arr[idx], arr[end]);
    return idx;

}

void quickSort(vector<int>& arr, int start, int end) {
    if (start >= end) return;

    
    int pos = partioningStart(arr, start, end); // pivot is start

 
    // int pos = partioningEnd(arr, start, end); // pivot is end     

    quickSort(arr, start, pos-1);
    quickSort(arr, pos+1, end);

}

void displayArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2};
    quickSort(arr, 0, 4);
    displayArr(arr);

    return 0;
}