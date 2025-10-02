#include<iostream>
using namespace std;

void placeZeroEnd(int nums[], int size) {
    int idx = 0;

    for (int i = 0; i < size; i++) {
        if (nums[i] != 0) {
            if (i != idx) {
                nums[idx] = nums[i];
                nums[i] = 0;
            }
           
            idx++;
        }
    }
}

int main() {

    int nums[] = {0, 1, 0, 3, 12};
   
    int size = sizeof(nums)/sizeof(nums[0]);


    placeZeroEnd(nums, size);


    for (int i = 0; i < size; i++) {
      
        cout << nums[i] << " ";
    }
    return 0;
}