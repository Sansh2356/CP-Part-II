#include <string>
#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

//TC= O(N^2logn)
//SC=2*O(length(string))
int compare(pair<char, int> &p1, pair<char, int> &p2)
{
    return (p1.second > p2.second);
}
int main()
{
    class Solution
    {
    public:
        string reorganizeString(string s)
        {
            unordered_map<char, int> m;
            for (int x = 0; x < s.length(); x++)
            {
                if (m.count(s[x]) == true)
                {
                    m[s[x]]++;
                }
                else
                {
                    m[s[x]] = 1;
                }
            }
            if (m.size() == 1 && m[s[0]] != 1)
            {
                return "";
            }
            else if (m.size() == 1)
            {
                string b = "";
                b.push_back(s[0]);
                return b;
            }
            vector<pair<char, int>> v;
            for (auto i : m)
            {
                v.push_back({i.first, i.second});
            }
            int f = 0;
            string ans = "";
            sort(v.begin(), v.end(), compare);
            while (v[0].second > 0)
            {
                if (ans.size() == 0)
                {
                    ans.push_back(v[0].first);
                    v[0].second--;
                    sort(v.begin(), v.end(), compare);
                    continue;
                }
                else
                {
                    if (ans[ans.length() - 1] == v[0].first && v[1].second > 0)
                    {
                        ans.push_back(v[1].first);
                        v[1].second--;
                        sort(v.begin(), v.end(), compare);
                    }
                    else if (ans[ans.length() - 1] == v[0].first && v[1].second <= 0)
                    {
                        return "";
                    }
                    else
                    {
                        ans.push_back(v[0].first);
                        v[0].second--;
                        sort(v.begin(), v.end(), compare);
                    }
                }
            }

            return ans;
        }
    };
}