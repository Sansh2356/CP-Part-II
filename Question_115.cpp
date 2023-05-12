#include <iostream>
#include <climits>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        long long ans;
        long long int t1 = INT_MAX;
        long long int t2 = INT_MAX;
        long long int ans2 = INT_MAX;

        while (n--)
        {
            long long int time;
            cin >> time;
            string skill;
            cin >> skill;
            if (skill[0] == '0' && skill[1] == '0')
            {
                continue;
            }
            else if (skill[0] == '1' && skill[1] == '0')
            {
                t1 = min(t1, time);
            }
            else if (skill[0] == '0' && skill[1] == '1')
            {
                t2 = min(t2, time);
            }
            else if (skill[0] == '1' && skill[1] == '1')
            {
                ans2 = min(ans2, time);
                continue;
            }
        }
        ans = (t1 + t2);
        if ((t1 == INT_MAX && t2 != INT_MAX || t2 == INT_MAX && t1 == INT_MAX) && ans2 != INT_MAX )
        {
            cout << -1 << endl;
            continue;
        }
        if (ans < ans2)
        {
            cout << ans << endl;
        }
        else if (ans > ans2)
        {
            cout << ans2 << endl;
        }
    }
}