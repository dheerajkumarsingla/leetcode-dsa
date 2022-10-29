// https://leetcode.com/problems/rearrange-array-elements-by-sign/description/
class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int length = nums.size();
        vector<int> result(length);
        int pp = 0;
        int np = 1;
        for(int i=0;i<length;i++) {
            if(nums[i] > 0) {
                result[pp] = nums[i];
                pp += 2;
            }
        }
        for(int i=0;i<length;i++) {
            if(nums[i] < 0) {
                result[np] = nums[i];
                np += 2;
            }
        }
        return result;
    }
};