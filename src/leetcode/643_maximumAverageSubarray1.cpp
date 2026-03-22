// https://leetcode.com/problems/maximum-average-subarray-i/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double currSum = 0;
        double maxSum = 0;

        for (int i = 0; i < k; i++) {
            currSum += nums[i];
        }
        maxSum = currSum;
        for (int i = k; i < nums.size(); i++) {
            currSum = currSum + nums[i] - nums[i - k];
            maxSum = max(maxSum, currSum);
        }
        return maxSum / k;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 5, 7, 4, 9};
    int k = 3;
    cout << "maxAverage = " << sol.findMaxAverage(nums, k) << endl;
    return 0;
}