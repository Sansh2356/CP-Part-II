#include<vector>
#include<numeric>
using namespace std;
class Solution {
public:
/*
bool lcm2(vector<int>ans,int &count,int k){
    sort(ans.begin(),ans.end());
    int max_val = ans[ans.size()-1];
    for(int m=0;m<ans.size();m++){
        if(lcm(max_val,ans[m]) != k){
            return false;
        }
    }
    return true;

}
*/
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        for(int j=0;j<n;j++){
            int ele = nums[j];
            if(ele == k){
                count++;
            }
            int g = ele;
            for(int m=j+1;m<nums.size();m++){
                g = lcm(nums[m],g);
                if(g == k){
                    count++;
                }
                else if(g < k){
                    continue;
                }
                else{
                    break;
                }

            }
        }
        return count;
    }
};