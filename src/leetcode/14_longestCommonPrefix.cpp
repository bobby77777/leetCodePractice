#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int ans = strs[0].length(), n = strs.size();
        for(int i = 1; i < n; i++){
            int j = 0;
            while(j < strs[i].length() && strs[i][j] == strs[0][j])
                j++;
            ans = min(ans, j);
        }
        return strs[0].substr(0, ans);
    }
};

int main() {
    vector<string> strs;
    strs.push_back("flower");
    strs.push_back("flow");
    strs.push_back("flight");
    // cout << strs[0].substr(0, 0) << endl;
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}