#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;
vector<int> bulidkmp(char str[]) {
   int siz = strlen(str);
   vector<int> kmp(siz,0);
   int i = 1, j=0;
   while(i < siz) {
      if(str[i] == str[j]) {
        kmp[i] = j+1;
        i++;
        j++;
      } else {
          if(j==0) i++;
          else {
            j = kmp[j-1];
          }
      }
   }
   return kmp;
}
int main() {
    char str[10010],btr[10010];
    scanf("%s %s",str,btr);
    int n = strlen(str);
    int m = strlen(btr);
    vector<int> lps = bulidkmp(btr);
    f(i, lps.size()) printf("%d ", lps[i]);
    int i = 0,j=0;
     while(i < n) {
        printf("i -- %d j -- %d\n",i,j);
      if(str[i] == btr[j]) {
        i++;
        j++;
      } else {
          if(j==0) i++;
          else {
            printf("%d %d\n",i,j);
            j = lps[j-1];
          }
      }
      if(j==m) {
        break;
      }
   }
     printf("%d %d\n",i-m, j);
    return j != m ? -1 : i-m;
}