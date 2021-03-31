#include <iostream>
#include <vector>
#include <unordered_map>
#include<stack>
#include <string>
#include<algorithm>
#include<math.h>
#include "stringToIntegerVector.hpp"
using namespace std;
// 1029. Two City Scheduling

// A company is planning to interview 2n people. Given the array costs where costs[i] = [aCosti, bCosti],
// the cost of flying the ith person to city a is aCosti, and the cost of flying the ith person to city b is bCosti.

// Return the minimum cost to fly every person to a city such that exactly n people arrive in each city.
// Example 1:

// Input: costs = [[10,20],[30,200],[400,50],[30,20]]
// Output: 110
// Explanation: 
// The first person goes to city A for a cost of 10.
// The second person goes to city A for a cost of 30.
// The third person goes to city B for a cost of 50.
// The fourth person goes to city B for a cost of 20.

// The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.
// Example 2:

// Input: costs = [[259,770],[448,54],[926,667],[184,139],[840,118],[577,469]]
// Output: 1859
// Example 3:

// Input: costs = [[515,563],[451,713],[537,709],[343,819],[855,779],[457,60],[650,359],[631,42]]
// Output: 3086
 

// Constraints:

// 2 * n == costs.length
// 2 <= costs.length <= 100
// costs.length is even.
// 1 <= aCosti, bCosti <= 1000

// 太蠢了这方法
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<vector<int>> tmp;
        for(int i=0; i< costs.size(); i++)
        {
            vector<int> t;
            t.push_back(costs[i][1]-costs[i][0]);
            t.push_back(i);
            tmp.push_back(t);
        }
        sort(tmp.begin(), tmp.end());
        int ret = 0;
        for(int i=0; i < costs.size()/2;i++)
        ret += costs[tmp[i][1]][1];
        for(int i=costs.size()/2; i < costs.size();i++)
        ret += costs[tmp[i][1]][0];
        return ret;        
    }
};

// class Solution:
//     def twoCitySchedCost(self, costs: List[List[int]]) -> int:
//         t = [j[1] for j in sorted(zip([(i[1]-i[0]) for i in costs], range(len(costs))))]
//         return sum(costs[i][1] for i in t[:len(t)//2]) + sum(costs[i][0] for i in t[len(t)//2:])
        
int main(){
    
    Solution sol;
    vector<vector<int>> costs;
    costs.push_back(stringToIntegerVector("[10,20]"));
    costs.push_back(stringToIntegerVector("[30,200]"));
    costs.push_back(stringToIntegerVector("[400,50]"));
    costs.push_back(stringToIntegerVector("[30,20]"));
    cout << sol.twoCitySchedCost(costs) << endl;
    
    return 0;
}
