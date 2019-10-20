#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
class Solution
{
public:
    int hammingWeight(uint32_t n)
    {
        int res = 0;
        while (n)
        {
            if (n & 1)
            {
                res++;
            }
            n = n >> 1;
        }
        return res;
    }
};

int main()
{
    Solution sol;
    cout << sol.hammingWeight(5) << endl;

    getchar();
    return 0;
}