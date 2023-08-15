#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
int main()
{
    //Formation of all permutations including distinct number//
    class Solution
    {
    public:
        void rec(vector<int> &nums, unordered_map<int, int> &m, vector<vector<int>> &ans, vector<int> &ele)
        {
            if (ele.size() == nums.size())
            {
                ans.push_back(ele);
                return;
            }
            for (auto &i : m)
            {
                if (i.second == 0)
                {
                    continue;
                }

                ele.push_back(i.first);
                m[i.second] -= 1;
                rec(nums, m, ans, ele);
                ele.pop_back();
                m[i.second] += 1;
            }
        }
        vector<vector<int>> permuteUnique(vector<int> &nums)
        {
            unordered_map<int, int> m;
            for (int x = 0; x < nums.size(); x++)
            {
                m[nums[x]]++;
            }
            vector<vector<int>> ans;
            vector<int> ele;
            rec(nums, m, ans, ele);
            return ans;
        }
    };
}