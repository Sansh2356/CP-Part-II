#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
    public:
        int eraseOverlapIntervals(vector<vector<int>> &intervals)
        {
            sort(intervals.begin(), intervals.end());
            int int_size = 0;
            int count = 0;
            for (int x = 0; x < intervals.size(); x++)
            {
                int s = intervals[x][0];
                int e = intervals[x][1];
                if (x == 0)
                {
                    int_size = e;
                    continue;
                }

                else if (s < int_size)
                {
                    count++;
                    int_size = min(int_size, e);
                    continue;
                }
                else
                {
                    int_size = e;
                    continue;
                }
            }
            return count;
        }
    };
}