#include <iostream>
using namespace std;
#include <vector>
#include <unordered_map>
// Sum of distances leetcode weekly contest brute force approach will give TLE//
class Solution
{
public:
    vector<long long> distance(vector<int> &nums)
    {
        unordered_map<long long, vector<long long>> m;
        vector<long long> ans;
        for (int s = 0; s < nums.size(); s++)
        {
            int index = s;
            m[nums[s]].push_back(s);
        }
        bool flag = false;
        for (int k = 0; k < nums.size(); k++)
        {
            long long number = nums[k];
            long long sum = 0;
            flag = false;
            for (int t = 0; t < (m[number].size()); t++)
            {
                if (m[number].size() == 1)
                {
                    ans.push_back(0);
                    flag = true;
                    break;
                }
                else
                {
                    if (m[number][t] == k)
                    {
                        continue;
                    }
                    else
                    {
                        sum += (abs(k - m[number][t]));
                    }
                }
            }
            if (flag == true)
            {
                continue;
            }
            else
            {
                ans.push_back(sum);
            }
        }
        return (ans);
    }
};