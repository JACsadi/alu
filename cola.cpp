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
      while (t--) {
        int n, f, w;
        scanf("%d %d %d", &w, &f, &n);
        int ** a = (int**) malloc(n * sizeof(int*));
        f(i, n) {
          a[i] = (int * ) calloc(4 , sizeof(int)); // sum , time, wrem,trem
          scanf("%d", &a[i][0]);
          if (i > 0) a[i][0] += a[i - 1][0];
          if (w > f) {
            a[i][1] = (a[i][0] / w) + ((a[i][0] % w == 0) ? 0 : 1);
            a[i][2] = (a[i][1] * w) - (a[i][0]);
            a[i][3] = (a[i][1] * f);
          } else {
            a[i][1] = (a[i][0] / f) + ((a[i][0] % f == 0) ? 0 : 1);
            a[i][3] = (a[i][1] * f) - (a[i][0]);
            a[i][2] = (a[i][1] * w);
          }
          printf("%d\n", a[i][1]);
          f(j, i) {
            int k = a[i][0] - a[j][0];
            int t = a[j][1];
            int wrem = a[j][2];
            int frem = a[j][3];
            int key = 0;
            key = a[i][1] <= (t + (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0))
             ? (a[i][1] <= (t + (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0)) ?
              0 : 2 )
              : ((t + (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0)) == (t + (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0))
               ? 3 : ((t + (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0)) < (t + (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0))
               ? 1 : 2));
                 printf("%d\n", a[i][1]);
           if(key == 1) {
              a[i][1] = (t + (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0));
              a[i][2] = (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0)*w - k + wrem;
              a[i][3] = (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0)*f + frem;
           } else if(key == 2) {
             a[i][1] = (t + (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0));
              a[i][2] = (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0)*w + wrem;
              a[i][3] = (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0)*f + frem - k;
           } if(key == 3) {
            if(f>w) {
              a[i][1] = (t + (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0));
              a[i][2] = (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0)*w - k + wrem;
              a[i][3] = (((k - wrem < 0 ? 0 : k - wrem)) / w) + (((k - wrem < 0 ? 0 : k - wrem)) % w > 0 ? 1 : 0)*f + frem;
            } else {
                a[i][1] = (t + (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0));
              a[i][2] = (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0)*w + wrem;
              a[i][3] = (((k - frem < 0 ? 0 : k - frem)) / f) + (((k - frem < 0 ? 0 : k - frem)) % f > 0 ? 1 : 0)*f + frem - k;
            }
           }
          }
         
        }
         printf("%d\n", a[n-1][1]);
      }
    }