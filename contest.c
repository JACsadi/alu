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
bool pancheck(int l, int r, char arr[]) {
if(l == r) return true;
  int mid = (l+r)/2 + (l+r) %2;
  bool flag = true;
  for(int z = 0; z < mid - l ; z++) {
    if(arr[l+z] != arr[r-z]) {
      flag = false;
      break;
    }
  }
  return flag;
}
bool finddd(char*** arr, char brr[], int l , int r) {
    char *temp = (char *)malloc((r-l + 2) * sizeof(char));
  strncpy(temp, brr + l, r-l+1);
  temp[r-l+1] = '\0';
  bool flag = false;
  int z = 0;
  while (arr[r-l][z] != NULL)
  {
    if(strcmp(temp, arr[r-l][z]) == 0) {
      flag = true;
      break;
    }
    z++;
  }
  if(!flag) {
    arr[r-l] = (char**) realloc(arr[r-l], (z+2)*sizeof(char*));
    arr[r-l][z] = (char*)malloc((r-l+2) * sizeof(char));
    arr[r-l][z+1] = NULL;
    strncpy(arr[r-l][z], temp, r-l+1);
    arr[r-l][z][r-l+1] = '\0';
  }
  free(temp);
  return flag;
}
int main() {
    char str[81];
   while(scanf(" %s", str) != EOF) {
    int k = strlen(str);
    char*** a = (char***) malloc((k+1)*sizeof(char**));
    f(i,k+1) {
      a[i] = (char**) malloc(1*sizeof(char*));
      a[i][0] = NULL;
      }
    int sum = 0;
    f(i,k) {
      f(j,(k-i)) {
          if(pancheck(i,j+i,str)) {
          if(!finddd(a, str , i, j+i))  
          sum++;
          }
      }
    } 
     printf("The string '%s' contains %d palindromes.\n", str, sum);
     free(a);
    }
    return 0;
}