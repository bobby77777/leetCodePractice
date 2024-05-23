class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int total = accumulate(nums.begin(), nums.end(), 0);
        int leftTotal = 0;
        int rightTotal = 0;
        for (int i = 0; i < nums.size(); i++) {
            rightTotal = total - leftTotal - nums[i];
            if (rightTotal == leftTotal) {
                return i;
            }
            leftTotal += nums[i];
        }
        return -1;
    }
};