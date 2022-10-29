// https://leetcode.com/problems/largest-divisible-subset/description/
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int length = nums.size();
        vector<int> lids(length, 1);

        int lengthOfLids = 1;
        for(int i=1;i<length;i++) {
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j] == 0) {
                    lids[i] = max(lids[i], 1 + lids[j]);
                    lengthOfLids = max(lengthOfLids, lids[i]);
                }
            }
        }

        // for(int i=0;i<length;i++) {
        //     cout<<lids[i]<<" ";
        // }
        // cout<<endl;

        vector<int> result;
        int lastNumber = -1;
        for(int i=length-1;i>=0;i--) {
            if(lids[i] == lengthOfLids && (lastNumber == -1 || lastNumber%nums[i] == 0)) {
                result.push_back(nums[i]);
                lengthOfLids--;
                lastNumber = nums[i];
            }
        }
        return result;
    }
};