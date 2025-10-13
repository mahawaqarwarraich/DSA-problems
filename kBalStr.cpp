#include<iostream>
#include<vector>
#include<map>
using namespace std;

bool isKBal(int start, int end, string s) {
    int mid = (start+end)/2;
    int itr1 = start;
    int itr2 = mid+1;

    while (itr1 <= mid) {
        if (s[itr1] == ')' || s[itr2] == '(') {
            return false;
        }
        itr1++;
        itr2++;
    }

    return true;
}

 string removeSubstring(string s, int k) {
   
    // To get k Balance ranges
        k += k;
        int strLen = s.length();
        vector<vector<int>> kBalRanges;
        for (int i = 0; i <= (strLen-k); i++) {
            int start = i;
            int end = start + (k-1);

            bool kBal = isKBal(start, end, s);
            if (kBal) {
                kBalRanges.push_back({start, end});
            }
        }

        // First making all indeces valid/true;
        
        vector<bool> indecesType(strLen, 1);

        // Make some indeces false/invalid for the final string by using k Balance ranges array
         
        for (int i = 0; i < kBalRanges.size(); i++) {
            int start = kBalRanges[i][0];
            int end = kBalRanges[i][1];

            for (int j = start; j <= end; j++) {
                indecesType[j] = 0;
            }

        }

        // Build the final string
         
         string finalStr = ""; 

        for (int i = 0; i < indecesType.size(); i++) {
            if (indecesType[i]) {
              
                 finalStr += s[i];
            }
        }


        return finalStr;

    }


int main() {
    string s =  "(())"; // (())
    int k = 1;
    string finalStr = removeSubstring(s, k);
    cout << "asnwer: " << finalStr;
    return 0;
}