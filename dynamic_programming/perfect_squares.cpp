// https://leetcode.com/problems/perfect-squares
class Solution {
public:
    int numSquaresInt(int n, vector<int> &dp) {
        if(n == 0) {
            return 0;
        }
        
        if(n == 1) {
            return 1;
        }
        if(dp[n] != -1) {
            return dp[n];
        }
        int minNumberRequired = INT_MAX;
        for(int i=1; i*i<=n; i++) {
            minNumberRequired = min(minNumberRequired, 1 + numSquaresInt(n - i*i, dp));
        }
        dp[n] = minNumberRequired;
        return dp[n];
    }
    int numSquares(int n) {
        vector<int> dp(n+1, -1);
        int numSquaresAns = numSquaresInt(n, dp);
        return numSquaresAns;
    }
};