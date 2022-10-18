// https://leetcode.com/problems/next-permutation/
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int lastPermutation = 1;
        for(int i=n-2;i>=0;i--) {
            if(!(nums[i] >= nums[i+1])) {
                lastPermutation = 0;
                break;
            }
        }
        if(lastPermutation == 1) {
            reverse(nums.begin(), nums.end());
            return;
        }

        int swapIndex1 = 0;
        for(int i=n-2; i>=0; i--) {
            if(nums[i] < nums[i+1]) {
                swapIndex1 = i;
                break;
            }
        }

        int swapIndex2 = 0;
        for(int i=n-1; i>=0; i--) {
            if(nums[i] > nums[swapIndex1]) {
                swapIndex2 = i;
                break;
            }
        }
        iter_swap(nums.begin() + swapIndex1, nums.begin() + swapIndex2);
        reverse(nums.begin() + swapIndex1 + 1, nums.end());
    }
};