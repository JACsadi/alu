#include <inttypes.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k));
#define sd(i) scanf("%d", &i)
ull bs(ull arr, int l, int r, ull tar) {
      
}
int main() {
    int t;
    sd(t);
    while(t--) {
        int n,q; sd(n);sd(q);
        ima(ele,int,0);
        ima(lastsum,ull,0);
        int siz = 0;
        ull last = 0;
        f(i,n) {
            int b; ull x; sd(b); scanf("%llu", &x);
            if(last >= (ull)1e18) continue;
            if(b==1) {
                siz++;
                ele = (int*) realloc(ele, siz*sizeof(int));
                lastsum = (ull*) realloc(lastsum, siz*sizeof(ull));
                ele[siz-1] = (int)x;
                lastsum[siz-1] = last++;
            } else {
                if((ull)1e18/(x+1) > (last)) last = (last)*(x+1);
                else {
                last = 1e18;
                siz++;
                ele = (int*) realloc(ele, siz*sizeof(int));
                lastsum = (ull*) realloc(lastsum, siz*sizeof(ull));
                ele[siz-1] = -1;
                lastsum[siz-1] = last;
                }
                if(i == n-1 &&  last != 1e18) {
                siz++;
                ele = (int*) realloc(ele, siz*sizeof(int));
                lastsum = (ull*) realloc(lastsum, siz*sizeof(ull));
                ele[siz-1] = -1;
                lastsum[siz-1] = last;
                }
            }
        }
        
    }
    return 0;
}