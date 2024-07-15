#include <iostream>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
    public:
        int minimumSum(vector<int> &nums)
        {
            vector<int> pf(nums.size());
            vector<int> sf(nums.size());
            sf[nums.size() - 1] = nums[nums.size() - 1];
            pf[0] = nums[0];
            for (int x = 1; x < nums.size(); x++)
            {
                pf[x] = min(pf[x - 1], nums[x]);
            }
            for (int x = nums.size() - 2; x >= 0; x--)
            {
                sf[x] = min(sf[x + 1], nums[x]);
            }
            int ans = INT_MAX;
            for (int x = 1; x < nums.size() - 1; x++)
            {
                if (pf[x - 1] < nums[x] && sf[x + 1] < nums[x])
                {
                    ans = min(ans, (nums[x] + pf[x - 1] + sf[x + 1]));
                }
            }
            if (ans == INT_MAX)
                return -1;
            return ans;
        }
    };
}