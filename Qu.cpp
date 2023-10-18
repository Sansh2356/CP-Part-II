// *YUVA*
    #include<bits/stdc++.h>
    using namespace std;
 
    #define double long double
    #define pb push_back
    #define int long long
    typedef vector<int> vi;
    #define all(a) a.begin(),a.end()
    typedef pair<int,int> pi;
    const int N = 998244353;
    #define f first
    #define s second
    #define endl "\n"
//


void get()
{
    int n; cin>>n;
    int a[n];
    for(int i=0;i<n;i++)cin>>a[i];

    double ans;
    sort(a,a+n);
    if(n<=3)
    {
        cout<<0;
        return;
    }

    ans = a[n-1] + a[n-2] - (a[1] + a[0]);
    ans/=2;

    if(n==5)
    {
        double left = a[0] + a[1];
        left/=2;
        double right = a[2] + a[4];
        right/=2;

        ans = (right - left);

        left = a[0] + a[2];
        left/=2;
        right = a[3] + a[4];
        right/=2;

        ans = max(right - left, ans);
    }

    cout<<setprecision(10)<<fixed;
    cout<<ans;
}
    
int32_t main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int Q=1;
    cin>>Q;

    for(int i=0;i<Q;i++)
    {
        cout<<"Case #"<<i+1<<": ";
        get();        
        if(i!=Q-1)cout<<endl;
    }
}