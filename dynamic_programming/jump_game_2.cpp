// https://leetcode.com/problems/jump-game-ii/
#define INFINITE INT_MAX;
using ll = long long int;
class Solution {
public:
    ll jumpsRequiredInt(vector<int>& nums,vector<ll>& dp, int currentIndex) {
        int lastPosition = nums.size() - 1;
        if(lastPosition == currentIndex) {
            return 0;
        }
        if(currentIndex > lastPosition) {
            return INFINITE;
        }
        if(dp[currentIndex] != -1) {
            return dp[currentIndex];
        }

        ll jumpsrequired =  INFINITE;
        for(int jumpStep=1; jumpStep<=nums[currentIndex]; jumpStep++) {
            jumpsrequired = min(jumpsrequired, 1 + jumpsRequiredInt(nums, dp, currentIndex+jumpStep));
        }
        dp[currentIndex] = jumpsrequired;

        return dp[currentIndex];
    }
    int jump(vector<int>& nums) {
        vector<ll> dp(nums.size(), -1);
        int currentIndex = 0;
        int ans = (int)jumpsRequiredInt(nums, dp, currentIndex);
        return ans;
    }
};