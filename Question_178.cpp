#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
      class Solution {
public:
    int kthGrammar(int n, int k) {
        if(n == 1)return 0;
         if(k%2 == 0){
            int c = kthGrammar(n-1,k/2);
            if(c == 0)return 1;
            else{
                return 0;
            }
        }
        else{
            int b = kthGrammar(n-1,(k+1)/2);
            if(b == 0)return 0;
            else{
                return 1;
            }
        }
    }
};
    }
}
