#include<iostream>
#include<vector>
using namespace std;
//Prefix sum for odd quries//
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        vector<long long>v(n);
        long long sum = 0;
        for(int m=0;m<n;m++){
            cin>>v[m];
        }
        vector<long long>prefix_array(n);
        prefix_array.push_back(0);
        for(int s=1;s<n;s++){
            prefix_array[s] = prefix_array[s-1] + v[s];
        }
        for(int f=0;f<q;f++){
            long long l,r,k;
            cin>>l>>r>>k;
            long long num2 = k*(r-l+1);
            sum = prefix_array[n]+prefix_array[r]-prefix_array[l-1]+num2;
            if(sum % 2 == 0){
                cout<<"No"<<endl;
            }
            else{
                cout<<"Yes"<<endl;
            }
                
            }
            
        }
    }