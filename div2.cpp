#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;
int bs(vector<ll>& arr,int n, ll tar) {
   int l = 0, r= n-1, ans = 0;
   while(l <= r) {
     int m = (l+r)/2;
     if(arr[m] < tar) {
       ans = m;
       l = m+1;
     } else r = m-1;
   }
   return ans + 1;
}
int main() {
    int n;
    sd(n);
    vector<ll> arr(n,0);
    vector<ll> pre(n+1,0);
    vector<ll> prepresum(n+1,0);
    vector<ll> presum(n+1,0);
    vector<ll> nth(n+1,0);
    f(i,n) {
       nth[i+1] = nth[i] + (n-i);
    }
    f(i,n){
       scanf("%lld", &arr[i]);
       pre[i+1] = pre[i]+arr[i];
       presum[i+1] = presum[i] + pre[i+1];
       prepresum[1] += pre[i+1];
    }
  
    f(i,n) {
      if(i==0) continue;
      prepresum[i+1] = prepresum[i] + (prepresum[i] - prepresum[i-1]  - (n-i+1)*arr[i-1]);
    }
    f(i,n) printf("%lld ",pre[i+1]);
    en;
    f(i,n) printf("%lld ",presum[i+1]);
    en;
    f(i,n) printf("%lld ",prepresum[i+1]);
    en;
    int q; sd(q);
    while(q--) {
      ll l,r;   scanf("%lld %lld", &l,&r);
      int pl = bs(nth,n,l);
      int pr = bs(nth,n,r);
      // printf("%d %d\n",pl,pr);
      ll ans = 0;
      if(l+(l != nth[pl-1] - (n-(pl-1)) + 1) <= r-(r != nth[pr-1])) {
       ans += prepresum[r-(r != nth[pr-1])] - prepresum[l+(l != nth[pl-1] - (n-(pl-1)) + 1)-1]; 
      }
      int lth = l - (pl == 1 ? 0 : nth[pl-2]);
      if(lth != 1) {
         ans += (presum[n]- presum[lth-1]) - (presum[])
      }
      
    }
    return 0;
}