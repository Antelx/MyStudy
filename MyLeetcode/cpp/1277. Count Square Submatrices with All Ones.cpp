#include <iostream>
#include <vector>
#include <unordered_map>
#include<stack>
#include <string>
#include<algorithm>
#include<math.h>
#include "stringToIntegerVector.hpp"
using namespace std;
// 1277. Count Square Submatrices with All Ones
// Given a m * n matrix of ones and zeros, return how many square submatrices have all ones.
// Example 1:
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
// Explanation: 
// There are 10 squares of side 1.
// There are 4 squares of side 2.
// There is  1 square of side 3.
// Total number of squares = 10 + 4 + 1 = 15.
// Example 2:
// Input: matrix = 
// [
//   [1,0,1],
//   [1,1,0],
//   [1,1,0]
// ]
// Output: 7
// Explanation: 
// There are 6 squares of side 1.  
// There is 1 square of side 2. 
// Total number of squares = 6 + 1 = 7.
 
// Constraints:
// 1 <= arr.length <= 300
// 1 <= arr[0].length <= 300
// 0 <= arr[i][j] <= 1

// 计算以当前点为右下角的正方形的个数
// 难点在于O(1)空间，
// 每个点的数值与左、上、左上有关
// 判断他们三个是否相等毫无意义，取其中最小值加一即可
class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        for(int i=1;i<matrix.size();i++)
        for(int j=1;j<matrix[0].size();j++)
        if(matrix[i][j]==1)
        matrix[i][j] = min(min( matrix[i][j-1], matrix[i-1][j-1]), matrix[i-1][j]) + 1;

        
        int res = 0;
        for(auto i:matrix)
        for(auto j:i)
        res += j;
        return res;
    }
};
// Input: matrix =
// [
//   [0,1,1,1],
//   [1,1,1,1],
//   [0,1,1,1]
// ]
// Output: 15
int main(){
    
    Solution sol;
    vector<vector<int>> matrix;
    matrix.push_back(stringToIntegerVector("[0,1,1,1]"));
    matrix.push_back(stringToIntegerVector("[1,1,1,1]"));
    matrix.push_back(stringToIntegerVector("[0,1,1,1]"));
    cout << sol.countSquares(matrix) << endl;
    for(auto i:matrix)
    {
        for(auto j:i)
        cout << j << ",";
        cout << endl;
    }

    
    return 0;
}
