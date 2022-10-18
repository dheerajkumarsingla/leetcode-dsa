// https://leetcode.com/problems/container-with-most-water/description/
class Solution {
public:
    int maxArea(vector<int>& height) {
        int lines = height.size();
        int waterAmount = 0;
        int left = 0;
        int right = lines-1;

        while(left < right) {
            waterAmount = max(waterAmount, (right-left)*min(height[left], height[right]));
            if(height[left] < height[right]) {
                left++;
            }
            else {
                right--;
            }
        }
        return waterAmount;
    }
};