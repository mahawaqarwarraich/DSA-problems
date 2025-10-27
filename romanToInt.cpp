#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> intgr;
        unordered_set<string> selective;

        intgr['I'] = 1;
        intgr['V'] = 5;
        intgr['X'] = 10;
        intgr['L'] = 50;
        intgr['C'] = 100;
        intgr['D'] = 500;
        intgr['M'] = 1000;

        selective.insert("IV");
        selective.insert("IX");
        selective.insert("XL");
        selective.insert("XC");
        selective.insert("CD");
        selective.insert("CM");

        int result = 0;

        for (int i = 0; i < s.length(); i++) {
            // ✅ Check that i+1 is within bounds before using s[i+1]
            if (i + 1 < s.length()) {
                string num = "";
                num += s[i];
                num += s[i + 1];

                if (selective.find(num) != selective.end()) {
                    int x = intgr[s[i + 1]] - intgr[s[i]];
                    result += x;
                    i++; // skip next char since it's already processed
                    continue;
                }
            }

            // Normal case (single symbol)
            result += intgr[s[i]];
        }

        return result;
    }
};

int main() {
    Solution sol;

    cout << sol.romanToInt("III") << endl;    // 3
    cout << sol.romanToInt("IV") << endl;     // 4
    cout << sol.romanToInt("IX") << endl;     // 9
    cout << sol.romanToInt("LVIII") << endl;  // 58
    cout << sol.romanToInt("MCMXCIV") << endl;// 1994

    return 0;
}
