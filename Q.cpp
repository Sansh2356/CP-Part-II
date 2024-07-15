#include <iostream>
#include <cmath>
#include <ctime>
#include <cmath>
#include <algorithm>
#include <set>
#include <unordered_set>
#include <stdlib.h>
#include <string>
#include <vector>
#include <time.h>
#include <unordered_map>
#include <numeric>
using namespace std;

// vector<int> generate(int size)
// {
//     vector<int> ele;
//     for (int x = 1; x <= size; x++)
//     {
//         ele.push_back(rand());
//     }

//     return ele;
// }
// void sum(vector<int> arr)
// {
//     long long sum_num = 0;
//     for (auto i : arr)
//     {
//         sum_num += i;
//     }
// }
// void sel_sort(vector<int> arr)
// {
//     int mini = INT_MAX;
//     int idx = 0;
//     for (int x = 0; x < arr.size(); x++)
//     {

//         idx = x;
//         mini = arr[x];
//         for (int f = x + 1; f < arr.size(); f++)
//         {
//             if (arr[f] <= mini)
//             {
//                 idx = f;
//                 mini = arr[f];
//             }
//         }
//         swap(arr[idx], arr[x]);
//     }
// }
// void permute(vector<int> arr, vector<int> ele, int idx)
// {
//     if (ele.size() == arr.size())
//     {
//         return;
//     }
//     for (int i = idx; i < arr.size(); i++)
//     {
//         swap(arr[i], arr[idx]);
//         permute(arr, ele, idx + 1);
//         swap(arr[i], arr[idx]);
//     }
// }
// void hanoi()
// {
// }

void solve()
{
    // vector<pair<int, double>> time;
    // double avg = 0;
    // for (int x = 6; x <= 10; x += 2)
    // {

    //     vector<int> arr = generate(x);
    //     int cnt = 10;
    //     for (int f = 0; f < 10; f++)
    //     {
    //         clock_t start = clock();
    //         // sel_sort(arr);
    //         // sum(arr);
    //         permute(arr, {}, 0);
    //         clock_t end = clock();
    //         avg += (end - start);
    //     }
    //     time.push_back({x, (double)(avg) / double(cnt)});
    // }
    // for (auto i : time)
    // {
    //     cout << i.first << " " << i.second << endl;
    // }

    // long long x, n;
    // cin >> x >> n;
    // long long ans = 1;
    // long long cnt = 1;
    // while ((x / cnt) >= n)
    // {
    //     if (x % cnt == 0)
    //     {
    //         ans = cnt;
    //     }
    //     cnt++;
    // }
    // cout<<ans<<endl;
    // string s = "abcdefghijklmnopqrstuvwxyz";
    // int n;
    // cin >> n;
    // vector<int> v(n);
    // for (int x = 0; x < n; x++)
    // {
    //     cin >> v[x];
    // }
    // unordered_map<char, int> m1;
    // unordered_set<char> s1;
    // for (int x = 0; x < s.length(); x++)
    // {
    //     m1[s[x]]=0;
    //     s1.insert(s[x]);
    // }
    // string ans = "";
    // for (int x = 0; x < n; x++)
    // {
    //     if (v[x] == 0)
    //     {
    //         char ch = *(s1.begin());
    //         s1.erase(s1.begin());
    //         m1[ch] += 1;
    //         ans.push_back(ch);
    //     }
    //     else
    //     {
    //         for (auto &i : m1)
    //         {
    //             if (i.second == v[x])
    //             {
    //                 ans.push_back(i.first);
    //                 m1[i.first] += 1;
    //                 break;
    //             }
    //         }
    //     }
    // }
    // cout<<ans<<endl;

//     unordered_set<long long> s1, s2, s3;

//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<long long> a(n);
//     vector<long long> b(m);

//     for (int x = 0; x < n; x++)
//     {
//         cin >> a[x];
//     }
//     for (int x = 0; x < m; x++)
//     {
//         cin >> b[x];
//     }


//     for (int x = 0; x < n; x++)
//     {
//         if (a[x] <= k)
//         {
//             s1.insert(a[x]);
//         }
//     }
//     for (int x = 0; x < m; x++)
//     {
//         if (b[x] <= k)
//         {
//             s2.insert(b[x]);
//         }
//     }

//     for (auto i : s1)
//     {
//         if (s2.find(i) != s2.end())
//         {
//              s3.insert(i);
//             s2.erase(i);
           
//         }
//     }
//     for (auto i : s3)
//     {
//        s1.erase(i);
//     }

//    if((s1.size()+s2.size()+s3.size())<k){
//     cout<<"NO"<<endl;
//     return;
//    }
//    else if(s1.size() > (k/2) || s2.size() > (k/2)){
//     cout<<"NO"<<endl;
//     return;
//    }
//    else{
//     cout<<"YES"<<endl;
//    }

    int n;
    cin>>n;
    vector<long long>v(n);
    for(int x=0;x<n;x++){
        cin>>v[x];
    }
    long long q;
    cin>>q;
    for(int x=0;x<q;x++){
        long long l,r;
        cin>>l>>r;
        
    }


}
int main()
{

    int t;
    cin >> t;

    while (t--)
    {
        solve();
    }
}
