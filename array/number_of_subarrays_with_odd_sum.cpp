// https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/description/
#define MOD 1000000007
class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int length = arr.size();
        vector<int> prefixSum(length, 0);
        
        prefixSum[0] = arr[0];
        int ans = arr[0]%2;
        int oddCount = ans;
        int evenCount = (ans == 1)? 0 : 1;

        for(int i=1;i<length;i++) {
            prefixSum[i] = prefixSum[i-1] + arr[i];
            if((prefixSum[i]%2) == 0) {
                ans = (ans + oddCount) % MOD;
                evenCount++;
            }
            else {
                ans = (ans + 1) % MOD;
                ans = (ans + evenCount) % MOD;
                oddCount++;
            }
        }
        // for(int i=0;i<length;i++) {
        //     cout<<prefixSum[i]<<" ";
        // }
        // cout<<endl;
        return ans;
    }
};