#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define f(i, n) for (int i = 0; i < n; i++)
 void merge(int** arr, int l, int m, int r) {
    if(l != r) {
        int L[m - l + 1], R[r - m];
        for(int i = l; i <= m; i++) L[i-l] = arr[i][1];
        for(int i = m + 1; i <= r; i++) R[i - m - 1] = arr[i][1];
        int i = 0 , j = 0;
        while(i + j < r - l + 1) {
            if(j == r - m) {
                 arr[l+i+j][1] = L[i];
                 i++;
            } else if(i == m - l + 1) {
                 arr[l+i+j][1] = R[j];
                 j++;
            } else if(L[i] < R[j]){
                arr[l+i+j][1] = L[i];
                 i++;
            } else {
                 arr[l+i+j][1] = R[j];
                 j++;
            }
        } 
    }
}
void sortttt(int** arr, int l,int r) {
    int mid = (l+r)/2;
    if(r > l) {
        sortttt(arr, l ,mid);
        sortttt(arr, mid + 1, r);
    }
    merge(arr,l,mid,r);
}
int bs(int **arr, int target, int n, int bl) {
    int l = 0, r = n, m, ans;
    while(l <= r) {
         m = (l+r) / 2 ;
         if(arr[m][1] == target && arr[m][0] == 0) {
          if(arr[m-1][1] == target && arr[m-1][0] == 1) r = m - 1;
          else  l = m+1;
        }
        else if(arr[m][1] > target) r = m - 1;
        else if(arr[m][1] < target) l = m + 1;
        else {
          if(bl) r = m - 1;
          else l = m+1;
          ans = m ;
        }
    }
    // printf("%dhh\n", ans);
    arr[ans][0] = 0;
    return ans;
}
int main() {
       int n, k;
       scanf("%d %d", &n, &k);
       int *unsort = (int*) malloc(n*sizeof(int));
       int **sort = (int**) malloc((n+1)*sizeof(int*));
       f(i,n) {
         scanf("%d", &unsort[i]);
         sort[i] = (int*) calloc(2,sizeof(int));
         sort[i][0] = 1;
         sort[i][1] = unsort[i];
       }
       sortttt(sort, 0, n-1);
    int l = 0, r = n-1, index = ((n+1) / 2) -1, h = sort[index][1];  
      for(int i = n - 1; i >= k; i--) {
          int z, kkk;
           if(unsort[l] <= unsort[r]) {
              z = unsort[l];
              l++;
              kkk = bs(sort, z, n-1, 1);
           } else {
            z = unsort[r];
            r--;
            kkk = bs(sort, z, n-1, 0);
           }  
        //   printf("%d %d\n", kkk, index);
          if(i & 1) {
              if(kkk > index) continue;
              else {
                do index++;
                while (!sort[index][0]);
                h = h > sort[index][1] ? h : sort[index][1];
              }
          } else {
             if(kkk < index) continue;
              else {
                do index--;
                while (!sort[index][0]);
                h = h > sort[index][1] ? h : sort[index][1];
              }
          }
      }
      printf("%d\n", h);
    return 0;
}
