#include <iostream>
using namespace std;
#include <unordered_map>
int main()
{
    unordered_map<int, int> dp;
    int size;
    int *arr = new int[size];
    int difference;
    int ans = 0;
    for (int x = 0; x < size; x++)
    {
        int number = arr[x] - difference;
        //Checke before this element if any other number exists with difference d//
        int temp = 0;
        //get the answer stored for that number//
        if (dp.count(number) == true)
        {
            temp = dp[number];
        }
        //update the answer for the current index by prevans + 1//
        dp[arr[x]] = 1 + temp;
        //Update the ans to get maximum among all the numbers//
        ans = max(ans, dp[arr[x]]);
    }
}