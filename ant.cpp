#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll  long long
#define f(i,n) for(int i = 0; i <n; i++)
int main() {
     int n;
     scanf("%d", &n);
    int k = n % 4;
     k == 0 || k == 3 ? printf("0\n") : printf("1\n");
    int z = n/4;
    printf("%d ", (z*2) + (k > 0 ? 1 : 0));
     f(i, n/4) {
     printf("%d %d ", k + (2*i) + 1, n-(2*i));
     }
     if(k) printf("%d", k);    
     return 0;
}
// 1 4       2 3 - 0 - 0
//  2 5 1   3 4  - 1 - 1
//  3 6 2   1 4 5  - 2 - 1
//  4 7 3   5 6 1 2 - 3 - 0