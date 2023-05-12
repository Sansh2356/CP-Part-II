#include <iostream>
#include <string>
using namespace std;
int main()
{
    class Solution
    {
    public:
        int count = INT_MIN;
        int maxVowels(string name, int k)
        {
            int count2 = 0;
            string s2 = name.substr(0, k);
            for (int x = 0; x < k; x++)
            {
                char ch = s2[x];
                if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                {
                    count2++;
                }
                count = max(count2, count);
            }
            if (s2[0] == 'a' || s2[0] == 'e' || s2[0] == 'i' || s2[0] == 'o' || s2[0] == 'u')
            {
                count2--;
            }
            for (int m = 1; m <= name.length() - k; m++)
            {
                string s = name.substr(m, k);
                if (s[s.length() - 1] == 'a' || s[s.length() - 1] == 'e' || s[s.length() - 1] == 'i' || s[s.length() - 1] == 'o' || s[s.length() - 1] == 'u')
                {
                    count2++;
                }
                count = max(count2, count);
                if (s[0] == 'a' || s[0] == 'e' || s[0] == 'i' || s[0] == 'o' || s[0] == 'u')
                {
                    count2--;
                }
            }
            return count;
        }
    };
}