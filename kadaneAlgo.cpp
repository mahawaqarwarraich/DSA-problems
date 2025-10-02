#include<iostream>
#include<vector>
using namespace std;

// Kadane's algorithm (to find the max contiguous sum)

void maxContSum(vector<int> &arr) {
    int sum = 0;
    int max = INT_MIN;
    int start;
    int end;

    for (int i = 0; i < arr.size(); i++) {
        if (sum == 0) start = i;
        sum += arr[i];

        if (sum < 0) {
            sum = 0;
        }

        if (sum > max){
            max = sum;
            end = i;
            cout << "For the sub array " << start << " to " << end << " , the max is: "  << max;
        }
    }

    
}

int main() {
    vector<int> arr = {-2, -3, 4, -1, -2, 1, 5, -3};
    maxContSum(arr);
   
    return 0;
}