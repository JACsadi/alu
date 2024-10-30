  #include <stdio.h>
      #include <string.h>
      #include <stdlib.h>
      #include <malloc.h>
      #include <math.h>
      #include <iostream>
      #include <queue>
      #include <map>
      using namespace std;

      int main() {
       int n,m;
       cin >> n >> m;
       double min = 1000.0;
      for(int i = 0; i <n; i++) {
        double a,b;
        cin >> a>> b;
        double kk = a/b;
        min = min < kk ? min : kk;
      }
      printf("%.8lf", min*m);
      }