#include<iostream>
#include<vector>
using namespace std;

void mergeSortArrs(vector<int> &arr1, vector<int> &arr2, vector<int> &arr3) {
    int i = 0;
    int j = 0;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] < arr2[j]) {
            arr3.push_back(arr1[i]);
            i++;
        } else {
            arr3.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
         arr3.push_back(arr1[i]);
            i++;
    }

     while (j < arr2.size()) {
          arr3.push_back(arr2[j]);
            j++;
    }


}


int main() {
    vector<int> arr1 = {99, 100, 101};
    vector<int> arr2 = {2, 3, 103};
    vector<int> arr3; 

    mergeSortArrs(arr1, arr2, arr3);

    for (int i = 0; i < arr3.size(); i++) {
        cout << arr3[i] << " ";
    }

    return 0;
}