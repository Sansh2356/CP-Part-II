#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //Trapping rain water using the idea that rmax and lmax will be taken rightmost storage unit and leftmost storage unit
    //each time max will be updated and if the given tower is small then we will take the difference and add to the given storage.
    class Solution
    {
    public:
        int trap(vector<int> &height)
        {
            int lmax = height[0];
            int rmax = height[height.size() - 1];
            int l = 1;
            int r = height.size() - 2;
            int ans = 0;
            while (l <= r)
            {
                if (height[l] >= lmax)
                {
                    lmax = height[l];
                    l++;
                }
                else if (height[r] >= rmax)
                {
                    rmax = height[r];
                    r--;
                }
                else if (lmax <= rmax && height[l] < lmax)
                {
                    ans += lmax - height[l];
                    l++;
                }
                else
                {
                    ans += rmax - height[r];
                    r--;
                }
            }
            return ans;
        }
    };
}