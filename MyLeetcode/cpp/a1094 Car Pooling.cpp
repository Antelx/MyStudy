#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool carPooling(vector<vector<int>> &trips, int capacity)
    {
     int up[1001] = {0};
     int down[1001] = {0};
     for(int i=0; i<trips.size();i++){
         up[trips[i][1]] += trips[i][0];
         down[trips[i][2]] += trips[i][0];
     }
     int p = 0;
     for(int i=0; i <1001; i++){
         p += up[i] - down[i];
         if(p > capacity){return false;}
     }
    return true;
    }
};

int main()
{


    getchar();
    return 0;
};