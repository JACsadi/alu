#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;
int main() {
   ll n,m;
   scanf("%lld %lld",&n,&m);
   ll ans =0;
   for(ll i=1; i <= m; i++) {
      ans = (ans+ (n%i))%mod;
   }
   printf("%lld ",ans);
    return 0;
}