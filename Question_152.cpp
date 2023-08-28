#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std; 
int main()
{
    class Solution
    {
    public:
        int rec(vector<vector<int>> &pairs, int index, int num, vector<vector<int>> &dp)
        {
            if (index >= pairs.size())
            {
                return 0;
            }
            if (dp[index][num + 1] != -1)
            {
                return dp[index][num + 1];
            }

            int take = 0;
            int no_take = 0;
            no_take = rec(pairs, index + 1, num, dp);

            if (num == -1 || pairs[num][1] < pairs[index][0])
            {
                take = 1 + rec(pairs, index + 1, index, dp);
            }
            dp[index][num + 1] = max(take, no_take);
            return dp[index][num + 1];
        }
        int findLongestChain(vector<vector<int>> &pairs)
        {
            sort(pairs.begin(), pairs.end());
            vector<vector<int>> dp(pairs.size() + 1, vector<int>(pairs.size() + 1, -1));
            return rec(pairs, 0, -1, dp);
        }
    };
}