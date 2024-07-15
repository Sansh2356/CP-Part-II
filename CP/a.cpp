
#include <iostream>
#include <cmath>
using namespace std;
#include <vector>
#include <numeric>
int rec(int a){
  return a >= 5 ? 5 : -1;
}
int main()
{
  cout<<rec(4)<<endl;
}

