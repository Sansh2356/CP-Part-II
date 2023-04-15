#include <iostream>
using namespace std;

int main() {
	// your code goes here//
	int t;
	cin>>t;
	while(t--){
	    long long n;
	    cin>>n;
	    long long ans = 0;
	    for(long long f = 1; f<10e10;f++){
	        if(f*20 > n){
	            ans = (n % ((f-1)*20));
	            break;
	        }
	    }
	    cout<<ans<<endl;
	}
	return 0;
}
