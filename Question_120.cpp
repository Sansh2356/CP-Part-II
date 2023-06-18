#include <iostream>
using namespace std;
int main()
{
   class Solution
   {
   public:
      int minLength(string s)
      {
         bool flag = false;
         string s2 = s;
         string s3 = "";
         while (flag == false)
         {
            for (int x = 0; x < s2.length(); x++)
            {
               char ch1 = s2[x];
               char ch2 = s2[x + 1];
               if (x == s2.length() - 1)
               {
                  break;
               }
               if (ch1 == 'A' && ch2 == 'B' || ch1 == 'C' && ch2 == 'D')
               {
                  string f = s2.substr(x + 2, s2.length());
                  flag = true;
                  s2 = s3 + f;
                  break;
               }
               else
               {
                  s3.push_back(ch1);
               }
            }
            if (flag == true)
            {
               flag = false;
               s3 = "";
            }
            else if (flag == false)
            {
               flag = true;
            }
         }

         return s2.length();
      }
   };
}