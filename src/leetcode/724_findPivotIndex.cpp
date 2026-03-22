#include <iostream>
#include <numeric>
#include <vector>

using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftTotal = 0;

        for (int i = 0; i < static_cast<int>(nums.size()); i++) {
            int rightTotal = total - leftTotal - nums[i];
            if (rightTotal == leftTotal) {
                return i;
            }
            leftTotal += nums[i];
        }

        return -1;
    }
};

int main() {
    Solution sol;
    vector<int> nums {1, 7, 3, 6, 5, 6};
    cout << sol.pivotIndex(nums) << endl;
    return 0;
}
