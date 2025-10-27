#include <iostream>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        static const unordered_map<char, int> intgr = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int result = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            if (i + 1 < s.length() && intgr.at(s[i]) < intgr.at(s[i + 1]))
                result -= intgr.at(s[i]);
            else
                result += intgr.at(s[i]);
        }

        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.romanToInt("MCMXCIV") << endl;  // 1994
}
