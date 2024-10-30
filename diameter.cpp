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
     vector<int> adj;
     int subtree;
     int vis;
     int holds;
     int dia;
     int val;
  } node;
  node tree[200005];
  int s,t,d;
  void dfs(int u , int p) {
      int temps=u,tempt=u;
      if(u != 1 &&  tree[u].adj.size()==1) tree[u].holds = u;
   for(int i = 0; i < tree[u].adj.size(); i++) {
      if(tree[u].adj[i] != p) {
      dfs(tree[u].adj[i],u);
      if(tree[temps].subtree <= tree[tree[u].adj[i]].subtree) {
      temps = tree[u].adj[i];
      if(tree[temps].subtree >= tree[tempt].subtree) swap(temps , tempt);
      }
    }
   }
   for(int i = 0; i < tree[u].adj.size(); i++) {
      if(tree[u].adj[i] != p) {
         if(tree[tree[u].adj[i]].subtree > tree[u].subtree)  { 
            tree[u].subtree = tree[tree[u].adj[i]].subtree; 
            tree[u].holds = tree[tree[u].adj[i]].holds;
         };
      }
   }
       tree[u].subtree += 1;
     if(u!= temps && u != tempt) {
       tree[u].dia = 1 + tree[temps].subtree+tree[tempt].subtree;
       if(tree[u].dia > d) {
         d = tree[u].dia;
         s = tree[temps].holds;
         t = tree[tempt].holds;
       } 
     } else {
       tree[u].dia = tree[u].subtree;
        if(tree[u].dia > d) {
         d = tree[u].dia;
         s = u;
         t = tree[tempt].holds;
       } 
       } 
  }
  void dfs2(int u, int p) {
      if(u==t) tree[u].holds = t;
      for(int i = 0; i < tree[u].adj.size(); i++) {
      if(tree[u].adj[i] != p) {
      dfs2(tree[u].adj[i],u);
       if(tree[tree[u].adj[i]].holds == t) {tree[u].holds = t; }    
      }
    }
   }
   int val = 1;
   void dfs3(int u, int p) {
      tree[u].val = val;
      int hd=0;
   for(int i = 0; i < tree[u].adj.size(); i++) {
      int nec = tree[u].adj[i];
      if(nec != p && tree[nec].holds !=t) {
         ++val;
         dfs3(nec,u);
         ++val;  
      } else if(nec != p && tree[nec].holds == t) hd = nec;
    }
    if( hd != 0) val++;
    if(hd != 0) dfs3(hd,u);
   }
  
  int main() {
   sd(n);
   f(i,n+1) {
      tree[i].vis = 0;
   }
   f(i,n-1) {
    int u,v;
    sd(u);sd(v);
    tree[u].adj.push_back(v);
    tree[v].adj.push_back(u);
   }
   dfs(1,0);
   f(i,n+1) tree[i].holds = 0;
   dfs2(s,0);
   dfs3(s,0);
   // printf("%d %d %d\n",s,t,d);
   f(i,n) printf("%d ", tree[i+1].val);
   }

  