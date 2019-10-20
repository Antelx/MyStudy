#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution
{
public:
    void fun(int i, int j, vector<vector<char>> &board)
    {
        if (board[i][j] == 'O')
        {
            board[i][j] = 'o';
        }
        else
        {
            return;
        }
        if (i > 0)
        {
            fun(i - 1, j, board);
        }
        if (i < board.size() - 1)
        {
            fun(i + 1, j, board);
        }
        if (j > 0)
        {
            fun(i, j - 1, board);
        }
        if (j < board[0].size() - 1)
        {
            fun(i, j + 1, board);
        }
    }
    void solve(vector<vector<char>> &board)
    {

        if (board.size() == 0)
        {
            return;
        }
        if (board[0].size() == 0)
        {
            return;
        }
        for (int i = 0; i < board.size(); i++)
        {
            fun(i, 0, board);
            fun(i, board[0].size() - 1, board);
        }
        for (int j = 0; j < board[0].size(); j++)
        {
            fun(0, j, board);
            fun(board.size() - 1, j, board);
        }
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (board[i][j] == 'o')
                {
                    board[i][j] = 'O';
                }
                else
                {
                    if (board[i][j] == 'O')
                    {
                        board[i][j] = 'X';
                    }
                }
            }
        }
    }
};

int main()
{
    Solution sol;

    // cout << sol.threeSum() << endl;

    getchar();
    return 0;
}