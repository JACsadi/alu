#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define f(i,n) for(int i = 0; i <n; i++)
#define ll  long long 
void merge(int *arr, int l, int m, int r) {
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
void sortttt(int *arr, int l,int r) {
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
     int n;
     scanf("%d", &n);
     int* arr = (int*) malloc(n*sizeof(int));
     f(i,n) scanf("%d", &arr[i]);
     sortttt(arr,0,n-1);
     ll count = 0;
     f(i,n) {
      for(int j = i+1; arr[j] - arr[i] <= 30; j++) {
        if(ceil(log2(arr[j] / arr[i])) == floor(log2(arr[j] / arr[i])) && log2(arr[j] / arr[i]) == (arr[j]-arr[i])) count++;
      }
     }
     printf("%lld\n", count);
     free(arr);
    }
    return 0;
}