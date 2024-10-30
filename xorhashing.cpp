#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;
ll custom(ll x) {
     x += 0x933779b97f4a7c15;
    x = (x^(x>>30))* 0x336179bc7f4a7c15;
    x = (x^(x>>27))* 0x2300119bc111f432;
    return x;
}
ll random(ll x) {
    ll rando = chrono::steady_clock::now().time_since_epoch().count();
    return (rando+custom(x));
}
void mixtrie(bitset<150>& bits, ll x) {
   ll hash = 1;
   ll val = 0;
   for(int i = 0; i < 63; i++) {
    if(x&(1ll<<i)) {
     if(bits[i+64]) {
      bits[i+64] = false;
     } else if(bits[i]) {
      bits[i] = false;
      bits[i+64] = true;
     } else {
      bits[i] = true;
     }
    }
   }
}
int main() {
        int n;sd(n);
        vector<int> arr(n,0);
        f(i,n) sd(arr[i]);
        map<int,ll> mymap;
        map<ll,int> maap;
        for(int i = 1; i <= 500010;i++){ mymap[i] = ((random((ll)i) )); while(maap[mymap[i]] > 0)  mymap[i] = (random((ll)i) ); maap[mymap[i]]++; }
        // for(int i = 100; i < 150; i++) printf("%lld\n",mymap[i]);
        bitset<150> ini; 
        unordered_map<bitset<150>,int> count;
        map<int,vector<int>> oc;
        vector<bitset<150>> pre(n);
        count[ini] = 1;
        int l = -1;
        ll ans = 0;
        for(int i = 0; i < n; i++) {
          oc[arr[i]].push_back(i);
          if(oc[arr[i]].size() > 3) {
            if(l==-1) {count[0]--;l=0;}
            for(int j = l; j < oc[arr[i]][oc[arr[i]].size() -4]; j++) count[pre[j]]--;
            l = max(l,oc[arr[i]][oc[arr[i]].size() -4]);
          }
           mixtrie(ini, mymap[arr[i]]);
          // printf("%lld %d\n",k,count[k]);
          pre[i] = ini;
          if(oc[arr[i]].size() >= 3)   ans += (ll)count[ini];
          count[ini]++;
        } 
        printf("%lld\n",ans);
        return 0;
    } 