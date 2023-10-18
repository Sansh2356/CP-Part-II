#include <iostream>
#include <vector>
int primechk[210000];
// TC of O(log(x*y)) as the value keeps on shrinking by half.
int gcd(int x, int y)
{
    return x % y == 0 ? y : gcd(x, x % y);
}
// Seive of erasthothenes used for calculating primes optimally in TC of O(log(log(m*n)))
void preprocess(void)
{
    int i, j;
    for (i = 2; i <= 20000; i++)
    {
        primechk[i] = 1;
    }
    for (i = 2; i <= 20000; i++)
    {
        if (primechk[i] == 1)
        {
            for (j = 2; i * j <= 20000; j++)
            {
                primechk[i * j] = 0;
            }
        }
    }
}
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin>>n>>m;
        string x, s;
        cin >> x >> s;
        bool flag = true;
        int cnt = 0;
        string e = "";
        string s3 = x;
       // int cnt = 0;
       
       while(x.length() <= 500){
            cnt+=1;
        for (int k = 0; k < x.length(); k++)
            {
                e = "";
                e.push_back(x[k]);
               // cout<<x.length()<<endl;
                for (int d = k + 1; d < x.length(); d++)
                {
                  
                    if (e == s)
                    {
                        flag = false;
                        break;
                    }
                    e.push_back(x[d]);
                     // cout<<e<<" "<<e.length()<<endl;
                    if (e == s)
                    {
                        flag = false;
                        break;
                    }
                }
                if (flag == false)
                {
                    break;
                }
            }
            if (flag == false)
            {
                //cout<<x<<endl;
                cout << cnt-1 << endl;
                break;
            }
            
            x = x + s3;
            s3 = x;
            //cout<<x<<endl;
       }
        if(flag == true){
            cout<<-1<<endl;
        }
    }
}