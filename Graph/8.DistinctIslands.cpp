#include <bits/stdc++.h>
using namespace std;

/*
Ques: https://www.geeksforgeeks.org/problems/number-of-distinct-islands/0
*/

class Solution
{

private:
    void dfs(int row, int col, vector<vector<int>> &vis, vector<pair<int, int>> &v, vector<vector<int>> &grid, int row0, int col0)
    {
        vis[row][col] = 1;
        int n = grid.size();
        int m = grid[0].size();
        v.push_back({row - row0, col - col0});
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, -1, 0, +1};
        for (int i = 0; i < 4; i++)
        {
            int nRow = row + dx[i];
            int nCol = col + dy[i];
            if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and !vis[nRow][nCol] and grid[nRow][nCol] == 1)
            {
                dfs(nRow, nCol, vis, v, grid, row0, col0);
            }
        }
    }

public:
    int countDistinctIslands(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();
        set<vector<pair<int, int>>> st;
        // vector<pair<int, int>> v; ===> declaring v here will not work and gives wrong ans
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++)
        {   
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] and grid[i][j] == 1)
                {
                    /*
                    Instead of declaring v once outside the loops, it should be declared inside the 
                    loop where you detect a new island. This ensures that v is reset for each island,
                     preventing data from one island from leaking into the computation for another.
                     */
                    vector<pair<int, int>> v;
                    dfs(i, j, vis, v, grid, i, j);
                    st.insert(v);
                }
            }
        }
        return st.size();
    }
};

int main()
{
}