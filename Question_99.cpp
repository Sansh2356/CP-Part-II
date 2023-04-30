#include<string>
#include<iostream>
using namespace std;
class Solution {
public:
    int addMinimum(string word) {
        int count = 0;
        if(word.length() == 1){
            return 2;
        }
        for(int m=0;m<word.length();m++){
            char ch = word[m];
            if(ch == 'a'){
                if(word[m+1] == 'a'){
                    count+=2;
                    continue;
                }
                else if(word[m+1] == 'b' && word[m+2] != 'c' ){
                    count+=1;
                    m = m+1;
                    continue;
                }
                else if(word[m+1] == 'b' && word[m+2] == 'c'){
                    m = m+2;
                    continue;
                }
                else if(word[m+1] == 'c'){
                    count+=1;
                    m = m+1;
                    continue;
                }
                 if(m == (word.length()-1)){
                     count+=2;
                 }
            }
            else if(ch == 'b'){
                 if(word[m+1] == 'b'){
                    count+=2;
                    continue;
                }
                if(word[m+1] == 'c'){
                    count+=1;
                    m = m+1;
                }
                else if(word[m+1] != 'c'){
                    count+=2;
                    continue;
                }
            }
            else{
                    count+=2;
                    continue;
            }
        }
        return (count);
    }
};