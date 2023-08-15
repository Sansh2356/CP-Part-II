#include <vector>
using namespace std;
class Solution
{
public:
    bool rec(vector<int> &nums, int index, vector<int> &dp)
    {

        if (index >= nums.size() - 1)
        {
            return true;
        }
        if (nums[index] == 0)
        {
            return false;
        }
        if (dp[index] != -1)
        {
            return false;
        }
        bool ans2;
        for (int x = 1; x <= nums[index]; x++)
        {
            ans2 = rec(nums, index + x, dp);
            if (ans2 == true)
            {
                return ans2;
            }
        }
        dp[index] = ans2;
        return dp[index];
    }
    bool canJump(vector<int> &nums)
    {
        vector<int> dp(nums.size() + 1, -1);
        return rec(nums, 0, dp);
    }
};