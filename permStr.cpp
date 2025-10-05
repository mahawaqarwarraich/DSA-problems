#include<iostream>
#include<vector>
using namespace std;

void recPerm(int idx, string str, vector<string> &ans) {
    if (idx == str.length()-1) {
        ans.push_back(str);
        return;
    }

    for (int i = idx; i < str.length(); i++) {
        char temp = str[idx];
        str[idx] = str[i];
        str[i] = temp;
        recPerm(idx+1, str, ans);
        temp = str[idx];
        str[idx] = str[i];
        str[i] = temp;
    }
}

vector<string> findPerm(string str) {
    vector<string> ans;
    cout << "1";
    recPerm(0, str, ans);
    cout << "2";
    return ans;
}

int main() {
    string str = "abc";
    vector<string> ans = findPerm(str);
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}