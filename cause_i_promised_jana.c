#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
# define ma(k, n) (k*) malloc(n*sizeof(k*));
int check(int** arr, int k,int n) {
    int left = 0, right = 0;
    int flag = 1;
    int j = 0;
    while(j < n) {
        if(left-k > arr[j][1] || right+k < arr[j][0]) {
            flag = 0;
            break;
        } 
        left = (left-k) > arr[j][0] ? (left-k) : arr[j][0];
        right = (right+k) > arr[j][1] ? arr[j][1] : right+k;
        j++;
    }
    return flag;
}
int bs(int** arr, int n) {
    int l = 0, r = 1000000000;
    while (l < r)
    {
       int m = (l+r)/2;
       if(check(arr,m,n)) r=m;
       else l = m+1;    
    }
    return l;
}
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        int** lr = ma(int*, n);
        f(i,n) {
            lr[i] = ma(int,2);
            scanf("%d %d", &lr[i][0], &lr[i][1]);
        }
       int ans = bs(lr,n);
       printf("%d\n", ans);
       f(i,n) free(lr[i]);
       free(lr);
    }
    return 0;
}