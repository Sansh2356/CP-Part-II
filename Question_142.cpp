#include <iostream>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
    public:
        long long rec(vector<int> &nums, int x, int index, int j, vector<vector<long long>> &dp)
        {
            if (index >= nums.size())
            {
                return 0;
            }
            if (dp[index][j] != -1)
            {
                return dp[index][j];
            }
            long long no_take = 0;
            no_take = rec(nums, x, index + 1, j, dp);
            long long ele = nums[index];
            long long take = 0;
            take = nums[index] + rec(nums, x, index + 1, ele % 2, dp);
            if (j != ele % 2)
            {
                take -= x;
            }
            dp[index][j] = max(take, no_take);
            return dp[index][j];
        }
        long long maxScore(vector<int> &nums, int x)
        {
            vector<vector<long long>> dp(nums.size() + 1, vector<long long>(2, -1));
            return (rec(nums, x, 0, nums[0] % 2, dp));
        }
    };
}
