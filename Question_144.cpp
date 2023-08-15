#include <iostream>
using namespace std;
#include <vector>
int main()
{

    class Solution
    {
    public:
        int rec(int amount, vector<int> &coins, int index, vector<vector<int>> &dp)
        {
            if (index >= coins.size())
            {
                if (amount == 0)
                {
                    return 0;
                }
                else
                {
                    return -1;
                }
            }
            if (dp[index][amount] != -1)
            {
                return dp[index][amount];
            }
            long long taken = 0;
            long long no_take = 0;
            no_take = rec(amount, coins, index + 1, dp);

            if (coins[index] <= amount)
            {
                taken = 1 + rec(amount - coins[index], coins, index, dp);
            }
            dp[index][amount] = taken + no_take;
            return dp[index][amount];
        }
        int change(int amount, vector<int> &coins)
        {
            vector<vector<int>> dp(coins.size() + 1, vector<int>(amount + 1, -1));
            return rec(amount, coins, 0, dp) + 1;
        }
    };
}