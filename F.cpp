#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define ma(k, n) (k*) malloc((n)*sizeof(k));
#define ima(y, k, n) k* y = (k*) calloc((n),sizeof(k));
#define sd(i) scanf(" %d", &i)
#define Max(a,b) ((a) < (b) ? (b) : (a))
#define Min(a,b) ((a) > (b) ? (b) : (a))
#define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
using namespace std;
 map<int,vector<int>> number;
 int sv[1000010];
 
 void sieve() {
    sv[1] = 1;
    int i = 2;
    while(i*i <= 1000000) {
      if(!sv[i]) {
        for(int j = 1; j*i <= 1000000; j++) {
          sv[j*i] = 1;
          number[j*i].push_back(i);
          // factors[i][j*i] = 1;
        }
      }
      i++;
    } 
 }
  int n ,k;
  int vis[2000010];
  int alu;
  map<int,map<int,int>> factors;
  map<int,int> already;
void traverse(int u,int* arr,int k) {
    vis[u] = k;
    for(auto x : number[arr[u%n]]) {
         factors[x].erase(u);
    }
    for(auto x : number[arr[u%n]]) {
        
         while(!factors[x].empty()) {
          map<int, int>::iterator it = factors[x].begin();
          if(abs(it->first -u) <=  k){
             if(it->first < n)
             traverse(it->first,arr,k); 
             else {
              if(already[vis[it->first%n]] == 0) {
                alu++;
                already[vis[it->first%n]] = 1;
              }
               for(auto x : number[arr[it->first%n]]) {
               factors[x].erase(u);
         }
             }
             }
          else break;
         
         }
         
    }

}
int main() {
  sieve();
 tcase {
    alu = 0;
    sd(n);sd(k);
    ima(arr,int,n);
    ll one = 0;
    int count = 0;
    f(i,n)  {vis[n-1-i] = 0;sd(arr[n-1-i]);if(arr[n-1-i] == 1) one++;}
    
    for(int i = n - 1; i >= 0; i--) {
       for(auto x : number[arr[i]]) {
         factors[x][i] = 1;
         if(i!=n-1) factors[x][i+n] = 1;
       }
    }
    int z = 1;
    for(int i = 0; i < n; i++) {
       if(i == n-1)  count = count*2;
       if(!vis[i]) {
        count++;
        traverse(i,arr,z);
        z++;
       }
    }
    printf("%lld\n", (ll)count + (ll)(one*(ll)(n-1)));
    factors.clear();
    already.clear();
 }
 
}
