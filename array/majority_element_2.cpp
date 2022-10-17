// https://leetcode.com/problems/majority-element-ii/description/
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int firstCandidate = INT_MAX;
        int secondCandidate = INT_MAX;
        int firstCandidateCount = 0;
        int secondCandidateCount = 0;

        for(int i=0;i<nums.size();i++) {
            if(nums[i] == firstCandidate) {
                firstCandidateCount++;
            }
            else if(nums[i] == secondCandidate) {
                secondCandidateCount++;
            }
            else if(firstCandidateCount == 0){
                firstCandidate = nums[i];
                firstCandidateCount++;
            }
            else if(secondCandidateCount == 0){
                secondCandidate = nums[i];
                secondCandidateCount++;
            }
            else {
                firstCandidateCount--;
                secondCandidateCount--;
            }
        }
        firstCandidateCount = 0;
        secondCandidateCount = 0;
        int targetFreq = nums.size()/3;
        for(int i=0;i<nums.size();i++) {
            if(firstCandidate == nums[i]) {
                firstCandidateCount++;
            }
            else if(secondCandidate == nums[i]) {
                secondCandidateCount++;
            }
        }
        vector<int> result;
        if(firstCandidateCount > targetFreq) {
            result.push_back(firstCandidate);
        }
        if(secondCandidateCount > targetFreq) {
            result.push_back(secondCandidate);
        }
        return result;
    }
};
