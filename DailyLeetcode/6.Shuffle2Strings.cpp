#include <bits/stdc++.h>
using namespace std;

/**
 * @brief Ques: https://www.ambitionbox.com/interviews/swiggy-question/shuffle-two-strings-you-are-given-three-strings-a-b-and-c-your-task-is-to-check-whether-c-is-formed-by-an-interleaving-of-a-and-b-c-is-said-to-be-interleaving-a-and-b-if-the-lWB8hCCd?campaign=top_question_card_view_answer&expandQuestion=true
 * 
 */

class Shuffle2Stringd
{

private:
    bool solve(string a, string b, string c, int n1, int n2, int n3)
    {
        // if all three are equal to zero
        if (n1 == 0 && n2 == 0 && n3 == 0)
            return true;

        // if c is not equal to sum of a+b
        if (n1 + n2 != n3)
            return false;

        // initializing dp
        if (dp[n1][n2] != -1)
            return dp[n1][n2];

        //checking if both A and B has same last character as C
        if (n1 > 0 and n2 > 0 and n3 > 0 and a[n1 - 1] == c[n3 - 1] and b[n2 - 1] == c[n3 - 1])
        {
            return dp[n1][n2] = (solve(a, b, c, n1 - 1, n2, n3 - 1, dp) || solve(a, b, c, n1, n2 - 1, n3 - 1, dp));
        }

        // if last char of a and c matches
        else if (n1 > 0 and n3 > 0 and a[n1 - 1] == c[n3 - 1])
        {
            return dp[n1][n2] = solve(a, b, c, n1 - 1, n2, n3 - 1);
        }

        // if last char of b and c matches
        else if (n1 > 0 and n2 > 0 and b[n2 - 1] == c[n3 - 1])
        {
            {
                return dp[n1][n2] = solve(a, b, c, n1, n2 - 1, n3 - 1);
            }
            else
            {
                return dp[n1][n2] = false;
            }
        }
    }

public:
    bool isInterleave(string a, string b, string c)
    {
        int n1 = a.size(), n2 = b.size(), n3 = c.size();
        vector<vector<int>> dp(n1 + 1, vector(n2 + 1, -1));
        return solve(a, b, c, n1, n2, n3, dp);
    }
};

int main()
{
}