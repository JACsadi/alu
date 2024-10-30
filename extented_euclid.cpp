   #include <bits/stdc++.h>
   #define ll long long
   #define ull unsigned long long
   #define f(i, n) for(int i = 0; i < (n); i++)
   #define sd(i) scanf(" %d", &i)
   #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
   #define en printf("\n")
   #define mod 1000000007
   using namespace std;
    int sieve[500010];
    int pcount;
    void siv(vector<vector<int>>& pfact) {
      sieve[1] = 1;
      for(int i = 2; i<500010;i++) {
        if(sieve[i] ==0) {
          pfact[i].push_back(i);
          for(int j = 2; i*j< 500010;j++) {pfact[i*j].push_back(i); sieve[i*j]=1;}
        }
      } 

    }
    int main() {
      vector<vector<int>> pfact(500010);
      siv(pfact);
     int n,q;
     sd(n);sd(q);
     vector<int> arr(n);
     f(i,n) sd(arr[i]);
    int ele = 0;
    vector<int> ase(n,0);
    map<int,bitset<100000>> primebit;
    map<int,map<int,int>> boroprime;
    ll ans = 0;
    while(q--) {
      int x; sd(x);x--;
      ans += (ll)ele;
      if(ase[x]==0) {
        bitset<100000> onena;
        for(int i = 0; i < pfact[arr[x]].size();i++) {
         if(pfact[arr[x]][i] < 3000) {
           onena |= primebit[pfact[arr[x]][i]]; primebit[pfact[arr[x]][i]].set(x);
           } else {
            
           }
        }
      }
      printf("%lld\n",ans);
    }
     return 0;
   }