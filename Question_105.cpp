#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<long long> lines;
        for (int x = 0; x < n; x++)
        {
            long long slopes;
            cin >> slopes;
            lines.push_back(slopes);
        }
        sort(lines.begin(), lines.end());
        for (int f = 0; f < m; f++)
        {
            long long a, b, c;
            cin >> a >> b >> c;
            long long left = (b + 2*sqrtl( a * c));
            long long right = (b - 2*sqrtl( a * c));
              auto upper = upper_bound(lines.begin(),lines.end(),right);
            if(*upper < (left)){
                cout<<"yes"<<endl;
                cout<<*upper<<endl;
            }
            else{
                cout<<"No"<<endl;
            }
           
        }
    }
}