#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;
vector<int> myz(char* str, int n) {
  vector<int> zvalue(n,0);
  int l = 0, r= 0;
 
  for(int i = 1; i < n; i++) {
    //  printf("%d %d %d\n",i,l,
    if(i > l && i <= r ) {

        if(i+zvalue[i-l] > r) {
           zvalue[i] = r-i+1;
           int orr= r;
           for(int j = orr+1; j<n;j++) {
            // printf("%d",j);
            if(str[j] == str[j-i]) {
                l = i;
                r=j;
            } else {zvalue[i] += j-orr-1;break;}
            if(j==n-1) zvalue[i] += j-orr;
        }
        }
        else  zvalue[i] = min(zvalue[i-l], n-i);

    } else {
       
        for(int j = i; j<n; j++) {
            if(str[j] == str[j-i]) {
                l = i;
                r=j;
            } else {zvalue[i] = j-i;break;}
            if(j==n-1)zvalue[i] = j-i+1;
        }
    }
  }
  return zvalue;
}
int main() {
    char str[1000010]; scanf(" %s",str);
    int n = (int)strlen(str);
    vector<int> zval = myz(str,n);
    // zval[0] = n;
    for(int i = n-1; i > 0; i--) if(i+zval[i] == n) printf("%d ",zval[i]);
    return 0;
}