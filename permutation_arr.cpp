#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

void recurPermute(vector<int> &arr, unordered_map<int,int> &usedChoices, vector<int> &permutation, vector<vector<int>> &ans) {
    if (permutation.size() == arr.size()) {
        ans.push_back(permutation);
        return;
    }

    for (int i = 0; i < arr.size(); i++) {
        if (usedChoices.find(i) == usedChoices.end()) {
            permutation.push_back(arr[i]);
            usedChoices[i] = arr[i];
            recurPermute(arr, usedChoices, permutation, ans);
            // when backtrack restore the state
            permutation.pop_back();                     
            usedChoices.erase(i);
        }
    }



}

vector<vector<int>> findPerms(vector<int> &arr) {
    unordered_map<int, int> usedChoices;
    vector<int> permutation;
    vector<vector<int>> ans;
    recurPermute(arr, usedChoices, permutation, ans);
    return ans;
}

void recurPermuteOpt(int idx, vector<int>& arr, vector<vector<int>> &ans) {
    if (idx == arr.size()) {
        ans.push_back(arr);
    }

    for (int i = idx; i < arr.size(); i++) {
        swap(arr[idx], arr[i]);
        recurPermuteOpt(idx+1, arr, ans);
        swap(arr[idx], arr[i]);
    }
}


vector<vector<int>> findPermsOpt(vector<int> &arr) {
    vector<vector<int>> ans;
    recurPermuteOpt(0, arr, ans);
    return ans;
}




int main() {
    vector<int> arr = {1, 2, 3};
   

   //  vector<vector<int>> permutations = findPerms(arr);
    vector<vector<int>> permutations = findPermsOpt(arr);
   

    for (int i = 0; i < permutations.size(); i++) {
       
        for (int j = 0; j < permutations[i].size(); j++) {
            cout << permutations[i][j] << " ";
        }
        cout << endl;
    }


    return 0;
}