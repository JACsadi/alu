      #include <stdio.h>
      #include <string.h>
      #include <stdlib.h>
      #include <malloc.h>
      #include <math.h>
      #include <iostream>
      #include <queue>
      #include <map>
      #define ll long long
      #define ull unsigned long long
      #define f(i, n) for(int i = 0; i < n; i++)
      #define ma(k, n) (k*) malloc(n*sizeof(k));
      #define ima(y, k, n) k* y = (k*) calloc((n),sizeof(k));
      #define sd(i) scanf("%lld", &i)
      #define Max(a,b) ((a) < (b) ? (b) : (a))
      #define Min(a,b) ((a) > (b) ? (b) : (a))
      #define tcase ll t;sd(t);for(int casee = 1; casee <= t; casee++)
      #define en printf("\n")
      #define inf 102
      // #define mod 1000000007
      ll mod;
      ll binExp(ll b, ll e) {
         ll ans = 1;
         b %= mod;
         while (e > 0) {
         if (e & 1)
         ans = (ans * b) % mod;
         e >>= 1;
         b = (b * b) % mod;
    }
    return ans % mod;
}
      using namespace std;
      int main() {
        tcase {
           ll n,k;
           sd(n);sd(k);sd(mod);
           ll ans = binExp(n,k);
           printf("%lld\n", ans);
        }
      }