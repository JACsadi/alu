#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>
#include <stdbool.h>
#include <malloc.h>
#define ll  long long
#define f(i,n) for(int i = 0; i < n; i++)
int siv[100001] = {0};
void sieve() {
    int i = 2;
   while(i < 100001) {
    if(siv[i]) {
        i++;
        continue;
    } 
    int k = 2;
    while(i*k < 100000) {
        siv[i*k] = 1;
        k++;
    }
    i++;
  }
}
int main() {
  int n;
  scanf("%d", &n);
  n += 1;
  sieve();
  int k = 2;
  int c = 1; 
  if(n > 3) c++;
  printf("%d\n", c);
  for(int i = 2; i <= n;i++) {
   if(c == 1) printf("1 ");
   if(!siv[i]) { 
    printf("2 ");
   } else {
   printf("1 ");
   }
  }
  return 0;
}
