#include <iostream>
#include <unordered_map>
#include<algorithm>
#include <map>
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
        vector<int> v(n);
        map<int, int> m;
        int maxi=INT_MIN;
        for (int x = 0; x < n; x++)
        {
            cin >> v[x];
            maxi = max(maxi,v[x]);
            if (m.count(v[x]) == true)
            {
                m[v[x]]++;
            }
            else
            {
                m[v[x]] = 1;
            }
        }
        if(m.size() != maxi+1){
            cout<<"no"<<endl;
            continue;
        }
        vector<int> demo;
        for (auto i : m)
        {
           // cout<<i.second<<endl;
            demo.push_back(i.second);
        }
        reverse(demo.begin(), demo.end());
        bool flag = true;
        for (int f = 0; f < demo.size() - 1; f++)
        {
            if (demo[f] > demo[f + 1])
            {
                cout << "no" << endl;
                flag = false;
                break;
            }
        }
        if (flag == true)
        {
            cout << "yes" << endl;
        }
    }
}