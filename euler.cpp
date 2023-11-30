#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
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
  while (t--)
  {
  int n,m;
  scanf("%d %d", &n, &m);
  int* a = (int*) malloc(n*sizeof(int));
  int* b = (int*) malloc(m*sizeof(int));
  f(i,n) scanf(" %d", &a[i]);
  f(i,m) scanf(" %d", &b[i]);
  int** count = (int**) malloc((n+1)*sizeof(int*));
  f(i, n+1) count[i] = (int*) calloc(1,sizeof(int));
  int seq = 1;
  int j = 0;
  for(int i = 1; i < n; i++) {
   if(a[i] > a[i-1]) seq++;
   if(a[i] <= a[i-1] || i == n-1) {
    if(seq > 1) {
      count[seq][0]++;
      count[seq] = (int*) realloc(count[seq], ((count[seq][0]*2)+1)*sizeof(int));
      count[seq][(count[seq][0]*2)-1] = j;
      count[seq][(count[seq][0]*2)] = i;
    }
    seq = 1;
    j = i;
   }
  }
  f(i,n) printf("%d %d\n", i, count[i][0]);
  sortttt(b,0,m-1);
  f(i,m) printf("%d ", b[i]);
  }
  return 0;
}