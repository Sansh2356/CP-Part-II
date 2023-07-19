#include <iostream>
#include <numeric>
#include <algorithm>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k, x;
        cin >> n >> k >> x;
        if (k == 1 && x == 1)
        {
            cout << "NO" << endl;
            continue;
        }
        else if (x >= 2)
        {
            cout << "YES" << endl;
            cout << n << endl;
            for(int x=0;x<n;x++){
                cout<<1<<" ";
            }
            cout<<endl;
            continue;
        }
         if (x == 1)
        {
            if (n % 2 == 0)
            {
                cout << "YES" << endl;
                cout << n / 2 << endl;
                for(int x=0;x<n/2;x++){
                cout<<2<<" ";
            }
            cout<<endl;
                continue;
            }
            if (n % 2 != 0)
            {
                if (k == 2)
                {
                    cout << "NO" << endl;
                    continue;
                }
                if(n == 3){
                    cout<<"YES"<<endl;
                    cout<<1<<endl;
                    cout<<3<<endl;
                    continue;
                }
                cout << "YES" << endl;
                cout << ((n - 3) / 2) + 1 << endl;
                for(int x=0;x<(n-3)/2;x++){
                cout<<2<<" ";
            }
            cout<<3<<endl;
            }
        }
    }
}
