#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
 
#define endl '\n'
#define all(x) x.begin(), x.end()
#define make_unique(v) sort(v.begin(), v.end()), v.erase(unique(v.begin(), v.end()), v.end())
#define fastIO cin.tie(0)->sync_with_stdio(0)
 
// #include <ext/pb_ds/assoc_container.hpp>
// using namespace __gnu_pbds;
 
// template <typename T>
// using order_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
// order_of_key() *find_by_order()
 
const int maxn = (int)2e5 + 9;
int all;
 
void solve(int test){
  int n;
  cin >> n;
  ll a[n + 1];
  set<ll> st;
  for(int i = 1; i <= n; ++i){
    cin >> a[i];
    st.insert(a[i]);
  }
  map<ll, ll> mp;
  int c = 1;
  for(auto k : st){
    mp[k] = c++;
  }
  for(int i = 1; i <= n; ++i){
    a[i] = mp[a[i]];
  }
  int l[n + 5] = {};
  int r[n + 5] = {};
  int lhs[n + 5];
  int rhs[n + 5];
  for(int i = 1; i <= n; ++i){
    l[a[i]] = max(l[a[i]], l[a[i] - 1] + 1);
    lhs[i] = l[a[i]];
  }
  for(int i = n; i >= 1; --i){
    r[a[i]] = max(r[a[i]], r[a[i] - 1] + 1);
    rhs[i] = r[a[i]];
  }
  int ans = 0;
  for(int i = 1; i <= n; ++i){
    if(min(lhs[i], rhs[i]) * 2 >= 4){
        ans = max(ans, min(lhs[i], rhs[i]) * 2);
    }
  }
  cout << "Case " << test << ": " <<  ans - 1 ;
  if(test != all) cout << endl;

}

int main(){
    fastIO;
    int tt = 1;
    cin >> tt;
    all = tt;
    int test = 1;
    while(tt--){
       solve(test++);
    }
}