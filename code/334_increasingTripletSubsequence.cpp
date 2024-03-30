#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int firstSmall = INT_MAX;
        int secondSmall = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] <= firstSmall) {
                firstSmall = nums[i];
            } else if (nums[i] <= secondSmall) {
                secondSmall = nums[i];
            } else {
                return true;
            }
        }
        return false;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2, 1, 5, 0, 4, 6};
    cout << sol.increasingTriplet(nums) << endl;
    return 0;
}