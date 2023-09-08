 #include <stdio.h>

  #include <stdarg.h>

  #include <string.h>

  #include <stdlib.h>

  #include <math.h>

  #define ll long long
  #define f(i, n) for (ll i = 0; i < n; i++)
  int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
      int n;
      ll sum = 0;
      scanf("%d", &n);
      ll *a =  (ll*) calloc(2*n,sizeof(ll)); 
      f(i,n) {
        ll val;
        scanf("%lld", &val);
        val -= i;
        if(val < 0) val = abs(val) + n;
        a[val]++;  
      }  
      f(i, (2*n)) {
        if(a[i] > 0) sum += ((long long)a[i] * (long long)(a[i]-1))/2; 
      }
      printf("%lld\n", sum);
    }
  }