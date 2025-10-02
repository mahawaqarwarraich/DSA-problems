#include<iostream>
#include<vector>
using namespace std;


int longLenPropPreSuff(string pattern, int n) {
    for (int len = n-1; len > 0; len--) { // prefix lenght will be always less than the n.
        bool flag = true;
        for (int i = 0; i < len; i++) {
             if (pattern[i] != pattern[n-len+i]) {
                 flag = false;
                 break;
             }
               
        }
        if (flag == true) {
            return len;
        }
    }
    return 0;
}


void fillLPS(string pattern, vector<int>& lps) {
   for (int i = 0; i < pattern.length(); i++) {
       lps[i] = longLenPropPreSuff(pattern, i+1);
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