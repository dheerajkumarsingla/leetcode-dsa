// https://leetcode.com/problems/remove-all-ones-with-row-and-column-flips/
class Solution {
public:
    bool removeOnes(vector<vector<int>>& grid) {
        int n = grid.size();
        if(n == 0) return true;

        int m = grid[0].size();
        if(n == 1 && m == 1) return true;

        for(int c=0;c<m;c++) {
            if(grid[0][c] == 1) {
                for(int r=0;r<n;r++) {
                    grid[r][c] ^= 1;
                }
            }
        }
        for(int r=0;r<n;r++) {
            int count = 0;
            for(int c=0;c<m;c++) {
                count += grid[r][c];
            }
            if(count != 0 && count != m) {
                return false;
            }
        }
        return true;

    }
};