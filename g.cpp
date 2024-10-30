   #include <bits/stdc++.h>
   #define ll long long
   #define ull unsigned long long
   #define f(i, n) for(int i = 0; i < (n); i++)
   #define sd(i) scanf(" %d", &i)
   #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
   #define en printf("\n")
   #define mod 1000000007
   using namespace std;
   const int MAX = 500010;
   int mobius[MAX+5]; 
   int pcount[MAX+5];
   void mymobius() {
     mobius[1] = 1;
    for(int i = 2; i <= 500010; i++) {
      if(pcount[i]==0) {
        mobius[i] =-1;
        for(int j = 2; j*i <= 500010; j++) {
          if(j%i == 0) {
            pcount[i*j] = -1;
          } else if(pcount[i*j] != -1) pcount[i*j]++;
        }
      } else if(pcount[i] == -1) mobius[i] = 0;
      else mobius[i] = ((pcount[i]%2 == 0) ? 1 : -1);
    }
   }

   int main() {
     int n,q;
     sd(n);sd(q);
     vector<int> arr(n);
     vector<vector<int>> divi(n);
     f(i,n) {
        sd(arr[i]);
        for(int j = 1; j *j <= arr[i]; j++) {
        if(arr[i]%j ==0) {
         divi[i].push_back(j);
         if(j*j != arr[i]) divi[i].push_back(arr[i]/j);
        }
      }
    }
    mymobius();
    // f(i,100) printf("%d -- %d\n",i+1,mobius[i+1]);
    int ele = 0;
    vector<int> ase(n,0);
    map<int,int> ei_divisor_aro_ase;
    ll ans = 0;
    while(q--) {
      int x; sd(x);x--;
      // ans = 0;
      if(ase[x]==0) {
        ase[x] =1;
       for(int i = 0 ; i < divi[x].size();i++) {
        // printf("%d ", divi[x][i]);
        ans += (ll)mobius[divi[x][i]] * (ll)(ei_divisor_aro_ase[divi[x][i]]);
        ei_divisor_aro_ase[divi[x][i]]++;
       } 
      } else if(ase[x] == 1) {
        ase[x] =0;
       for(int i = 0 ; i < divi[x].size();i++) {
        // printf("%d ", divi[arr[x]][i]);
        ei_divisor_aro_ase[divi[x][i]]--;
        ans -= (ll)mobius[divi[x][i]] * (ll)(ei_divisor_aro_ase[divi[x][i]]);
       } 
      }
      printf("%lld\n",ans);
     
    }
     return 0;
    }