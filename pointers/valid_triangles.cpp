// https://leetcode.com/problems/valid-triangle-number/description/
class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int count = 0;
        int size = nums.size();

        if(size < 3) {
            return count;
        }

        int i=0;
        int j=1;
        int k=2;

        sort(nums.begin(), nums.end());

        while(i < size - 2) {
            j = i + 1;
            k = i + 2;
            while(j < size - 1 && nums[i] != 0){
                while(k < size && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                count += k-j-1;
                j++;
            }
            i++;
        }

        return count;
    }
};