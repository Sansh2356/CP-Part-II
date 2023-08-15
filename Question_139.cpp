#include <vector>
#include <algorithm>
using namespace std;
int main()
{
    class Solution
    {
    public:
        bool check(int mid, vector<int> ul)
        {

            int cnt = ul.size() - 1;
            int cnt2 = 0;

            while (cnt2 != mid)
            {
                sort(ul.begin(), ul.end());
                for (int f = (ul.size() - 1); f >= cnt - cnt2; f--)
                {
                    int freq = ul[f];
                    if (freq <= 0)
                    {
                        return false;
                    }
                    else
                    {
                        ul[f]--;
                    }
                }
                cnt2++;
            }
            return true;
        }
        int maxIncreasingGroups(vector<int> &ul)
        {
            int n = ul.size();

            int s = 1;
            int e = n;
            int ans = INT_MIN;
            while (s <= e)
            {
                int mid = (s + e) / 2;
                if (check(mid, ul) == true)
                {
                    ans = max(ans, mid);
                    s = mid + 1;
                }
                else
                {
                    e = mid - 1;
                }
            }
            return ans;
        }
    };
}