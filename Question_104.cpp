#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        vector<int>v(n);
        int f;
        bool flag = true;
        for(int m=1;m<101;m++){
            int num_of_pos = m;
            int num_of_neg = (n-m);
            int val = num_of_pos*(num_of_pos-1)/2+(num_of_neg-1)*(num_of_neg)/2;
            if(k == val){
                f = m;
                flag = false;
                break;
            }
        }
        if(flag == false){
            cout<<"yes"<<endl;
            for(int j=0;j<f;j++){
                cout<<1<<" ";
            }
             for(int k=0;k<(n-f);k++){
                cout<<-1<<" ";
            }
        }
        else if(flag == true){
            cout<<"No"<<endl;
        }
    }
}