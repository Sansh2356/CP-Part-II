#include<iostream>
#include<stack>
#include<queue>
using namespace std;
//Buy and sell a stock with transaction fees recursive solution //
int main(){
class Solution {
public:
     int stock(vector<int>&v,int buy,int index,int fee)
    {
        if(index==v.size())
        {
            return 0;
        }
       
        int profit=0;
        
        if(buy)
        {
            
            int not_buy=stock(v,1,index+1,fee);
            int buy= -v[index]+stock(v,0,index+1,fee);
            profit=max(buy,not_buy);
        }
        else
        {
         
            int sell=v[index]-fee+stock(v,1,index+1,fee);
            int not_sell=stock(v,0,index+1,fee);
            profit=max(sell,not_sell);
        }
        return profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        
    
      return stock(prices,1,0,fee);
    }
};
    
}