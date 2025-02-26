#include <bits/stdc++.h>
using namespace std;

/*
Ques: https://www.geeksforgeeks.org/problems/shortest-path-in-a-binary-maze-1655453161/1
*/

/**
 * Since it is given shortest, we will try to use BFS over here
 *
 */

class ShortestPathInMaze
{
public:
    int shortestPath(vector<vector<int>> &grid, pair<int, int> source,
                     pair<int, int> destination)
    {
        int n = grid.size();
        int m = grid[0].size();
        int x1 = source.first;
        int y1 = source.second;
        int x2 = destination.first;
        int y2 = destination.second;
        int dx[] = {0, -1, 0, +1};
        int dy[] = {-1, 0, +1, 0};
        vector<vector<int>> dist(n + 1, vector<int>(m + 1, 1e9));
        dist[x1][y1] = 0;
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {x1, y1}});
        while (!q.empty())
        {
            auto distance = q.front().first;
            auto row = q.front().second.first;
            auto col = q.front().second.second;
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int nRow = row + dx[i];
                int nCol = col + dy[i];
                if (nRow >= 0 and nRow < n and nCol >= 0 and nCol < m and
                    grid[nRow][nCol] == 1 and 1 + distance < dist[nRow][nCol])
                {
                    dist[nRow][nCol] = 1 + distance;
                    if (nRow == x2 && nCol == y2)
                        return 1 + distance;
                    q.push({1 + distance, {nRow, nCol}});
                }
            }
            // it means first and last overlaps i.e same distance like original or coincide with each othr
            if ((x1 == x2) and (y1 == y2))
                return 0;
        }
        return -1;
    }
};

int main()
{
}