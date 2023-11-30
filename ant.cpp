#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <malloc.h>
#include <stdbool.h>
#define ll  long long
#define f(i,n) for(int i = 0; i < n; i++)
int main() {
   int t;
   scanf("%d", &t);
   while(t--) {
      int n,k;
      scanf("%d %d", &n, &k);
      int* arr = (int*) calloc(2*n,sizeof(int));
      int j = 0, zz = 0;
      int ooo = n;
      while(k > 0) {
       if(ooo == 1) {
         zz++;
         ooo = arr[zz];
         continue;
       }
       arr[j] = ooo/2;
       arr[j+1] = (ooo/2) + (ooo%2);
       j += 2;
       k -= 2;q
       int f = 0;
       if(arr[j-2] % 2 && k > 0) {
         arr[j] = 1;
         k--;
         f++;
       }
       if(arr[j-1] % 2 && k> 0) {
         arr[j+f] = 1;
         k--;
       }
       j += f;
       arr[zz] = 0;
       zz++;
       ooo = arr[zz];
      }
      f(i, 2*n) 
         if(arr[i]) printf("%d ", arr[i]);
   }
   return 0;
}