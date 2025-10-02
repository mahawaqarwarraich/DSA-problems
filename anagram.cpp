#include<iostream>
#include<unordered_map> 
using namespace std;

bool isAnagram(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return false;
    }


    int freq[26] = {0};
    // note freq of characs of first string
    for (int i = 0; i < s1.size(); i++) {
        int idx = s1[i]-97;
        freq[idx]++;
    }

    // now subtract for second string
    for (int i = 0; i < s2.size(); i++) {
         int idx = s2[i]-97;
         if (freq[idx] > 0) {
            freq[idx]--;
         }
           
    }

    // loop freq;
    for (int i = 0; i < 26; i++) {
        if (freq[i] > 0) {
            return false;
        }
    }

    return true;


}


int main () {
    string s1 = "efgh";
    string s2 = "aham";

    int res = isAnagram(s1, s2);

    if (res) {
        cout << "yes there are both anagram";
    } else {
        cout << "these are not anagram bro";
    }
    return 0;
}