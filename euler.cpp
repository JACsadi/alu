#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
double a,b,c,v,x,y,z;
#define ex (1e-5)
double setprecision(double k) {
   return floor(k*100000)/100000;
}
void surface(double val) {
     double l = 1.0, r = val;
    double ans = 100000000.0;
    while (r-l > 1e-9)
    {
    double m = (l+r) / 2.0; 
    x = setprecision(m);
    y = setprecision(val/x);
    ans = (b*x) + (c*val / y);
    double backans = (b*setprecision(m-ex)) + (c*setprecision(val / m-ex));
    if(ans < backans)  l = m+ex;
    else r = m-ex;
    }
}
double bs() {
    double l = 1.0, r = v;
    double ans ;
    while (r-l > 1e-9)
    {
      double m = (l+r) / 2.0; 
      surface(v/m);
      z = setprecision(m);
      ans = (x*y*a) + (x*z*b) + (y*z*c);
      surface(v/(z-(ex)));
      z = setprecision(m-ex);
      double backans =  (x*y*a) + (x*z*b) + (y*z*c);
      if(ans < backans)  l = m + ex;
      else r = m - ex;
    }
    return ans;
}
int main() {
    int t;
    scanf("%d", &t);
  while(t--) {
    scanf(" %lf %lf %lf %lf",&a,&b,&c,&v);
    printf("%lf\n", 2.0*bs());
    printf("%lf %lf %lf %lf", x,y,z, 2*((x*y*a) + (x*z*b) + (y*z*c)));
  } 
}