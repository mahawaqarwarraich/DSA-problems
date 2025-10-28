#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNum2(int num) {
        vector<int> romans = {1, 5, 10, 50, 100, 500, 1000};
        for (int i = romans.size()-1; i >= 0; i--) {
            if (romans[i] <= num) {
                return romans[i];
            }
        }
        return -1;
    }

    int findNum22(int num) {
        vector<int> romans = {1, 5, 10, 50, 100, 500, 1000};
        for (int i = 0; i < romans.size(); i++) {
            if (romans[i] >= num) {
                return romans[i];
            }
        }
        return -1;
    }

    string getRoman(int num) {
        static unordered_map<int, string> roman = {
            {1, "I"}, {5, "V"}, {10, "X"}, {50, "L"},
            {100, "C"}, {500, "D"}, {1000, "M"}
        };
        string res = "";
        string numStr = to_string(num);

        if (num != 4 && num != 9 && num != 40 && num != 90 && num != 400 && num != 900) {
            int sub = 1;
            while (sub != 0) {
                int num2 = findNum2(num);
                sub = num - num2;

                if (roman.find(num2) != roman.end())
                    res += roman.at(num2);

                num = abs(sub);
                if (num == 0) break;
            }
        } else {
            int num2 = findNum22(num);
            int sub = num - num2;

            if (roman.find(abs(sub)) != roman.end())
                res += roman.at(abs(sub));

            if (roman.find(num2) != roman.end())
                res += roman.at(num2);
        }

        return res;
    }

    string intToRoman(int num) {
        string s = to_string(num);
        int exp = s.length() - 1;
        string res = "";
        for (int i = 0; i < s.length(); i++) {
            int nbr = s[i] - '0';
            int numPart = nbr * pow(10, exp); // decimal place number
            if (numPart != 0) {
                string roman = getRoman(numPart);
                res += roman;
            }
            exp--;
        }
        return res;
    }
};

// ✅ Main function for testing
int main() {
    Solution sol;

    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Roman numeral: " << sol.intToRoman(n) << endl;

    return 0;
}
