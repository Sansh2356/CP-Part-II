#include <iostream>
#include<algorithm>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
    public:
        int bestClosingTime(string customers)
        {
            int cnt_n = 0;
            vector<int> v;
            vector<int> v2;
            for (int x = 0; x < customers.length(); x++)
            {
                char ch = customers[x];
                if (ch == 'Y')
                    v.push_back(1);
                else if (ch == 'N')
                    v.push_back(0);
            }
            reverse(v.begin(), v.end());
            v2.push_back(v[0]);

            for (int x = 1; x < v.size(); x++)
            {
                v2.push_back(v[x] + v2.back());
            }
            reverse(v2.begin(), v2.end());
            pair<int, int> p = {0, v2[0]};
            if (customers[0] == 'N')
            {
                cnt_n++;
            }
            int cnt2 = 1;
            for (int x = 1; x < customers.length(); x++)
            {
                if (v2[cnt2] + cnt_n < p.second)
                {
                    p.first = x;
                    p.second = v2[cnt2] + cnt_n;
                }
                if (customers[x] == 'N')
                {
                    cnt_n++;
                }
                cnt2++;
            }
            if (customers.back() == 'N')
            {
                cnt_n--;
                if (cnt_n < p.second)
                {
                    p.first = customers.length();
                }
            }
            else
            {
                if (cnt_n < p.second)
                {
                    p.first = customers.length();
                }
            }
            return p.first;
        }
    };
}