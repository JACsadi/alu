#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
 void merge(int* arr, int l, int m, int r) {
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
void sortttt(int* arr, int l,int r) {
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
        int n,m;
        scanf("%d %d", &n,&m);
        int* a =(int*) malloc(n*sizeof(int));
        int* b =(int*) malloc(n*sizeof(int));
        f(i,n-1) scanf("%d", &a[i]);
        f(i,n) scanf("%d", &b[i]);
        a[n-1] = 1;
        sortttt(a,0,n-1);
        sortttt(b,0,n-1);
        int* temp =(int*) malloc(n*sizeof(int));
        f(i,n)  temp[i] = a[n-i-1];
        f(i,n) a[i] = temp[i];
        int k = 0;
        int count = 0;
        int flag = 1;
        for(int i = n- 1; i >= 0; i--) {
            for(int j = k; j <= n; j++) {
                if(j == n) flag =0;
                else if(b[i] > a[j]) {
                    count++;
                    k = j+1;
                    break;
                }
            }
            if(!flag) break;
        }
        printf("%d\n", n-count);
    }
return 0;    
}
