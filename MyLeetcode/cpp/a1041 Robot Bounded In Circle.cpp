#include <iostream>
#include <vector>
using namespace std;

class Solution
{
public:
    bool isRobotBounded(string instructions)
    {
        int dx = 0, dy = 1, px = 0, py = 0;
        for (int i = 0; i < instructions.length(); i++)
        {
            if (instructions[i] == 'G')
            {
                px += dx;
                py += dy;
            }
            if (instructions[i] == 'L')
            {
                int t = -dy;
                dy = dx;
                dx = t;
            }
            if (instructions[i] == 'R')
            {
                int t = -dx;
                dx = dy;
                dy = t;
            }
        }
        if ((px != 0 || py != 0) && dx == 0 && dy == 1)
        {
            return false;
        }
        else
        {
            return true;
        }
    }
};

int main()
{
    getchar();
    return 0;
}