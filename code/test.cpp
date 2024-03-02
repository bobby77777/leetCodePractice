#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minPartitions(string n) {
        int length = n.length(), max = 0;
        for(int i = 0; i < length; i++) {
            if((int)n[i]-48 > max) {
                max = (int)n[i] - 48;
            }
        }
        return max;
    }

    int finalValueAfterOperations(vector<string>& operations) {
        int ans = 0;
        for(int i = 0; i < operations.size(); i++) {
            if(operations[i] == "++X" || operations[i] == "X++") {
                ans += 1;
            } else if(operations[i] == "--X" || operations[i] == "X--") {
                ans -= 1;
            }
        }
        return ans;
    }

    void solve(string digit, string output, int index, vector<string>& ans, string mapping[]) {
        if(index >= digit.length()) {
            ans.push_back(output);
            return;
        }
        int number = digit[index] - '0';
        string value = mapping[number];
        for(int i = 0; i < value.length(); i++) {
            output.push_back(value[i]); 
            solve(digit, output, index+1, ans, mapping);
            output.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        string output;
        if(digits.length() == 0){
            return ans;
        }
        int index = 0;
        string mapping[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        solve(digits, output, index, ans, mapping);
        return ans;
    }

    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        for(int i = 0; i < jewels.size(); i++) {
            for(int j = 0; j < stones.size(); j++) {
                if(jewels[i] == stones[j])
                    ans += 1;
            }
            
        }
        return ans;
    }
};


int divide(int dividend, int divisor) {
    if(abs(dividend) < abs(divisor)) return 0;
    if(dividend * divisor > 0) {
        return 1 + divide(dividend - divisor, divisor);    
    } else {
        return -1 + divide(dividend + divisor, divisor);
    }   
}

int uniquePaths(int m, int n) {
    vector<vector<int>> dp(m, vector<int> (n, 1));

    for(int i = 1; i < m; i++) {
        for(int j = 1; j < n; j++) {  
            dp[i][j] = dp[i][j-1] + dp[i-1][j];
        }
    }
    return dp[m-1][n-1];
}

int main() {
    // Solution solution;
    // string jewels = "aA";
    // string stones = "aAAbbbb";
    // cout << solution.numJewelsInStones(jewels, stones) << endl;
    // cout << divide(-2147483648, -1) << endl;
    cout << uniquePaths(10, 10) << endl;
    return 0;
}