#include <iostream>
#include <vector>
using namespace std;
int mod = 1e9 + 7;
int main()
{
    class Solution
    {
    public:
        int rec(int steps, int arrLen, int index, vector<vector<int>> &dp)
        {
            if (index >= arrLen || index < 0)
                return 0;
            if (steps == 0)
            {
                if (steps == 0 && index == 0)
                    return 1;
                return 0;
            }
            if (dp[index][steps] != -1)
            {
                cout << dp[index][steps] << endl;
                return dp[index][steps];
            }
            // 3 choices //
            // Moving//
            long long ans = 0;
            ans = ans + rec(steps - 1, arrLen, index + 1, dp) % mod;
            ans = ans + rec(steps - 1, arrLen, index - 1, dp) % mod;
            ans = ans + rec(steps - 1, arrLen, index, dp) % mod;
            return dp[index][steps] = ans;
        }
        int numWays(int steps, int arrLen)
        {
            vector<vector<int>> dp(arrLen, vector<int>(steps + 1, -1));
            return rec(steps, arrLen, 0, dp);
        }
    };
}