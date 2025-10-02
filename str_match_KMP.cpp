#include <iostream>
#include <string>
#include <vector>
using namespace std;

/*
    Algorithm: KMP (Knuth-Morris-Pratt)
    Time Complexity: O(n + m)  [n = length of A, m = length of B]
    Key Trick: A rotation of A is always a substring of A+A.
*/

// Build LPS array for KMP
vector<int> buildLPS(const string& pattern) {
    vector<int> lps(pattern.size(), 0);
    int len = 0;
    for (int i = 1; i < pattern.size();) {
        if (pattern[i] == pattern[len]) {
            lps[i++] = ++len;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }
    }
    return lps;
}

// KMP Search
bool KMPSearch(const string& text, const string& pattern) {
    vector<int> lps = buildLPS(pattern);
    int i = 0, j = 0;
    while (i < text.size()) {
        if (text[i] == pattern[j]) {
            i++;
            j++;
            if (j == pattern.size()) return true; // match found
        } else {
            if (j != 0) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
    }
    return false;
}

// Check if any rotation of A is in B
bool isRotationInString(const string& A, const string& B) {
    if (A.empty() || B.empty()) return false;
    if (A.size() > B.size()) return false;

    string doubleA = A + A; // contains all rotations of A
    return KMPSearch(B, doubleA); // check if any rotation exists in B
}

int main() {
    string A = "water";
    string B = "terwaabcd";

    if (isRotationInString(A, B)) {
        cout << "Rotated substring exists!\n";
    } else {
        cout << "No rotated substring found.\n";
    }
}
