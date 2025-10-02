#include<iostream>
#include<vector>
using namespace std;


void fillLPS(string pattern, vector<int>& lps) {
    int n = pattern.size();
    int len = 0;
    lps[0] = 0;
    int i = 1;
    while (i < n) {
        if (pattern[i] == pattern[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            // when len is zero
            if (len == 0) {
                lps[i] = 0;
                i++;
            } else {
            // when len is not zero
             len = lps[len-1];
            }
           
        }
    }
}

int main() {
    string pattern = "abababca";
    vector<int> lps(pattern.size(), 0);
    fillLPS(pattern, lps);
    for (int i = 0; i < lps.size(); i++) {
        cout << lps[i] << " ";
    }
    return 0;
}