# Count Square Submatrices with all 1s

'''
Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.

Example 1:
Input: matrix =
[
  [0,1,1,1],
  [1,1,1,1],
  [0,1,1,1]
]
Output: 15
Explanation: 
There are 10 squares of side 1.
There are 4 squares of side 2.
There is  1 square of side 3.
Total number of squares = 10 + 4 + 1 = 15.
'''

Constraints:

1 <= arr.length <= 300
1 <= arr[0].length <= 300
0 <= arr[i][j] <= 1

Time Complexity:- O(m*n)
Space Complexity:- O(m*n)


class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        
        int m = matrix.size();
        if(m==0) return 0;
        int n = matrix[0].size();
        int res = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j]==0) continue;
                if(i==0 || j==0){
                    res++;
                    continue;
                } 
                
                int minValue = min(matrix[i-1][j-1],min(matrix[i][j-1],matrix[i-1][j]));
                matrix[i][j]+=minValue;
                res+=matrix[i][j];
            }
        }
        return res;
    }
};
