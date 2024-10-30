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
   int ind;
   vector<int> adj;
   vector<int> ulta;
  } node;
  node tree[300010];
  vector<vector<int>> scc(300010);
  vector<vector<vector<ll>>> sgtree(300010);
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
    tree[u].vis = scount;
    tree[u].ind = scc[scount].size();
    scc[scount].push_back(u); 
    f(i,tree[u].ulta.size()) {
        int next = tree[u].ulta[i];
        if(tree[next].vis==0) dfs2(next);
    }
  }
  void build(vector<vector<ll>>& sg, int l, int r, int ind, int sc,vector<int>& arr) {
    if(l==r) {
      sg[ind][0] = (ll)arr[scc[sc][l]-1];
      sg[ind][1] = 1;
    } else {
      int m = (l+r)/2;
      build(sg,l,m,(ind*2)+1,sc,arr);
      build(sg,m+1,r,(ind*2)+2,sc,arr);
      if(sg[(ind*2)+1][0] == sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = sg[(ind*2)+1][1]+sg[(ind*2)+2][1];
      } else if(sg[(ind*2)+1][0] > sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = sg[(ind*2)+1][1];
      } else {
        sg[ind][0] = sg[(ind*2)+2][0];
        sg[ind][1] = sg[(ind*2)+2][1];
      }
    }
  }
   void update(vector<vector<ll>>& sg, int l, int r, int ind,int tar,int x) {
    // printf("l--%d r--%d\n",l,r);
     if(l==r) {
       sg[ind][0] += (ll)x;
     } else {
      int m = (l+r)/2;
     if(tar <= m) update(sg,l,m,(ind*2)+1,tar,x);
      else update(sg,m+1,r,(ind*2)+2,tar,x);
      if(sg[(ind*2)+1][0] == sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = sg[(ind*2)+1][1]+sg[(ind*2)+2][1];
      } else if(sg[(ind*2)+1][0] > sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = sg[(ind*2)+1][1];
      } else {
        sg[ind][0] = sg[(ind*2)+2][0];
        sg[ind][1] = sg[(ind*2)+2][1];
      }
     }
   }
    void build2(vector<vector<ll>>& sg, int l, int r, int ind) {
    if(l==r) {
      sg[ind][0] = sgtree[l+1][0][0];
      sg[ind][1] = sgtree[l+1][0][1];
    } else {
      int m = (l+r)/2;
      build2(sg,l,m,(ind*2)+1);
      build2(sg,m+1,r,(ind*2)+2);
      if(sg[(ind*2)+1][0] == sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = max(sg[(ind*2)+1][1],sg[(ind*2)+2][1]);
      } else if(sg[(ind*2)+1][0] > sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = sg[(ind*2)+1][1];
      } else {
        sg[ind][0] = sg[(ind*2)+2][0];
        sg[ind][1] = sg[(ind*2)+2][1];
      }
    }
  }
   void update2(vector<vector<ll>>& sg, int l, int r, int ind, int tar,ll x,ll y) {
     if(l==r) {
       sg[ind][0] = (ll)x;
       sg[ind][1] = (ll)y;
     } else {
      int m = (l+r)/2;
     if(tar <= m) update2(sg,l,m,(ind*2)+1,tar,x,y);
      else update2(sg,m+1,r,(ind*2)+2,tar,x,y);
      if(sg[(ind*2)+1][0] == sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = max(sg[(ind*2)+1][1],sg[(ind*2)+2][1]);
      } else if(sg[(ind*2)+1][0] > sg[(ind*2)+2][0]) {
        sg[ind][0] = sg[(ind*2)+1][0];
        sg[ind][1] = sg[(ind*2)+1][1];
      } else {
        sg[ind][0] = sg[(ind*2)+2][0];
        sg[ind][1] = sg[(ind*2)+2][1];
      }
     }
   }
  int main() {
   int n,m,q; 
   sd(n);sd(m);sd(q);
   vector<int> arr(n);
   
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
   f(i,n)  sd(arr[i]); 
   for(int i = 1 ; i <= n;i++) if(tree[i].vis==0){ dfs(i);}
   f(i,n+5) tree[i].vis = 0;
   while (!st.empty()) {
    int u = st.top();
    // printf("%d\n",u);
    st.pop();
    if(tree[u].vis==0) {
        scount++;
        dfs2(u);
        // f(j,scc[scount].size()) printf("%d ",scc[scount][j]);
        // en;
        sgtree[scount].resize(4*scc[scount].size());
        f(k,4*scc[scount].size())  sgtree[scount][k].resize(2,-90000000000000000);
        build(sgtree[scount],0,scc[scount].size()-1,0,scount,arr);
        // printf("%lld %lld\n\n\n",sgtree[scount][0][0],sgtree[scount][0][1]);
    }   
   };
   vector<ll> lazy(scount+1,0);
   vector<vector<ll>> sgtr(4*scount,vector<ll>(2,-90000000000000000));
   build2(sgtr,0,scount-1,0);
   while(q--) {
    char str[5];
    scanf(" %s",str);
    if(str[0] == 'Q') {
        if(sgtr[0][0] < 0) printf("0\n");
        else printf("%lld %lld\n",sgtr[0][0],sgtr[0][1]);
    }
    else if(str[1] == 'C') {
      int x,y;sd(x);sd(y);
      int s = tree[y].vis;
      lazy[s] += (ll)x;
      update2(sgtr,0,scount-1,0,s-1,sgtree[s][0][0]+lazy[s],sgtree[s][0][1]);
      //  printf("%d -- %lld %lld\n",s,sgtree[s][0][0]+lazy[s],sgtree[s][0][1]);
    } else {
      int x,y;sd(x);sd(y);
      int s = tree[y].vis;
    //   printf("s--%d ind-%d \n",s,tree[y].ind);
      update(sgtree[s],0,scc[s].size()-1,0,tree[y].ind,x);
      update2(sgtr,0,scount-1,0,s-1,sgtree[s][0][0]+lazy[s],sgtree[s][0][1]);
    //   printf("%d -- %lld %lld\n",s,sgtree[s][0][0]+lazy[tree[y].vis],sgtree[scount][0][1]);
    }
   }
   
 } 
