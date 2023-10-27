#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
 void merge(int arr[], int l, int m, int r) {
    if(l != r) {
        int L[m - l + 1], R[r - m];
        for(int i = l; i <= m; i++) L[i-l] = arr[i];
        for(int i = m + 1; i <= r; i++) R[i - m - 1] = arr[i];
        int i = 0 , j = 0;
        while(i + j < r - l + 1) {
            if(j == r - m) {
                 arr[l+i+j] = L[i];
                 i++;
            } else if(i == m - l + 1) {
                 arr[l+i+j] = R[j];
                 j++;
            } else if(L[i] < R[j]){
                arr[l+i+j] = L[i];
                 i++;
            } else {
                 arr[l+i+j] = R[j];
                 j++;
            }
        } 
    }
}
void sortttt(int arr[], int l,int r) {
    int mid = (l+r)/2;
    if(r > l) {
        sortttt(arr, l ,mid);
        sortttt(arr, mid + 1, r);
    }
    merge(arr,l,mid,r);
}
int main() {
       int t;
       scanf("%d", &t);
       while(t--) {
        int s, la, a,b;
        scanf("%d %d %d %d", &s,&la,&a,&b);
        int* arr = (int*) malloc(s * sizeof(int));
        f(i,s) scanf("%d", &arr[i]);
        sortttt(arr,0,s-1);
        int l = a, r = b - (s*la) +1, mid;
        ll ans;
        while(l <= r) {
            mid = (l+r) / 2;
            ll m = 0, ml = 0, mr = 0;
            f(i,s) m += abs( mid + (i*la) - arr[i]);
            f(i,s) mr += abs( mid+1 + (i*la) - arr[i]);
            f(i,s) ml += abs(mid - 1 + (i*la) - arr[i]);
            if(mr <= m) {
                l = mid + 1;
                ans = m;
            } else if(ml <= m) {
                r = mid - 1;
                ans = m;
            } else {
                ans = m;
                break;
            }
        }
        printf("%lld\n", ans) ;
       }
    return 0;
}
