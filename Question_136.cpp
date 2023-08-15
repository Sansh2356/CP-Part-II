#include <iostream>
#include <algorithm>
using namespace std;
#include <stack>
#include <vector>
int main()
{
    class Solution
    {
    public:
        vector<int> asteroidCollision(vector<int> &v)
        {
            vector<int> ans;

            stack<int> st;
            for (int x = 0; x < v.size(); x++)
            {
                int num = v[x];
                if (st.empty() == true)
                {
                    st.push(num);
                    continue;
                }
                else
                {
                    int a = st.top();
                    if (a > 0 && num > 0 || a < 0 && num < 0)
                    {
                        st.push(num);
                    }
                    else
                    {
                        if (a < 0 && num > 0)
                        {
                            st.push(num);
                            continue;
                        }
                        if (abs(a) > abs(num))
                        {
                            // The number will get exploded and no entry inside the stack//
                            continue;
                        }
                        else if (abs(a) < abs(num))
                        {
                            // the number will be left as the magnitude is greater in size //
                            // loop will be there till the collisions stop//
                            st.pop();
                            st.push(num);
                            bool flag = true;
                            while (flag == true && st.empty() != true)
                            {
                                int f = st.top();
                                st.pop();
                                if (st.top() > 0 && f > 0 || st.top() < 0 && f < 0)
                                {
                                    flag = false;
                                    st.push(f);
                                    continue;
                                }
                                else
                                {
                                    if (abs(st.top()) > abs(f))
                                    {
                                        flag = false;
                                        continue;
                                    }
                                    else
                                    {
                                        st.pop();
                                        st.push(f);
                                    }
                                }
                            }
                        }
                        else
                        {
                            st.pop();
                        }
                    }
                }
            }
            while (st.empty() != true)
            {
                ans.push_back(st.top());
                st.pop();
            }
            reverse(ans.begin(), ans.end());
            return ans;
        }
    };
}
