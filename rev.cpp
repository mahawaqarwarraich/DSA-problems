#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> slidingWindowMax(const vector<int>& nums, int k) {
   deque<int> dq;
   vector<int> res;

   for (int i = 0; i < nums.size(); i++) {
    // remove small indeces before this index
    while (!dq.empty() && nums[dq.back()] <= nums[i]) {
        dq.pop_back();
    }

    // remove out of range indeces
    while (!dq.empty() && dq.front() <= i-k)  {
        dq.pop_front();
    }

    // add the index
    dq.push_back(i);

    // if k size is reached return the front
    if (i >= k-1 && !dq.empty()) {
        res.push_back(dq.front());
    }



   }
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

