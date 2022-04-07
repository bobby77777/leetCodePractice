#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> merge (nums1.size()+nums2.size());
        int i = 0; //merge's Index
        int j = 0; //mums1's Index
        int k = 0; //nums2's Index
        int n = nums1.size();
        int m = nums2.size();
        while (i < (n+m)) {
            if (j < n && k < m) {
                if (nums1[j] < nums2[k]) {
                    merge[i] = nums1[j];
                    j++;
                } else {
                    merge[i] = nums2[k];
                    k++;
                }
            } else if (j < n) {
                merge[i] = nums1[j];
                j++;
            } else if (k < m) {
                merge[i] = nums2[k];
                k++;
            } else {
                break;
            }
            i++;
        }
        int medianIndex = merge.size() / 2;
        return merge.size() % 2 ? merge[medianIndex] : (merge[medianIndex] + merge[medianIndex-1]) / 2.0;
    }
};

int main() {
    // vector<int> num1 = {1, 2, 3, 4}, num2 = {9, 10};
    vector<int> num1, num2;
    num1.push_back(1); num1.push_back(2); num1.push_back(3);
    num2.push_back(8); num2.push_back(9); num2.push_back(10); num2.push_back(11);
    Solution sol;
    cout << sol.findMedianSortedArrays(num1, num2) << endl;
    return 0;
}