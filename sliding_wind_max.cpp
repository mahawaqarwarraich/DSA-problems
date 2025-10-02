#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(const vector<int>& nums, int k) {
    deque<int> dq; // will store indices of useful elements
    vector<int> result;

    for (int i = 0; i < nums.size(); i++) { // n
        // 1️⃣ Remove indices from the front that are out of the current window
        while (!dq.empty() && dq.front() <= i - k) // n
            dq.pop_front();

        // 2️⃣ Remove indices from the back whose values are less than current element
        while (!dq.empty() && nums[dq.back()] <= nums[i]) // k
            dq.pop_back();

        // 3️⃣ Add current index
        dq.push_back(i); // 1

        // 4️⃣ Store the max for the current window
        if (i >= k - 1)
            result.push_back(nums[dq.front()]); // 1
    }

    return result;
}

// Time c

int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    int k = 3;
    vector<int> ans = slidingWindowMax(nums, k);

    cout << "Sliding window maximums: ";
    for (int x : ans)
        cout << x << " ";
    cout << endl;
}

