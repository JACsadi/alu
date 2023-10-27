  #include <stdio.h>

  #include <string.h>

  #include <stdlib.h>

  #include <malloc.h>

  #include <math.h>
  #define f(i, n) for (int i = 0; i < n; i++)
  #define ll  long long
  ll x,y;
  ll gcd(ll a, ll b) {
      if(b == 0) {
          x = 1;
          y = 0;
          return a;
      }
      else{
          ll k = gcd(b, a%b);
          ll temp = y;
          y = x - ((a/b)*y);
          x = temp;
          return k;
      }
  }
int main() {
   int t;
   scanf("%d",&t);
    while(t--) {
        double i,k;
        scanf("%lf %lf", &i,&k);
        ll a = (ll)floor(i/k);
        ll b = (ll)ceil(i/k);
        ll gg = gcd(a,b);
        ll kk = (ll)i / gg;
        printf("%lld %lld\n", x*kk, y*kk);
    }
    return 0;
}