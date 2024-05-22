// https://leetcode.com/problems/max-number-of-k-sum-pairs/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int left = 0;
        int right = nums.size() - 1;
        int count = 0;
        sort(nums.begin(), nums.end());
        while (left < right) {
            if (nums[left] + nums[right] == k) {
                left++;
                right--;
                count++;
            } else if (nums[left] + nums[right] < k) {
                left++;
            } else {
                right--;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 3, 7, 9, 1, 5, 8};
    int k = 10;
    cout << "maxOperations = " << sol.maxOperations(nums, k) << endl;
}