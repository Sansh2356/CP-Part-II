#include <iostream>
#include <algorithm>
#include <vector>
#include <numeric>
using namespace std;
bool is_sorted(vector<long long> v)
{
    vector<long long> s = v;
    sort(v.begin(), v.end());
    if (v == s)
    {
        return true;
    }
    return false;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<long long> v(n);
        int neg_count = 0;
        for (int m = 0; m < n; m++)
        {
            cin >> v[m];
            if (v[m] < 0)
            {
                neg_count++;
            }
        }
        int pos_count = (n - neg_count);
        if (pos_count == n || neg_count == n)
        {
            if (is_sorted(v) == true)
            {
                cout << "yes" << endl;
                continue;
            }
            else
            {
                cout << "no" << endl;
                continue;
            }
        }
        else if (is_sorted(v) == true)
        {
            cout << "yes" << endl;
            continue;
        }
        else
        {
            int index = neg_count;
                for (int f = 0; f < n; f++)
                {   
                    if(f >=index){
                        if(v[f] < 0){
                            v[f] = v[f]*-1;
                        }
                    }
                    else if(f < index){
                        if(v[f]>=0){
                            v[f] = v[f]*-1;
                        }
                    }
                }
                
            }
            if (is_sorted(v) == true)
            {
                cout << "yes" << endl;
                continue;
            }
            else
            {
                cout << "no" << endl;
            }
        }
    }

