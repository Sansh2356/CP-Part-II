#include <iostream>
#include <string>
using namespace std;

int main()
{
    // your code goes here
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        if (s.length() <3)
        {
            int b = stoi(s);
            if (b % 8 == 0)cout<<s<<endl;
                
            else if (b % 8 != 0)
            {
                
                if (s.length() == 1)
                {
                    cout << 8 << endl;
                    continue;
                }
                else if(s.length() == 2){
                    if(s[0]=='0')cout<<"08"<<endl;
                        
                
                
                        if(s[0]=='1')cout<<"16"<<endl;
                
                 
                        else if(s[0]=='2')cout<<"24"<<endl;
                
                
                
                        else if(s[0]=='3')cout<<"32"<<endl;
                        
                
                
                        else if(s[0]=='4')cout<<"40"<<endl;
                        
                
                
                        else if(s[0]=='5')cout<<"56"<<endl;
                        
                
                
                        else if(s[0]=='6')cout<<"64"<<endl;
                        
                
               
                        else if(s[0]=='7')cout<<"72"<<endl;
                        
                
                 
                        else if(s[0]=='8')cout<<"80"<<endl;
                        
                
                 
                        else if(s[0]=='9')cout<<"96"<<endl;
                }
               
                
                        
            }
        }
        else
        {
            // cout<<"B"<<s<<endl;
            string s2 = "";
            s2.push_back(s[s.length() - 3]);
            s2.push_back(s[s.length() - 2]);
            s2.push_back(s[s.length() - 1]);
            int num = stoi(s2);
            if (num % 8 == 0)cout << s << endl;
                
            else if (num % 8 != 0)
            {
                char ch1 = s2[0];
                char ch2 = s2[1];
                char ch3 = s2[2];
                s.pop_back();
                s.pop_back();
                s.pop_back();
                string s3 = "";
                string s4 = "";
                int ans = 4;
                for (int x = 0; x <= 9; x++)
                {
                    s3.push_back(to_string(x)[0]);
                    for (int f = 0; f <= 9; f++)
                    {
                        s3.push_back(to_string(f)[0]);
                        for (int k = 0; k <= 9; k++)
                        {
                            s3.push_back(to_string(k)[0]);
                            int t1 = stoi(s3);
                            if (t1 % 8 == 0)
                            {
                               //cout<<s3<<endl;
                                int cnt = 0;
                                for (int l = 0; l < 3; l++)
                                {
                                    if (s3[l] != s2[l])
                                        cnt++;
                                }
                                if (cnt < ans)
                                {
                                    s4 = s3;
                                    ans = cnt;
                                }
                            }
                            s3.pop_back();
                        }
                        s3.pop_back();
                    }
                    s3.pop_back();
                }
                cout << s + s4 << endl;
            }
        }
    }
    return 0;
}
