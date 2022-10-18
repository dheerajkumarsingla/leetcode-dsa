// https://leetcode.com/problems/shortest-unsorted-continuous-subarray/description/
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int minValue = INT_MIN;
        int findMinInRightSubarray = 0;

        int maxValue = INT_MAX;
        int findMaxInRightSubArray = 0;

        int n = nums.size();

        for(int i=1;i<n;i++) {
            if(findMinInRightSubarray == 1) {
                minValue = min(minValue, nums[i]);
            }
            else if(nums[i] < nums[i-1]) {
                findMinInRightSubarray = 1;
                minValue = nums[i];
            }
        }
        for(int i=n-2;i>=0;i--) {
            if(findMaxInRightSubArray == 1) {
                maxValue = max(maxValue, nums[i]);
            }
            else if(nums[i] > nums[i+1]) {
                findMaxInRightSubArray = 1;
                maxValue = nums[i];
            }
        }
        cout<<minValue<<" "<<maxValue<<endl;
        if(minValue == INT_MIN && maxValue == INT_MAX) {
            return 0;
        }
        int leftIndex = 0;
        for(int i=0;i<n;i++) {
            if(nums[i] > minValue) {
                leftIndex = i;
                break;
            }
        }
        int rightIndex = 1;
        for(int i=n-1;i>=0;i--) {
            if(nums[i] < maxValue) {
                rightIndex = i;
                break;
            }
        }
        cout<<leftIndex<<" "<<rightIndex<<endl;
        return rightIndex - leftIndex + 1;
    }
};