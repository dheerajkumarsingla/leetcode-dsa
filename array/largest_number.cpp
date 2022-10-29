// https://leetcode.com/problems/largest-number/description/
class Solution {
public:
    static bool compareFunc(int a, int b) {
        long long int option1 = stol(to_string(a) + to_string(b));
        long long int option2 = stol(to_string(b) + to_string(a));
        if(option1 > option2) return true;
        return false;
    }
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), compareFunc);
        
        if(nums[0] == 0) return "0";

        string result = "";
        for(int i=0;i<nums.size();i++) {
            result += to_string(nums[i]);
        }
        return result;
    }
};