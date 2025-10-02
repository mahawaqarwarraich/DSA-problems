#include<iostream>
#include<vector>
using namespace std;


int findDuplicates(vector<int> arr) {
    if (arr.size() == 0 || arr.size() == 1) {
        return -1;
    }
    
    int slow = arr[0];
    int fast = arr[0];

    // finding the point of collision using tortoise and hair method, treating array as the linked list with cycle.
    do {
        slow = arr[slow];
        fast = arr[arr[fast]];
    } while (slow != fast);// see you there hai

    // Now have two slow pointers, their point of collision would be the answer
    int slow2 = arr[0];
    while (slow != slow2) {
        slow = arr[slow];
        slow2 = arr[slow2];
    }

    return slow;

}

int main() {
    vector<int> arr = {3, 3, 4, 2, 1};
    int duplicate = findDuplicates(arr);
    cout << "the duplicate element in the give array is: " << duplicate;
    return 0;
    
}