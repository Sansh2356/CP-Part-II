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
        vector<int> v(n);
        int pos_sum = 0;
        int pos_count = 0;
        int neg_count = 0;
        int neg_sum = 0;
        for (int x = 0; x < n; x++)
        {
            cin >> v[x];
            if (v[x] < 0)
            {
                neg_sum += v[x];
                neg_count++;
            }
            else
            {
                pos_sum += v[x];
                pos_count++;
            }
        }
        if (pos_count > neg_count)
        {
            if (neg_count % 2 == 0)
            {
                cout << 0 << endl;
                continue;
            }
            else
            {
                cout << 1 << endl;
                continue;
            }
        }
        if (pos_count == neg_count)
        {
            if (neg_count % 2 == 0)
            {
                cout << 0 << endl;
                continue;
            }
            else if (neg_count % 2 != 0)
            {
                cout << 1 << endl;
                continue;
            }
        }
        bool flag = true;
        int count = 0;
        for (int x = 0; x < n; x++)
        {
            if (v[x] < 0)
            {
                neg_sum++;
                pos_sum++;
                neg_count--;
                pos_count++;
                count++;
                if (neg_sum + pos_sum == 0)
                {
                    if (neg_count % 2 == 0)
                    {
                        flag = false;
                        cout << count << endl;
                        break;
                    }
                    else if (neg_count % 2 != 0)
                    {
                        cout << count + 1 << endl;
                        flag = false;
                        break;
                    }
                }
                else if (neg_sum + pos_sum > 0)
                {
                    if (neg_count % 2 == 0)
                    {
                        flag = false;
                        cout << count << endl;
                        break;
                    }
                    else if (neg_count % 2 != 0)
                    {
                        cout << count + 1 << endl;
                        flag = false;
                        break;
                    }
                }
            }
        }
    }
}