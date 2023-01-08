// https://leetcode.com/problems/search-in-rotated-sorted-array/description/
class Solution {
public:
    int findTarget(vector<int>& nums, int si, int ei, int target) {
        int csi = si;
        int cei = ei;

        while(csi <= cei) {
            int mid = csi + (cei - csi)/2;
            if(nums[mid] > target) {
                cei = mid - 1;
            }
            else if(nums[mid] < target) {
                csi = mid + 1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        int si = 0;
        int ei = n - 1;
        int ref = nums[ei];

        while(si < ei) {
            int mid = si + (ei-si)/2;
            if(nums[mid] < ref) {
                ei = mid - 1;
            }
            else {
                si = mid + 1;
            }
        }
        int fsubArraySi = 0;
        int fsubArrayEi = nums[si] > ref? si: si-1;

        int ssubArraySi = nums[si] > ref? si+1: si;
        int ssubArrayEi = n-1;

        int searchResult = findTarget(nums, fsubArraySi, fsubArrayEi, target);

        return searchResult == -1? findTarget(nums, ssubArraySi, ssubArrayEi, target): searchResult;
    }
};