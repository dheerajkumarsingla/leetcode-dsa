// https://leetcode.com/problems/minimum-difference-between-largest-and-smallest-value-in-three-moves/description/
class Solution {
public:
    int minDifference(vector<int>& nums) {


        int length = nums.size();
        if(length <= 4) return 0;
        partial_sort(nums.begin(), nums.begin()+4, nums.end());
        partial_sort(nums.rbegin(), nums.rbegin()+4, nums.rend(), greater<int>());

        int result = nums[length-1] - nums[0];
        for(int i=0,j=length-4; i<4; i++,j++) {
            result = min(nums[j] - nums[i], result);
        }
        return result;

        // int length = nums.size();
        // if(length <= 4) {
        //     return 0;
        // }
        // sort(nums.begin(), nums.end());
        // int leftPointer = 0;
        // int rightPointer = 1;
        // int diff = nums[rightPointer] - nums[leftPointer];

        // for(int i=1;i<length-1;i++) {
        //     if(diff > nums[i+1] - nums[i]) {
        //         leftPointer = i;
        //         rightPointer = i+1;
        //         diff = nums[rightPointer] - nums[leftPointer];
        //     }
        // }

        // int leftExtreme = 0;
        // int rightExtreme = length-1;
        // int allowedChanges = 3;

        // while(allowedChanges > 0) {
        //     int leftDelta = nums[leftPointer] - nums[leftExtreme];
        //     int rightDelta = nums[rightExtreme] - nums[rightPointer];
        //     if(leftDelta > rightDelta) {
        //         nums[leftExtreme] = nums[leftPointer];
        //         leftExtreme++;
        //     }
        //     else {
        //         nums[rightExtreme] = nums[rightPointer];
        //         rightExtreme--;
        //     }
        //     allowedChanges--;
        // }
        // return *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    }
};