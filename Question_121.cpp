#include <iostream>
#include <algorithm>
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
        int l=-1;
        int r =-1;
        long long sum = 0;
        bool flag = true;
        for(int x=0;x<n;x++){
            cin>>v[x];
            sum+=abs(v[x]);
            if(v[x] == 0){
                continue;
            }
            if(v[x] < 0 && flag == true){
                l = x;
                flag = false;
            }
            else if(v[x] < 0 && flag != true){
                r = x;
            }
        }
        int neg_count=0;
        int pos_count = 0;
        int zero_count = 0;
        if(l == r && l == -1){
            cout<<sum<<" "<<0<<endl;
            continue;
        }
        if(l != -1 && r == -1){
            cout<<sum<<" "<<1<<endl;
            continue;
        }
        for(int x=l;x<=r;x++){
            if(v[x] < 0){
                neg_count++;
            }
            else if(v[x] > 0){
                pos_count++;
            }
            else{
                zero_count++;
            }
        }
        if(neg_count > pos_count && pos_count != 0){
            cout<<sum<<" "<<pos_count+1<<endl;
        }
        else if(neg_count > pos_count && pos_count == 0){
            cout<<sum<<" "<<1<<endl;
        }
        else if(neg_count == pos_count && pos_count != 0){
            cout<<sum<<" "<<pos_count<<endl;
        }
        else if(pos_count > neg_count){
            cout<<sum<<" "<<neg_count<<endl;
        }
        else{
            if(zero_count == (r-l+2)){
                cout<<sum<<" "<<0<<endl;
            }
        }

    }
}