#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
    {
        if (matrix.size() == 0)
        {
            vector<int> res(0);
            return res;
        }
        if (matrix[0].size() == 0)
        {
            vector<int> res(0);
            return res;
        }
        vector<int> res;
        bool con = true;
        int i = 0;
        int j = 0;
        while(i != matrix.size()-1 || j != matrix[0].size()-1){
            res.push_back(matrix[i][j]);
            if(con){
                if(i>0 && j < matrix[0].size()-1){
                    i--;
                    j++;
                }
                else
                {
                    con = false;
                    if(j<matrix[0].size()-1){
                        j++;
                    }
                    else
                    {
                        i++;
                    }
                    
                }
                
            }
            else{
                if(i<matrix.size()-1 && j>0){
                    i++;
                    j--;
                }
                else{
                    con = true;
                    if(i<matrix.size()-1){
                        i++;
                    }
                    else{
                        j++;
                    }
                }
            }
        }
        res.push_back(matrix[matrix.size()-1][matrix[0].size()-1]);
        return res;
    }
};

int main()
{
    static int m = 4;
    static int n = 3;
    int a[m][n] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}, {10, 11, 12}};
    vector<vector<int>> matrix(m, vector<int>(n));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            matrix[i][j] = a[i][j];
        }
    }

    Solution sol;
    for(int i = 0; i < m*n; i++){
        cout<<sol.findDiagonalOrder(matrix)[i]<<endl;
    }

    getchar();
    return 0;
}