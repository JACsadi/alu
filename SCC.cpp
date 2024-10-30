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
  #define mod 998244353
  using namespace std;
  typedef struct node {
   int vis;
   vector<int> adj;
   vector<int> ulta;
  } node;
  node tree[300010];
  vector<vector<int>> scc(300010);
  stack<int> st;
  int scount = 0;
  void dfs(int u) {
    tree[u].vis = 1;
    f(i,tree[u].adj.size()) {
        int next = tree[u].adj[i];
        if(tree[next].vis==0) dfs(next);
    }
    st.push(u);
  }
  void dfs2(int u) {
    // printf("%d %d\n",u,scount);
    tree[u].vis = 1;
    scc[scount-1].push_back(u); 
    f(i,tree[u].ulta.size()) {
        int next = tree[u].ulta[i];
        if(tree[next].vis==0) dfs2(next);
    }
  }
  int main() {
   int n; 
   sd(n);
   vector<int> arr(n);
   f(i,n)  sd(arr[i]); 
   int m; sd(m);
   f(i,n+5) {
    tree[i].vis = 0;
    tree[i].adj.clear();
    tree[i].ulta.clear();
   }
   f(i,m) {
    int u,v;sd(u);sd(v);
    tree[u].adj.push_back(v);
    tree[v].ulta.push_back(u);
   }
   for(int i = 1 ; i <= n;i++) if(tree[i].vis==0){ dfs(i);}
   f(i,n+5) tree[i].vis = 0;
   while (!st.empty()) {
    int u = st.top();
    // printf("%d\n",u);
    st.pop();
    if(tree[u].vis==0) {
        scount++;
        dfs2(u);
        f(j,scc[scount-1].size()) printf("%d ",scc[scount-1][j]);
        en;
    }
   };
   
 } 
