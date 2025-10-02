#include <iostream>
using namespace std;

// Compute length of string manually
int strLength(char s[]) {
    int len = 0;
    while (s[len] != '\0') len++;
    return len;
}

// Build LPS (Longest Prefix Suffix) array
void buildLPS(char pat[], int m, int lps[]) {
    int len = 0;
    lps[0] = 0;

    int i = 1;
    while (i < m) {
        if (pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if (len != 0) {
                len = lps[len - 1];
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }
}

// KMP Search
bool KMPSearch(char text[], int n, char pat[], int m) {
    int lps[1000]; // max pattern size
    buildLPS(pat, m, lps);

    int i = 0, j = 0;
    while (i < n) {
        if (text[i] == pat[j]) {
            i++;
            j++;
            if (j == m) return true; // match found
        } else {
            if (j != 0) j = lps[j - 1];
            else i++;
        }
    }
    return false;
}

// Generate rotation manually
void makeRotation(char s1[], int n, int shift, char rot[]) {
    for (int i = 0; i < n; i++) {
        rot[i] = s1[(shift + i) % n];
    }
    rot[n] = '\0';
}

int main() {
    char s1[1000], s2[1000];
    cout << "Enter first string: ";
    cin >> s1;
    cout << "Enter second string: ";
    cin >> s2;

    int n = strLength(s1);
    int m = strLength(s2);

    bool found = false;
    char rotation[1000];

    for (int shift = 0; shift < n; shift++) { // m
        makeRotation(s1, n, shift, rotation); // m

        if (KMPSearch(s2, m, rotation, n)) { // m+n
            cout << "Rotation found: " << rotation << endl;
            found = true;
        }
    }

    if (!found) cout << "No rotation of " << s1 << " found in " << s2 << endl;

    return 0;
}

