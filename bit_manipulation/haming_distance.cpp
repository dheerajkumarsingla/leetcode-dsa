// https://leetcode.com/problems/total-hamming-distance/description/
class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> zerosCountAtEachPosition(32, 0);
        
        for(int i=0;i<n;i++) {
            int bit = 0;
            while(bit < 32) {
                if((nums[i] >> bit)%2 == 0) {
                    zerosCountAtEachPosition[bit] += 1;
                }
                bit++;
            }
        }

        int hammingDistance = 0;
        for(int i=0;i<32;i++) {
            hammingDistance += zerosCountAtEachPosition[i]*(n-zerosCountAtEachPosition[i]);
        }
        return hammingDistance;
    }
};