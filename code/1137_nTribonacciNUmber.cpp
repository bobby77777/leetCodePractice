#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    int tribonacci(int n) {
        unordered_map<int, int> memo;
        return helper(n, memo);
        
    }
private:
    int helper(int n, unordered_map<int, int>& memo) {
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }
        int result;
        if (n == 0) {
            result = 0;
        } else if (n == 1 || n == 2) {
            result =  1;
        } else {
            result = helper(n - 1, memo) + helper(n - 2, memo) + helper(n - 3, memo);
        }
        memo[n] = result;
        return result;
    }
};

int main() {
    Solution sol;
    cout << sol.tribonacci(5) << endl;
    // unordered_map<int, bool> um; 
  
    // um[12] = true; 
    // um[6789] = false; 
    // um[456] = true;
    // if (um.find(23) == um.end()) 
    //     cout << "Element Not Present\n"; 
    // else
    //     cout << "Element Present\n"; 
    return 0;
}