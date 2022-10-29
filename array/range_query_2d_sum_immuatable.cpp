// https://leetcode.com/problems/range-sum-query-2d-immutable/description/
class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        for(int i=0;i<rows;i++) {
            prefixSum.resize(rows);
            for(int j=0;j<cols;j++) {
                prefixSum[i].resize(cols);
            }
        }

        for(int i=0;i<rows;i++) {
            for(int j=0;j<cols;j++) {
                if(j == 0) {
                    prefixSum[i][j] = matrix[i][j];
                }
                else {
                    prefixSum[i][j] = prefixSum[i][j-1] + matrix[i][j];
                }
            }
        }

        for(int j=0;j<cols;j++) {
            for(int i=0;i<rows;i++) {
                if(i != 0) {
                    prefixSum[i][j] += prefixSum[i-1][j];
                }
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int val1 = col1 - 1 < 0 ? 0 : prefixSum[row2][col1-1];
        int val2 = row1 - 1 < 0 ? 0 : prefixSum[row1-1][col2];
        int val3 = ((row1 - 1 ) < 0 || (col1 - 1 ) < 0)? 0 : prefixSum[row1-1][col1-1];
        return prefixSum[row2][col2] - val1 - val2 + val3;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */