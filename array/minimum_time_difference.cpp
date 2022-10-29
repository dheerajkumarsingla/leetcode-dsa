// https://leetcode.com/problems/minimum-time-difference/description/
class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int ans = INT_MAX;
        int n = timePoints.size();
        vector<int> timestamps(n);
        for(int i=0;i<n;i++) {
            int hours = stoi(timePoints[i].substr(0,2));
            int minutes = stoi(timePoints[i].substr(3,2));
            int timeStamp = hours*60 + minutes;
            timestamps[i] = timeStamp;
            // for(int j=i+1;j<timePoints.size();j++) {
            //     int chours = stoi(timePoints[j].substr(0,2));
            //     int cminutes = stoi(timePoints[j].substr(3,2));
            //     int ctimeStamp = chours*60 + cminutes;
            //     ans = min(ans, min((ctimeStamp - timeStamp + 1440)%1440, (timeStamp - ctimeStamp + 1440)%1440));
            //     // cout<<timeStamp<<" "<<ctimeStamp<<endl;
            // }
        }
        sort(timestamps.begin(), timestamps.end());

        for(int i=1;i<n;i++) {
            ans = min(ans, timestamps[i] - timestamps[i-1]);
        }
        ans = min(ans, (timestamps[0] - timestamps[n-1] + 1440)%1440);
        return ans;
    }
};