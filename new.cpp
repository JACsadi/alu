#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
ll bs(ll n, ll l, ll r) {
  if(l > r) return n+2;
    ll m = (l+r) / 2;
    ll kk = (n%m)+(n/m);  
    if(kk < m) {
      ll ans;
      if(kk == m - 1) {
        ans = bs(n, m+1, r); 
      } else  ans = m;
      return ans < bs(n, l, m-1) ? ans : bs(n, l, m-1);
    }
    else return bs(n, m+1, r);
  }
  int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    ll n;
    scanf("%lld", &n);
    for(ll i =1005727; i < 1005758; i++) {
      if((n/i) == (n/(i-1))) printf("%lld\n", i);
    }
    // printf("%lld\n", bs(n,3,n+2));
  }
  return 0;
  }