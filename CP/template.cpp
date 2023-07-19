#include<map>
#include<queue>
#include<stack>
#include<iostream>
#include<algorithm>
#include<vector>
#include<unordered_map>
//#include <bits/stdc++.h>
#include<set>
using namespace std;


#define ll long long;
#define unsigned long long ull;

int main(){
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    // vector<vector<int>>v(4,vector<int>(4,-1));
    // int*arr =new int[2];
    int arr1[2][2] = {{1,2},{3,-1}};
    sort(arr1,arr1+2);
    for(int x=0;x<2;x++){
        for(int y=0;y<2;y++){
            cout<<arr1[x][y]<<endl;
        }
    }
}
