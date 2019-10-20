#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;
class Solution
{
public:
    int minSteps(int n)
    {
        unordered_map<int, int> nmap;
        int p = 2;
        while (n > 1)
        {
            if (n % p == 0)
            {
                n /= p;
                if (nmap.find(p) != nmap.end())
                {
                    nmap[p]++;
                }
                else
                {
                    nmap[p] = 1;
                }
            }
            else
            {
                p++;
            }
        }
        int res = 0;
        for (unordered_map<int, int>::iterator i = nmap.begin(); i != nmap.end(); i++)
        {
            cout<<i->first * i->second<<endl;
            res += i->first * i->second;
        }
        return res;
    }
};
int main()
{
    int n = 1000;
    Solution sol;

    cout << sol.minSteps(n) << endl;

    getchar();
    return 0;
}