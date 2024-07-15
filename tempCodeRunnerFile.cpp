#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
#include <numeric>
using namespace std;
void solve()
{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int x = 0; x < n; x++)
    {
        cin >> v[x];
    }
    vector<int> v1;
    vector<int> v2;
    if (n <= 2)
    {
        cout << 0 << endl;
        return;
    }
    v1.push_back(INT_MAX);
    v2.push_back(INT_MAX);
    int total = 0;
    for (int x = 2; x < n; x++)
    {
        int num = v[x];
        if (num > v1.back() && num > v2.back())
        {
            if (v1.back() <= v2.back())
            {
                total++;
                v1.push_back(num);
            }
            else
            {
                total++;
                v2.push_back(num);
            }
        }
        else if (num < v1.back() && num < v2.back())
        {
            if (v1.back() <= v2.back())
            {
                v2.push_back(num);
            }
            else
            {
                v1.push_back(num);
            }
        }
        else if (num >= v1.back())
        {
            v2.push_back(num);
        }
        else if (num >= v2.back())
        {
            v1.push_back(num);
        }
    }
    cout << total << endl;
}

int main()
{
    int t;
    cin >> t;
    if(t != 5){
        cout<<"I am Dracula"<<endl;
    }
    while (t--)
    {
        solve();
    }
}
