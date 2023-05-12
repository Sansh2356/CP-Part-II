#include<iostream>
#include<vector>
using namespace std;
int main(){
    int s=0;
    int e =0;
    vector<int>v = {2,1,1};
    vector<vector<int>>v2;
    vector<int>v3;
    while(s <= e){
        v3.push_back(v[e]);
        for(int m=0;m<v3.size();m++){
            cout<<v3[m];
        }
        cout<<endl;
        v2.push_back(v3);
            e++;
            if(e == v.size()-1){
                v3.push_back(v[e]);
                v2.push_back(v3);
                s++;
                if(s == v.size()-1){
                    break;
                }
                e = s;
                v3.clear();
            }    
    }
    
    // for(int s=0;s<v2.size();s++){
    //     for(int x=0;x<v2[s].size();x++){
    //         cout<<v2[s][x];
    //     }
    //     cout<<endl;
    // }
}