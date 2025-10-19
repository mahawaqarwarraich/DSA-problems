#include<iostream>
#include<vector>
using namespace std;

void makeGreater(int gt, int sm, int& moves, vector<int>& nums) {
    // while (nums[sm] >= nums[gt]) {
    //     nums[sm]--;
    //     moves++;
    // }


    // My thinking
    // int temp = nums[sm]-nums[gt];
    // temp++;
    // nums[sm] = temp;
    // moves += temp;

    // Correct
    int requiredMoves = nums[sm] - (nums[gt] - 1);
    nums[sm] = nums[gt] - 1;
    moves += requiredMoves;
    }

int minEven(vector<int> nums) {
    int moves = 0;
    // set the target
    int len = nums.size();
    int target;
    if (len%2 == 0) {
        target = len-1;
    } else {
        target = len;
    }
    // main program
    for (int i = 0; i < target; i++) {
        if (i%2 == 0) {
            if (i == 0 && nums[i+1] >= nums[i]) {
               makeGreater(i, i+1, moves, nums);
            } else if (i == len-1 && nums[i-1] >= nums[i]) {
                makeGreater(i, i-1, moves, nums);
            } else {
                if (nums[i-1] >= nums[i]) {
                    makeGreater(i, i-1, moves, nums);
                } else if (nums[i+1] >= nums[i]) {
                    makeGreater(i, i+1, moves, nums);
                }
            }
        }
    }

    return moves;
}

int minOdd(vector<int> nums) {
    int moves = 0;
    // set the target
    int len = nums.size();
    int target;
    if (len%2 == 0) {
        target = len;
    } else {
        target = len-1;
    }
    // main program
    for (int i = 0; i < target; i++) {
        if (i%2 != 0) {
            if (i == len-1 && nums[i-1] >= nums[i]) {
               makeGreater(i, i-1, moves, nums);
            }  else {
                if (nums[i-1] >= nums[i]) {
                    makeGreater(i, i-1, moves, nums);
                } else if (nums[i+1] >= nums[i]) {
                    makeGreater(i, i+1, moves, nums);
                }
            }
        }
    }

    return moves;

}

int minMovs(vector<int> nums) {
    int evenMovs = minEven(nums);
    int oddMovs = minOdd(nums);

    if (evenMovs < oddMovs) {
        return evenMovs;
    } else {
        return oddMovs;
    }
}


int main() {
    vector<int> nums = {9,6,1,6,2};
    int ans  = minMovs(nums);
    cout << ans;
    return 0;
}