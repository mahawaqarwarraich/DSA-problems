#include<iostream>
#include<vector>
using namespace std;


void reverseArr(vector<int> &arr) {
    int i = 0;
    int j = arr.size()-1;

    cout << "yahan bhaee";

    while (i != j && i < j) {
        cout << "suno";
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
        i++;
        j--;
    }

}


int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6};
    reverseArr(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}