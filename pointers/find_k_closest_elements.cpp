// https://leetcode.com/problems/find-k-closest-elements/description/
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int arrSize = arr.size();
        int leftPointer = 0;
        int rightPointer = arrSize - 1;

        while(rightPointer-leftPointer+1 > k) {
            if(abs(arr[leftPointer] - x) > abs(arr[rightPointer] - x)) {
                leftPointer++;
            }
            else {
                rightPointer--;
            }
        }
        vector<int> ans(arr.begin() + leftPointer, arr.begin() + rightPointer+1);
        return ans;
    }
};