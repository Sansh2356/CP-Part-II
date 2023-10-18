#include <iostream>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
    public:
        int rec(vector<int> &cost, vector<int> &time, int index, int walls, vector<vector<int>> &dp)
        {
            if (walls >= time.size())
                return 0;
            if (index >= cost.size())
                return 1e9;
            if (dp[index][walls] != -1)
                return dp[index][walls];
            int take = 0;
            int no_take = 0;
            no_take = rec(cost, time, index + 1, walls, dp);
            take = cost[index] + rec(cost, time, index + 1, walls + time[index] + 1, dp);
            return dp[index][walls] = min(no_take, take);
        }
        int paintWalls(vector<int> &cost, vector<int> &time)
        {
            vector<vector<int>> dp(cost.size() + 1, vector<int>(cost.size() + 1, -1));
            return rec(cost, time, 0, 0, dp);
        }
    };
}