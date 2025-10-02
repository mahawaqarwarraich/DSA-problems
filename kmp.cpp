#include<iostream>
#include<vector>
using namespace std;

vector<int> lps(string pattern) {
    vector<int> lps(pattern.size(), 0);


 
}


i = 0
j = 1
count  = 0
while (j < pattern.size())
target = j;
while (i < target)
if i and j match
  count++;
  ptn[j] = count;
  increase i
  increase j 
else 
break;
i = 0
  increase j // when i shortens




bool isMatchKMP(string pattern, string text) {
    vector<int> lps = lps(pattern);

}


int main() {
    // input -> pattern and text
    // output -> yes, no
    bool ans = isMatchKMP("terwa", "terwaabcd");

    if (ans) {
        cout << "yes the substring exists in the text";
    } else {
        cout << "no the substring does exist in the text"; 
    }
    return 0;
}
