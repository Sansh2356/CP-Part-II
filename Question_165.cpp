#include<iostream>
using namespace std;
bool rec(int row,int col,int a,int b,int s1,int s2,bool flag){
   //Base case//
   if(row == s1 && col == s2){
    return true;
   }
   bool a1=false;
   bool a2 = false;
   for(int x=1;x<=a;x++){
        if(row+x <= s1 && flag == true){
            a1 = rec(row+x,col,a,b,s1,s2,false);
        }
        else{
            break;
        }
   }
   for(int x=1;x<=b;x++){
      if(col+x <= s2 && flag == false){
        a2 = rec(row,col+x,a,b,s1,s2,true);
      }
      else{
        break;
      }
   }
   return a1^a2;


}
int main(){
    int t;
    cin>>t;
    int b2=0;
    while(t--){
       int r,c,a,b;
       cin>>r>>c>>a>>b;
       if(rec(0,0,a,b,r-1,c-1,true)==false){
        b2++;
        cout<<"Case #"<<b2<<":"<<" "<<"NO"<<endl;
        
       }
       else{
        b2++;
         cout<<"Case #"<<b2<<":"<<" "<<"YES"<<endl;
       }
       
    }

}