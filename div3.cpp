#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define f(i,n) for(int i = 0; i <n; i++)
#define ll  long long 
int main() {
    int t;
    scanf("%d", &t);
    for(int k = 1; k <=t;k++) {
     ll n;
     scanf("%lld", &n);
     ll* arr = (ll*) malloc(n*sizeof(ll));
     f(i,n) scanf("%lld", &arr[i]);
     ll ans = n * (n+1) / 2;
     ans -= n;
     int* hashh = (int*) calloc(n+1, sizeof(int));
     int match = 1;
     for(int i = 1; i < n; i++) {
        if(arr[i] == arr[i-1]) {
             match++;
             hashh[match]++;
        }
        else {
            match = 1;
        }
     }
      ans -= hashh[n];
     for(int i = n-1; i >= 2; i--) {
       hashh[i] += hashh[i+1];
       ans -= hashh[i];
     }
     printf("Case %d: %lld\n",k, ans);
    }
    return 0;
}