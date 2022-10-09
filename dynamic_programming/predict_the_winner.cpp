// https://leetcode.com/problems/predict-the-winner
class Solution {
public:
    int predictTheWinnerInt(vector<int>& nums, vector<vector<int>> &dp, int currLeftIndex, int currRightIndex) {
        int scoresSize = nums.size();
        if(currLeftIndex < 0 || currRightIndex > scoresSize-1 || currLeftIndex > currRightIndex) {
            return 0;
        }

        if(dp[currLeftIndex][currRightIndex] != -1) {
            return dp[currLeftIndex][currRightIndex];
        }

        int maxScore = max(
            nums[currLeftIndex] + min(
                predictTheWinnerInt(nums, dp, currLeftIndex+2, currRightIndex),
                predictTheWinnerInt(nums, dp, currLeftIndex+1, currRightIndex-1)
            ),
            nums[currRightIndex] + min(
                predictTheWinnerInt(nums, dp, currLeftIndex+1, currRightIndex-1),
                predictTheWinnerInt(nums, dp, currLeftIndex, currRightIndex-2)
            )
        );
        dp[currLeftIndex][currRightIndex] = maxScore;
        return dp[currLeftIndex][currRightIndex];
    }
    bool PredictTheWinner(vector<int>& nums) {
        int scoresSize = nums.size();
        vector<vector<int>> dp(scoresSize);
        
        for(int rowIndex=0; rowIndex<scoresSize; rowIndex++) {
            dp[rowIndex].resize(scoresSize);
            for(int colIndex=0; colIndex<scoresSize; colIndex++) {
                dp[rowIndex][colIndex] = -1;
            }
        }
        int currLeftIndex = 0;
        int currRightIndex = scoresSize-1;
        int score = predictTheWinnerInt(nums, dp, currLeftIndex, currRightIndex);
        return score >= accumulate(nums.begin(), nums.end(), 0) - score;
    }
};