#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll  long long
#define f(i,n) for(ll i = 0; i < n; i++)
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
        int n,occ = 1, min = 2000000, pc = 0, uni = 0;
        scanf("%d", &n);
        int *a = (int*) malloc(n*sizeof(int));
        int *b = (int*) calloc (n , sizeof(n));
        f(i,n)  scanf("%d", &a[i]);
        sortttt(a, 0 , n-1);
        f(i,n) {
        if(i != 0 && (a[i] == a[i-1] || i == n -1)) {
            uni++;
            b[occ]++;
            occ = 1;
            continue;
        } else if(i != 0) occ++;
        }
        f(i,n) {
            if(!b[i]) continue;
            uni -= b[i];
            min = min < (n - (b[i]*i) - (uni*i));
        }
        printf("%d\n", min);
    }
}