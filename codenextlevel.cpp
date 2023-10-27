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
int main() {
  int t;
  scanf("%d", &t);
  while(t--) {
    char str[81];
    scanf(" %s", str);
    int len = strlen(str);
    if(len < 2) continue; 
    for(int i = 1; i < len - 1; i++) {
     if(len % i) continue ;
      bool flag = 1;
      f(j, len-i) {
        if(str[j] != str[j+i]) {
          flag = 0;
          break;
        }
      }
      if(flag) {printf("%d\n\n", i);
          break;
      }
    }
  }
  return 0;
}
