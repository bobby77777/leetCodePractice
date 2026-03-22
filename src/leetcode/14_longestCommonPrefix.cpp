#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int answerLength = static_cast<int>(strs[0].length());

        for (int i = 1; i < static_cast<int>(strs.size()); i++) {
            int j = 0;
            while (j < static_cast<int>(strs[i].length()) && strs[i][j] == strs[0][j]) {
                j++;
            }
            answerLength = min(answerLength, j);
        }

        return strs[0].substr(0, answerLength);
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};
    Solution sol;
    cout << sol.longestCommonPrefix(strs) << endl;
    return 0;
}
