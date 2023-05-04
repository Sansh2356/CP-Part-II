#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
int main(){
      class Solution {
public:
    int index1;
    int index2;
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        unordered_map<int,pair<int,int>>m;
        for(int s=0;s<mat.size();s++){
                for(int f=0;f<mat[0].size();f++){
                    pair<int,int>p1;
                    p1.first =s;
                    p1.second = f;
                        m[mat[s][f]] = p1; 
                }
        }
        vector<int>row(mat.size(),0);
        vector<int>column(mat[0].size(),0);
        for(int k=0;k<arr.size();k++){

            bool flag = true;
            int num = arr[k];
               
                        if(i.first == num){
                        flag = false;
                            row[i.second.first]++;
                            column[i.second.second]++;
                            index1 = i.second.first;
                            index2 = i.second.second;
                            break;
                        
                }
            if(flag == false){
                if(row[index1] == mat[0].size() || column[index2] == mat.size() ){
                    return k;
                }
            }
             
        }
        return INT_MIN;
        
        
    }
};
       
}