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
  int n,m;
  typedef struct node {
     int val;
     vector<int> adj;
     vector<int> p;
     vector<int> ele;
     vector<vector<int>> pth;
     int childv;
     int dep;
  } node;
  node tree[100005];
  void dfs(int u , int p) {
      tree[u].p[0] = p;
      tree[u].dep = tree[p].dep + 1;
      for(int i = 1; i <= (int)log2(n) +1; i++) {
        if(tree[u].p[i-1] == 0) break;
        tree[u].p[i] = tree[tree[u].p[i-1]].p[i-1];
      }
     for(int i = 0; i < tree[u].adj.size(); i++)  if(tree[u].adj[i] != p) dfs(tree[u].adj[i],u);
  }
  int lca(int u, int v) {
     if(tree[v].dep < tree[u].dep) swap(v,u);
     for(int i = (int)log2(n) + 1; i >= 0; i--) {
      if(tree[v].p[i] && (tree[tree[v].p[i]].dep >= tree[u].dep)) {
         v = tree[v].p[i];
      }
     }
     if(v==u){
       return v;
     }
     for(int i = (int)log2(n) + 1; i >= 0; i--) {
      if(tree[v].p[i] != tree[u].p[i]) {
         v = tree[v].p[i]; u = tree[u].p[i];
       }
     }
    
     return tree[v].p[0];
  }
  int main() {
   sd(n);sd(m);
   f(i,n+1) {
    tree[i].p.resize((int)log2(n) + 5,0);
    tree[i].adj.clear();
    tree[i].ele.clear();
    tree[i].pth.resize((int)log2(n) + 5);
    tree[i].dep = 0;
    tree[i].val = 0;
    tree[i].childv = (1<<31)-1;
   }
   f(i,n-1) {
    int v;
    sd(v);
    tree[i+1].adj.push_back(v);
   }
   //   priority_queue
     f(i,m) {
      int a;sd(a);
     tree[n-m+i].val = a; 
     }
   dfs(1,0);

}
  