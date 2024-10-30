    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>
    #include <malloc.h>
    #include <math.h>
    #include <iostream>
    #include <queue>
    #define ll long long
    #define ull unsigned long long
    #define f(i, n) for(int i = 0; i < n; i++)
    #define ma(k, n) (k*) malloc(n*sizeof(k));
    #define ima(y, k, n) k* y = (k*) calloc((n),sizeof(k));
    #define sd(i) scanf("%d", &i)
    #define Max(a,b) a < b ? b : a;
    #define Min(a,b) a > b ? b : a;
    #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
    #define en printf("\n")
    using namespace std;
    int main() {
      tcase {
        int n;
        sd(n);
        ima(arr,int,n+5);
        f(i,n) {
          int a; sd(a);
          if(a < n+5) arr[a] = 1;
        }
        f(i,n+1) {
          if(!arr[i]) {
            int j = i;
            while (1) {
              printf("%d\n", j);
              fflush(stdout);
              int y; sd(y);
              if(y==-1) {
                break;
              } else j = y;
            }
            break;
          }
        }
      }
      return 0;
    }