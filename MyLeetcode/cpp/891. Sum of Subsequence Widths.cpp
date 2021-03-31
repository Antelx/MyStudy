#include <iostream>
#include <vector>
#include <unordered_map>
#include<stack>
#include <string>
#include<algorithm>
#include<math.h>
#include "stringToIntegerVector.hpp"

using namespace std;
// 891. Sum of Subsequence Widths
// Given an array of integers A, consider all non-empty subsequences of A.
// For any sequence S, let the width of S be the difference between 
// the maximum and minimum element of S.
// Return the sum of the widths of all subsequences of A. 
// As the answer may be very large, return the answer modulo 10^9 + 7.

// Example 1:
// Input: [2,1,3]
// Output: 6
// Explanation:
// Subsequences are [1], [2], [3], [2,1], [2,3], [1,3], [2,1,3].
// The corresponding widths are 0, 0, 0, 1, 1, 2, 2.
// The sum of these widths is 6.
 
// Note:
// 1 <= A.length <= 20000
// 1 <= A[i] <= 20000

//排序
//找出每个片段出现多少次
//优化，简化算式，看每个点出现多少次
class Solution {
public:
    // long long p(int x, int y)
    // {
    //     int ret = 1;
    //     for(int i=0;i<y;i++)
    //     {
    //         ret *= x;
    //         if (ret > 1000000007)
    //         ret %= 1000000007;
    //     }
    //     return ret;
    // }
    int sumSubseqWidths(vector<int>& A) {
        sort(A.begin(), A.end());
        int len = A.size();
        long long ret = 0;
        long long mod = 1000000007;
        // for(int i=0; i<len-1; i++)
        // {
        //     if(A[i+1] == A[i])
        //     continue;
        //     ret += (A[i+1] - A[i]) * (p(2, i+1)-1) *  (pow(2, len-i-1)-1) ;
        //     ret %= mod;
        // }        
        long long a = 1;
        for(int i=0; i<len; i++)
        {
            ret += (A[i] * a) % mod;
            ret -= (A[len-i-1] * a)%mod;
            a = (a * 2) % mod;
            ret = ret % mod;
        }
        return (ret+mod)%mod;
    }
};


int main(){
    
    Solution sol;
    
    auto vec = stringToIntegerVector("[1,5,6,8]");
   
    //auto vec = stringToIntegerVector("[5,69,89,92,31,16,25,45,63,40,16,56,24,40,75,82,40,12,50,62,92,44,67,38,92,22,91,24,26,21,100,42,23,56,64,43,95,76,84,79,89,4,16,94,16,77,92,9,30,13]");
    // auto vec = stringToIntegerVector("[64,90,54,84,99,67,9,81,100,52,66,37,32,14,14,23,31,82,96,81,96,22,17,68,3,88,59,54,23,22,77,61,16,46,22,94,50,29,46,7,33,22,99,31,99,75,67,95,54,31]");
    cout<<sol.sumSubseqWidths(vec)<<endl;
    
    return 0;
}
