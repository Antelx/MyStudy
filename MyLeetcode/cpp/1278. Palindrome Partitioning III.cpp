#include <iostream>
#include <vector>
#include <unordered_map>
#include<stack>
#include <string>
#include<algorithm>
#include<math.h>
#include "stringToIntegerVector.hpp"
using namespace std;
// 1278. Palindrome Partitioning III
// You are given a string s containing lowercase letters and an integer k. You need to :

// First, change some characters of s to other lowercase English letters.
// Then divide s into k non-empty disjoint substrings such that each substring is palindrome.
// Return the minimal number of characters that you need to change to divide the string.

// Example 1:
// Input: s = "abc", k = 2
// Output: 1
// Explanation: You can split the string into "ab" and "c", and change 1 character in "ab" to make it palindrome.
// Example 2:
// Input: s = "aabbc", k = 3
// Output: 0
// Explanation: You can split the string into "aa", "bb" and "c", all of them are palindrome.
// Example 3:
// Input: s = "leetcode", k = 8
// Output: 0

// Constraints:
// 1 <= k <= s.length <= 100.
// s only contains lowercase English letters.

// 分解大问题到可行的小问题
class Solution {
public:
    int palindromePartition(string s, int k) {
        if(s.size()==k) return 0;
                
        // m 首先计算每个片段变成回文需要改变的字符的个数
        vector<vector<int>> m;
        for (int i=0; i<s.size();i++)
        {
            vector<int> tmp(s.size(), 0);
            m.push_back(tmp);
        }
        for(int i=1; i<s.size(); i++)
        {
            for(int j=0; j<s.size()-i;j++)
            m[j][j+i] = m[j+1][j+i-1] + 1 - (int)(s[j]==s[j+i]);
        }

        // dp计算 到第j个字符为止，分为g个部分的最小值
        vector<vector<int>> m2;
        m2.push_back(m[0]);
        for (int i=1; i<k;i++)
        {
            vector<int> tmp(s.size(), 0);
            m2.push_back(tmp);
        }
        for(int g=1; g<k; g++)
        {
            for(int j=g; j<s.size();j++)
            {
                int tmp_min = m2[g-1][0] + m[1][j];
                for(int i=1; i<j;i++)
                {
                    if(m2[g-1][i]+m[i+1][j] < tmp_min)
                    tmp_min = m2[g-1][i]+m[i+1][j];
                }
                m2[g][j] = tmp_min;
            }
        }  
        return m2[k-1][s.size()-1];        
    }
};

int main(){
    
    Solution sol;
    cout << sol.palindromePartition("leetcode", 3) << endl; // ans: 2

    
    return 0;
}
