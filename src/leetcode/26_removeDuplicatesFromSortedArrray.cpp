#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <stack>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < (int)nums.size() - 1; i++) {
            if (nums[i] == nums[i+1]) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }

    void vectorList(vector<int> nums) {
        cout << "[";
        for (int x : nums) {
            cout << x << ", ";
        }
        cout << "]";
        cout << endl;
    }
};

int main() {
    Solution solution;
    vector<int> nums = {1, 1, 3, 3, 4, 6, 7, 7};
    solution.vectorList(nums);
    cout << solution.removeDuplicates(nums) << endl;
    solution.vectorList(nums);
    return 0;
}