#include <bits/stdc++.h>
using namespace std;
class Solution {
    int dp[101][101];
     map<char,vector<int>> mymap;
    string z;
    int rangedp(int l, int r) {
     if(l > r) return 0;
     if(dp[l][r] != 0) return dp[l][r];
     if(l == r) return dp[l][r] = 1;
    for(int i = l; i <= r; i++) {
    if(i == l) dp[l][i] = 1;
    else {
        dp[l][i] = 1+dp[l][i-1];
        for(int x : mymap[z[l]]) {
          if(x >= i) break;
          dp[l][i] = min(dp[l][i], dp[l][x]+rangedp(x+1, i-1));
        }
    }
    }
  
      return dp[l][r];
    }
public:
    int strangePrinter(string s) {
        z = s;
        int n = s.length();
        for(int i = 0; i<n;i++) mymap[s[i]].push_back(i);
        return rangedp(0,n-1);
    }
};