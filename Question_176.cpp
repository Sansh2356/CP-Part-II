#include <iostream>
#include <vector>
using namespace std;

int main()
{
   int t;
   cin >> t;
   while (t--)
   {
      int n;
      cin >> n;
      vector<long long> v(n);
      vector<long long> pf(n), sf(n);
      for (int x = 0; x < n; x++)
      {
         cin >> v[x];
      }
      pf[0] = v[0];
      for (int x = 1; x < n; x++)
      {
         pf[x] = max(pf[x - 1], v[x]);
      }
      long long ans = 0;
      sf[n - 1] = v[v.size() - 1];
      for (int x = n - 2; x >= 0; x--)
      {
         sf[x] = max(sf[x + 1], v[x]);
      }
      for (int x = 0; x < n; x++)
      {
         v[x] = max(v[x], min(sf[x], pf[x]));
      }
      for (int x = 0; x < n; x++)
      {
         ans += v[x];
      }
      cout << ans << endl;
   }
   return 0;
}
