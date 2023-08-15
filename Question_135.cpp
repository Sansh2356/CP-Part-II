#include <iostream>
#include <algorithm>
using namespace std;

#define nl "\n"
#define ll long long int
#define INF 1e9

void solve()
{
    int n;
    cin >> n;
    int a[4];
    for (int &x : a)
        cin >> x;
    ll l = 0, r = n;
    ll ans = 0;
    sort(a, a + n);
    while (l <= r)
    {
        ll mid = (l + r) >> 1;
        int cnt = 0;
        int val = mid;
        for (int bob = 0, alice = n - 1; bob <= alice;)
        {
            if (a[alice] > val)
                alice--;
            else
            {
                cnt++;
                bob++;
                alice--;
                val = mid - (cnt + 1) + 1;
            }
        }

        if (cnt >= mid)
        {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T = 1;
    cin >> T;
    for (int t = 1; t <= T; t++)
    {
        // cout << "Case #" << t << ": ";
        solve();
    }
}