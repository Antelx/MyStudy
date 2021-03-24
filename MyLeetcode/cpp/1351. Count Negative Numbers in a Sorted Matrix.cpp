#include <iostream>
#include <vector>
#include "stringToIntegerVector.hpp"
#include<stack>
#include <string>
using namespace std;
// 1351. Count Negative Numbers in a Sorted Matrix
// Given a m x n matrix grid which is sorted in non-increasing order both row-wise and column-wise, 
// return the number of negative numbers in grid.

// Example 1:
// // Input: grid = [[ 4, 3, 2,-1],
//                   [ 3, 2, 1,-1],
//                   [ 1, 1,-1,-2],
//                   [-1,-1,-2,-3]]
// Output: 8
// Explanation: There are 8 negatives number in the matrix.
// Example 2:

// Input: grid = [[3,2],[1,0]]
// Output: 0
// Example 3:

// Input: grid = [[1,-1],[-1,-1]]
// Output: 3
// Example 4:

// Input: grid = [[-1]]
// Output: 1
 
// Constraints:
// m == grid.length
// n == grid[i].length
// 1 <= m, n <= 100
// -100 <= grid[i][j] <= 100
 
// Follow up: Could you find an O(n + m) solution?


// // Input: grid = [[ 4, 3, 2,-1],
//                   [ 3, 2, 1,-1],
//                   [ 1, 1,-1,-2],
//                   [-1,-1,-2,-3]]


class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int ret = 0;
        int n_row = grid.size();
        int n_col = grid[0].size();
        int p1 = n_row-1;
        int p2 = 0;

        while (p1 > -1 && p2 < n_col)
        {
            if (grid[p1][p2] < 0)
            {
                ret = ret + n_col-p2;
                p1--;
            }
            else
            {
                p2++;
            }
            
        }   
        return ret;
    }
};

int main(){
    
    Solution sol;

    vector<vector<int>> grid;
    grid.push_back(stringToIntegerVector("[ 4, 3, 2,-1]"));
    grid.push_back(stringToIntegerVector("[ 3, 2, 1,-1]"));
    grid.push_back(stringToIntegerVector("[ 1, 1,-1,-2]"));
    grid.push_back(stringToIntegerVector("[-1,-1,-2,-3]"));

    int ret = sol.countNegatives(grid);
    cout << "ret:" <<ret << endl;

    system("pause");
    return 0;
}
