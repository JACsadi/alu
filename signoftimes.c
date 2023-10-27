  #include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
  int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        int *a = (int*) calloc(n, sizeof(int));
        int r = 0;
        f(i,m) {
            int b;
            scanf("%d", &b);
            a[b-1]++;
            r = r > a[b-1] ? r : a[b-1];
    }
     int l = 1, mid, ans;
     while(l <= r) {
      ll sum = m;
      mid = (l+r+1) / 2;
      f(i, n) {
      sum -=  mid < a[i] ? mid : (a[i] + ((mid -a[i])/2)); 
      }
      if(sum > 0) l = mid + 1;
      else {
         r = mid - 1;
         ans = mid;
      }
     }
     printf("%d\n", ans);
  }
  return 0;
  }