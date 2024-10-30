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
const int debug = 1;
double check(double u, double v, double t, double x) {
    return (((u+x)*(x-u)/2) + (x*(t+u+v-(2*x))) + ((v+x)*(x-v)/2));
}
double bs(double u,double v, double t, double l,double r) {
    double ans = 0; double m;
    if(r-l > 1e5) {
        m = (l+r)/2;
        ans = check(u,v,t,m);    
        if(checkans(u,v,t,m+1e5) > ans) {
            l = m+1e+5;
            } else if(checkans(u,v,t,m-1e5) > ans) {
                r = m-1e+5;
            }
        else  break;
    }
    return m;
}
int main() {
    int n; sd(n);
    double ans = 0;
    ima(t,double,n);
    ima(v,double,n);
    f(i,n) scanf("%lf", &t[i]);
    f(i,n) scanf("%lf", &v[i]);
    for(int i = n-1; i>= 0;i--) v[i] = ((i < n- 1 ?v[i+1] : 0)+t[i] < v[i] ? (i < n- 1 ?v[i+1] : 0)+t[i] : v[i]);
    if(debug) f(i,n) printf("%lf \n", t[i]);
    double enterspeed = 0;
    f(i,n) {
       if((i < n- 1 ?v[i+1] : 0) - enterspeed  > t[i]) {
        ans += ((2*enterspeed) + t[i])*t[i]/2;
        enterspeed  += t[i];
       } else {
          double x = (t[i] + enterspeed + (i < n- 1 ?v[i+1] : 0))/2 < v[i] ?  (t[i] + enterspeed + (i < n- 1 ?v[i+1] : 0))/2;
           if(debug) printf("%lf %lf %lf %.3lf\n", enterspeed, (i < n- 1 ?v[i+1] : 0), x, ans);
           ans += bs((enterspeed<v[i+1]?enterspeed:v[i+1]), (v[i+1] > enterspeed ?v[i+1]:enterspeed), t[i], x);
       }
    }
    printf("%.4lf\n", ans);
    return 0;
}