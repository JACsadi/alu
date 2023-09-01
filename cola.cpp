  #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #define ll  long long
  #define f(i,n) for(ll i = 0; i <n; i++)
  void merge(ll arr[][2], ll left, ll middle, ll right) {
    ll n1 = middle - left + 1;
    ll n2 = right - middle;

    ll L[n1][2], R[n2][2];

    for (ll i = 0; i < n1; i++)
        f(o,2) L[i][o] = arr[left + i][o];
    for (ll j = 0; j < n2; j++)
        f(o,2) R[j][o] = arr[middle + 1 + j][o];

    ll i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (L[i][1] >= R[j][1]) {
           f(o,2) arr[k][o] = L[i][o];
            i++;
        } else {
           f(o,2)  arr[k][o] = R[j][o];
            j++;
        }
        k++;
    }

    while (i < n1) {
        f(o,2) arr[k][o] = L[i][o];
        i++;
        k++;
    }

    while (j < n2) {
        f(o,2) arr[k][o] = R[j][o];
        j++;
        k++;
    }
}

void mergeSort(ll arr[][2], ll left, ll right) {
    if (left < right) {
        ll middle = left + (right - left) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}
  int main() {
        int t;
        scanf("%d", &t);
        while (t--)
        {
          ll n,m,d,  sum = 0, max = 0;
          scanf("%lld %lld %lld", &n, &m, &d);
         long long (*a)[2] = (long long (*)[2])malloc(n * sizeof(long long[2]));
          f(i, n) {
            ll ele;
            scanf("%lld", &ele);
              a[i][0] = i;
              a[i][1] = ele - (i+1)*d;
            } 
            mergeSort(a, 0 , n-1);
          f(i,m) {
          if(a[i][1] + (i+1)*d > 0)  {
            sum += a[i][1]  + (i+1)*d;
            max = max > a[i][0] ? max : a[i][0];
          }
          }
          printf("%lld\n", sum - (max+1)*d);
        }
        return 0;
      };