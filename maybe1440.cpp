#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k));
#define sd(i) scanf("%d", &i)
int check(int* arr , int n) {
  int flag = 0;
  if(n == 1) return 1;
  else if(n == 2) abs(arr[0] - arr[1]) <= 2 ? 1 : 0; 
  int* temp = (int*) malloc(((n/2)+1)*sizeof(int));
  int tempflag = 1;
  for(int i = 1; i <n; i+= 2) {
      if((i == n-1 ? arr[i] : arr[i+1]) > 1){
        tempflag = 0;
        break;
      }
      temp[(i+1)/2] = (arr[i] + (i == n-1 ? arr[i] : arr[i+1])) / 2;
  }
  if(tempflag) {
    temp[0] = arr[0];
    flag = check(temp,((n/2)+1));
    if(!flag &&  arr[0] > 0) {
     temp[0] = arr[0]-1;
    flag = check(temp,((n/2)+1));
    } if(n%2 == 0 && !flag && temp[(n/2)] > 0) {
       temp[(n/2)] = arr[n-1]-1;
      temp[0] = arr[0];
      flag = check(temp,((n/2)+1));
     }
     if(n%2 == 0 && !flag && temp[(n/2)] > 0) {
      temp[(n/2)] = arr[n-1]-1;
      temp[0] = arr[0]-1;
      flag = check(temp,((n/2)+1));
     }
  }

  free(temp);
  tempflag = 1;
  if(!flag) {
  int* temp = (int*) malloc(((n+1)/2)*sizeof(int));
  for(int i = 0; i <n; i+= 2) {
      if(abs(arr[i]-(i == n-1 ? arr[i] : arr[i+1])) > 1){
        tempflag = 0;
        break;
      }
      temp[(i+1)/2] = (arr[i] + (i == n-1 ? arr[i] : arr[i+1])) / 2;
  }
  if(tempflag) {
    flag = check(temp,((n+1)/2));
    if(!flag &&  arr[n-1] > 0 && n%2) {
     temp[n/2] = arr[n-1] -1;
    flag = check(temp,((n+1)/2));
    } 
  }
  }
   return flag;
} 
int main() {
  int t;
  sd(t);
  while (t--)
  {
    int n;
    sd(n);
    ima(arr,int,n);
    f(i,n) {
        scanf("%d", &arr[i]);
    }
    int flag = check(arr,n);
    if(flag) printf("YES\n");
    else printf("NO\n");
    }

  return 0;
}