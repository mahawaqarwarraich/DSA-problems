#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBal(string s) {
        unordered_map<char, int> freq;
        for (int i = 0; i < s.length(); i++) {
            freq[s[i]]++;
        }

        for (auto& pair: freq) {
            char first = pair.first;
            static int target = freq[first];
            
            if (freq[first] != target) {
                return false;
            }
        }

        return true;
    }

    int longestBalanced(string s) {
        vector<string> sub;
        for (int i = 0; i < s.length(); i++) {
            string subStr = "";
            for (int j = i; j < s.length(); j++) {
                subStr += s[j];
                sub.push_back(subStr);
            }
        }

        // ✅ Show all substrings
        cout << "All Substrings:\n";
        for (auto &str : sub) {
            cout << str << endl;
        }
        cout << "---------------------\n";

        int maxLen = INT_MIN;

        // ✅ Show only balanced substrings
        cout << "Balanced Substrings:\n";
        for (int i = 0; i < sub.size(); i++) {
            if (isBal(sub[i])) {
                cout << sub[i] << endl; // ← Print Balanced Substring
                int subStrLen = sub[i].length();
                if (subStrLen > maxLen) {
                    maxLen = subStrLen;
                }
            }
        }

        cout << "---------------------\n";
        return maxLen;
    }
};

int main() {
    Solution obj;
    string s;

    // 🖥️ Input from user
    cout << "Enter a string: ";
    cin >> s;

    int result = obj.longestBalanced(s);
    cout << "Longest Balanced Substring Length = " << result << endl;

    return 0;
}
