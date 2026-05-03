#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canPlaceFlowers(vector<int> &flowerbed, int n)
    {
        int cnt = 0;
        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                /*
                i == 0: If i == 0, we're checking the first plot in the flowerbed. 
                Since there is no plot before the first one (i - 1 is out of bounds), 
                we can assume the left side is "empty" (i.e., there is no flower to the left).
                */
                bool left_empty = (i == 0 || flowerbed[i - 1] == 0); 
                bool right_empty = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);
                if (left_empty and right_empty)
                {
                    flowerbed[i] = 1;
                    cnt++;
                    i++;
                    if (cnt >= n)
                    {
                        return true; 
                    }
                }
            }
        }
        if(n<=cnt) return true;
        return false;
    }
};

int main()
{
}