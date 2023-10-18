#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;
int main()
{
    set<pair<int, int>> s1;
    int *arr = new int(5);
    // we are entering a corresponding index along with its value//
    s1.insert({0, 1});
    s1.insert({1, 2});
    s1.upper_bound({0, 1});
    class Solution
    {
    public:
        vector<int> findIndices(vector<int> &nums, int id, int vd)
        {
            int n = nums.size();
            set<pair<int, int>> st;
            for (int i = id; i < n; i++)
            {
                st.insert({nums[i - id], i - id});
                auto it = st.lower_bound({nums[i] + vd, -1});
                if (it != st.end())
                {
                    return {i, it->second};
                }
                auto it1 = st.upper_bound({nums[i] - vd, INT_MAX});
                if (it1 != st.begin())
                {
                    it1 = prev(it1);
                    // cout << it1->first << '\n';
                    return {i, it1->second};
                }
            }
            return {-1, -1};
        }
    };
}