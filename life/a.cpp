#include <iostream>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int r; cin >> r;
    while(r--){
        int v; cin >> v;
        if(v % 2 == 0){
            cout << -1 << "\n";
            continue;
        }
        for (int j = 1; j <= v; j++){
            int z = (2 * j) % v;
            if(z == 0) z = v;
            cout << z << " ";
        }
        cout << "\n";
    }
    return 0;
}
