 #include <stdio.h>
  #include <stdarg.h>
  #include <string.h>
  #include <stdlib.h>
  #include <math.h>
  #include <stdbool.h>
  #include <iostream> 
  #include <stack>
  #include <queue>
  #define ll long long
  #define f(i, n) for (int i = 0; i < n; i++)
  #define ma(k, n) (k*) malloc(n*sizeof(k))
  #define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))
  #define sd(i) scanf("%d", &i)
  #define Max(a,b) ((a) < (b) ? (b) : (a))
  #define Min(a,b) ((a) > (b) ? (b) : (a))
  #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
  #define M (1000000007)
  #define inf (10000000000000000)
  using namespace std;
  int n,m;
    typedef struct  node
    {
       int edge;
       int* adj;
       int* w;
       ll dis;
       bool vis;
       ll pod;
       int low;
       int high;
    } node;
    node g[100001];
    void init() {
        f(i,n+1) {
            g[i].edge = 0;
            g[i].dis = inf;
            g[i].vis = 0;
        }
    }
    void takeinp() {
    f(i,m) {
        int u,v,w;
        sd(u);sd(v);sd(w);
        g[u].edge++;
        g[u].adj = (int*) realloc(g[u].adj, sizeof(int)*g[u].edge);
        g[u].adj[g[u].edge-1] = v;
        g[u].w = (int*) realloc(g[u].w, sizeof(int)*g[u].edge);
        g[u].w[g[u].edge-1] = w;
    }
    }
   
  void ds() {
    priority_queue<pair<ll,int>,vector<pair<ll,int>>,greater<pair<ll,int>>> pq;
    pq.push({(ll)0,1});
    // g[1].vis = 1;
    g[1].dis = 0;
    g[1].pod = 1;
    g[1].low = 0;
    g[1].high = 0;
    while(!pq.empty()) {
        pair<ll,int> top = pq.top();
        pq.pop();
        int i = top.second;
        ll val = top.first;
        if(g[i].vis) continue;
        f(j,g[i].edge) {
              int nextnod = g[i].adj[j];
              ll nextval = (ll)g[i].w[j] + (ll)g[i].dis;
              if(g[nextnod].dis > nextval) {
                g[nextnod].dis = nextval;
                pq.push({nextval,nextnod});
                // g[nextnod].pod = 0;
                // g[nextnod].low = 1000000;
                // g[nextnod].high = 0;
                g[nextnod].pod = g[i].pod%M;
                g[nextnod].low = g[i].low + 1 ;
                g[nextnod].high = g[i].high + 1 ;
                } else if(g[nextnod].dis == nextval) {
                g[nextnod].pod = (g[nextnod].pod+g[i].pod)%M;
                if(g[i].low + 1 < g[nextnod].low) g[nextnod].low = g[i].low + 1 ;
                if(g[i].high + 1 > g[nextnod].high)g[nextnod].high = g[i].high + 1 ;
                }
        }
        g[i].vis = 1;
    }
  }
  
 int main() {
    sd(n);sd(m);
    init();
    takeinp();
    ds();
    printf("%lld %lld %d %d", g[n].dis, g[n].pod,g[n].low, g[n].high);

 }