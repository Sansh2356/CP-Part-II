#include <iostream> 
#include <vector> 
using namespace std; 

int fun(vector<vector<int> > a, vector<vector<int> > t, 
		int cl, int cs, int x1, int x2, int n) 
{ 
	// base case 
	if (cs == n - 1) { 
		if (cl == 0) { // exiting from (current) line =0 
			return x1; 
		} 
		else // exiting from line 2 
			return x2; 
	} 
	// continue on same line 
	int same 
		= fun(a, t, cl, cs + 1, x1, x2, n) + a[cl][cs + 1]; 
	// continue on different line 
	int diff = fun(a, t, !cl, cs + 1, x1, x2, n) 
			+ a[!cl][cs + 1] + t[cl][cs + 1]; 

	return min(same, diff); 
} 
int main() 
{ 
	int n = 4; // number of statin 
	vector<vector<int> > a 
		= { { 4, 5, 3, 2 }, { 2, 10, 1, 4 } }; 
	vector<vector<int> > t 
		= { { 0, 7, 4, 5 }, { 0, 9, 2, 8 } }; 

	int e1 = 10; 
	int e2 = 12; 
	int x1 = 18; 
	int x2 = 7; 
	// entry from 1st line 
	int x = fun(a, t, 0, 0, x1, x2, n) + e1 + a[0][0]; 
	// entry from 2nd line 
	int y = fun(a, t, 1, 0, x1, x2, n) + e2 + a[1][0]; 
	cout << min(x, y) << endl; 
}
