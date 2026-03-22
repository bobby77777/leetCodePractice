#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1) {
            return s;
        }

        int n = static_cast<int>(s.size());
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        string longest = s.substr(0, 1);

        for (int i = 0; i < n; i++) {
            dp[i][i] = true;
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j] && (j - i == 1 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (static_cast<int>(longest.size()) < j - i + 1) {
                        longest = s.substr(i, j - i + 1);
                    }
                }
            }
        }

        return longest;
    }
};

int main() {
    Solution solution;
    string given = "abccb";
    cout << solution.longestPalindrome(given) << endl;
    return 0;
}
