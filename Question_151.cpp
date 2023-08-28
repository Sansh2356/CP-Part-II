#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        long long s = 2;
        long long e = 10e9;
        long long ans = 0;
        while (s <= e)
        {
            long long mid = (s + e) / 2;
            if ((mid * (mid - 1)) / 2 > n)
            {
                e = mid - 1;
            }
            else
            {
                ans = max(ans, mid);
                s = mid + 1;
            }
        }
        cout << (ans + (n - (ans * (ans - 1)) / 2)) << endl;
    }
}