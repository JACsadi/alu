  #include <stdio.h>

  #include <stdarg.h>

  #include <string.h>

  #include <stdlib.h>

  #include <math.h>
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
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
        int n;
        scanf("%d", &n);
        int *a = (int*) malloc(n* sizeof(int));
        f(i,n) scanf("%d", &a[i]);
     sortttt(a, 0, n-1);
     int l = 0, mid , ans, r = a[n-1]; 
     while(l <= r) {
      int* b = (int*) malloc(3*sizeof(int));
      f(i,3) b[i] = 0;
      mid = (l+r)/2;
      int flag  = 1;
      f(i,n) {
        f(j,3) {
         if(b[j] == 0) {
          b[j] = a[i] + mid;
           break;
         } 
         if(abs(b[j] - a[i]) <= mid) {
          break;
         } else if(j == 2) {
          flag = 0;
          break;
         } 
        }
      if(!flag) break;
      }
      if(flag) {
        ans = mid;
        r = mid - 1;
      } else l = mid + 1;
      free(b);
     }
     printf("%d\n", ans);
     free(a);
  }
  return 0;
  }