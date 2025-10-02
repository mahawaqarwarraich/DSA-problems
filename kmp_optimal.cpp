#include<iostream>
#include<vector>
using namespace std;

void constructLPS(string pattern, vector<int>& lps) {
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

vector<int> search(string pat, string text, vector<int>& res) {
    int n = text.size();
    int m = pat.size();
    vector<int> lps(m, 0);
   constructLPS(pat, lps); // O(m)
     // pointer i and j for traversing text and pattern
    int i = 0;
    int j = 0;
    while (i < n) {
        // if characters match move both pointer forward
        if (text[i] == pat[j]) {
            i++;
            j++;
            // if entire pattern is matched 
            // store the start index in res
            if (j == m) {
                res.push_back(i-j);
               //  j = 0;
               j = lps[j-1];
            }


        } else {
            // lps value of prev index to avoid redundant comparisons
            if (j != 0) {
                j = lps[j-1];
            } else {
                i++;
            }
        }
    }
    return res;
}

int main() {
    string pattern = "abc";
    string text = "abcdabc";
    vector<int> res;
    search(pattern, text, res);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
    return 0;
}