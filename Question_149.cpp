#include <iostream>
#include <stack>
#include <vector>
using namespace std;
int main()
{
    class Solution
    {
    public:
        bool check(string s)
        {
            stack<int> st;
            for (int x = 0; x < s.length(); x++)
            {
                char ch = s[x];
                if (st.empty() == true)
                {
                    st.push(ch);
                }
                else if (st.top() == '(' && ch == ')')
                {
                    st.pop();
                }
                else
                {
                    st.push(ch);
                }
            }
            if (st.empty() == true)
            {
                return true;
            }
            return false;
        }
        void rec(int n, string ele, vector<string> &v, string s)
        {
            if (ele.size() == n * 2)
            {
                if (check(ele) == true)
                    v.push_back(ele);
                return;
            }
            for (int x = 0; x < s.length(); x++)
            {
                ele.push_back(s[x]);
                rec(n, ele, v, s);
                ele.pop_back();
            }
        }
        vector<string> generateParenthesis(int n)
        {
            vector<string> v;
            string s = "()";
            rec(n, "", v, s);
            return v;
        }
    };
}