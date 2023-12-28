#include <bits/stdc++.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
# define ma(k, n) (k*) malloc(n*sizeof(k*));
using namespace  std;
int main() {
    int M;
    scanf("%d", &M);
    f(k,M){
        if (k > 0)  getchar(); 
        int n, m;
        scanf("%d %d", &n, &m);
        char str[m][n + 1];
        f(i,m){
            scanf("%s", str[i]);
        }
        int* unsort = (int*) calloc(m,sizeof(int));
        f(i,m) {
            int* cc = (int*) calloc(4,sizeof(int));
            f(j,n) {
                if(str[i][j] == 'C') str[i][j] = 'B';
                 else if(str[i][j] == 'G') str[i][j] = 'C';
                  else if(str[i][j] == 'T') str[i][j] = 'D';
                cc[str[i][j] -'A']++;
            }
            f(j,n) {
                for(int lk = 'A'; lk < str[i][j]; lk++) {
                    unsort[i] += cc[lk -'A'];
                }
                cc[str[i][j] -'A']--;
                if(str[i][j] == 'B') str[i][j] = 'C';
                else  if(str[i][j] == 'C') str[i][j] = 'G';
                  else if(str[i][j] == 'D') str[i][j] = 'T';
            }
            free(cc);
        }
        priority_queue < pair<int,int>, vector < pair<int,int> >, greater < pair<int,int> > > pq;
        f(i,m) pq.push({unsort[i], i});
        f(i,m) {
            pair<int , int> alu;
            alu = pq.top();
            pq.pop();
            printf("%s\n", str[alu.second]);
        }
      printf("\n");
      free(unsort);
    }
   return 0;
}