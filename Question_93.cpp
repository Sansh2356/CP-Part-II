#include<iostream>
#include<vector>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        bool flag = false;
        int n;
        cin>>n;
        vector<int>v(n);
        for(int m=0;m<n;m++){
            cin>>v[m];
        }
        for(int x=0;x<2e8;x++){
            int li = 0;
                for(int s=0;s<n;s++){
                    int val = (x^v[s]);
                    if(s == 0){
                        li = val;
                    }
                    else{
                        li = (li^val);
                    }
                }
                if(li == 0){
                    cout<<x<<endl;
                    flag = true;
                    break;
                }
                else {
                    continue;
                }
               
    }
    if(flag == true){
        continue;
    }
    else {
        cout<<-1<<endl;
    }

}
}