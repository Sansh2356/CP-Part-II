#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
//Codeforces div-2  string with a target //
using namespace std;
int main() {
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    string s;
    cin >> s;
    string s2 = s;
    string empty = "";
    sort(s2.begin(), s2.end());
    char max = s2[0];
    if (s[0] != max) {
      bool flag = true;
      for (int x = 0; x < n; x++) {
        if (s[x] == max && flag == true) {
          flag = false;
          continue;
        } else {
          empty.push_back(s[x]);
        }
      }
      empty = max + empty;
      cout << empty << endl;
      continue;
    }
    if (s[0] == max) {
      bool flag = true;
      for (int f = 1; f < n; f++) {
        char ch = s[f];
        if (ch == max && f != 1 && flag == true) {
          if (s[f + 1] == max && s[f - 1] == max) {
            empty.push_back(ch);
            continue;
          }
          if (s[f + 1] != max && s[f - 1] == max) {
            empty.push_back(ch);
            continue;
          }
          if (s[f + 1] != max && s[f - 1] != max) {
            flag = false;
            continue;
          }
          if (s[f - 1] != max && s[f + 1] == max) {
            flag = false;
            continue;
          }

        } else {
          empty.push_back(ch);
        }
      }
      empty = max + empty;
      if (flag == false) {
        empty = max + empty;
      }
      cout << empty << endl;
      continue;
    }
  }
}