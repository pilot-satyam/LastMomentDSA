#include <unordered_map>
#include <vector>

class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int, int> ballToColor;
        unordered_map<int, int> colorCount;
        vector<int> result;

        //[[1,4],[2,5],[1,3],[3,4]]

        for (auto it : queries) {
            int ball = it[0]; //1,2,1,3 
            int color = it[1]; //4,5,3,4 

            // If the ball already has a color, update the color count
            if (ballToColor.find(ball) != ballToColor.end()) {
                int prevColor = ballToColor[ball];
                if (--colorCount[prevColor] == 0) {
                    colorCount.erase(prevColor);
                }
            }

            // Assign the new color to the ball
            ballToColor[ball] = color;
            colorCount[color]++;

            // The number of distinct colors is the size of colorCount
            result.push_back(colorCount.size());
        }

        return result;
    }
};
