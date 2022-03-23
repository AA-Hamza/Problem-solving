/*
 *  Problem Link https://leetcode.com/problems/contains-duplicate-ii/
 */
class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_set<int> window;
        int end = 0, start = 0;
        while (end < nums.size()) {
            if (window.count[nums[end]] == 0) {
                window.insert[nums[end]];
            }
            else {
                return true;
            }

            if (end-start+1 > k) {
                window.erase(nums[start++]);
            }
            end++;
        }
        return false;
    }
};
