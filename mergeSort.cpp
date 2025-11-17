#include<iostream>
#include<vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end) {
    int size = (end-start)+1;
    vector<int> temp(size, 0);
    int i,j,k;
    i = start;
    j = mid+1;
    k = 0;
    while (i <= mid && j <= end) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        } else {
             temp[k] = arr[j];
             k++;
             j++;
        }
    }

    while (i <= mid) {
          temp[k] = arr[i];
          k++;
          i++;
    }

    while (j <= end) {
        temp[k] = arr[j];
        k++;
        j++;
    }

    // again copy temp to arr
    for (int i = 0; i < temp.size(); i++) {
        arr[start+i] = temp[i];
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    if (start == end) return;

    int mid = start + (end - start)/2; 
    mergeSort(arr, start, mid);
    mergeSort(arr, mid+1, end);
    merge(arr, start, mid, end);
  
}

void displayArr(vector<int>& arr) {
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
}

int main() {
    vector<int> arr = {1, 5, 4, 3, 2};
    mergeSort(arr, 0, 4);
    displayArr(arr);

    return 0;
}