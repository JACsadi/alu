#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf("%d", &i)
#define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 1000000007
using namespace std;
typedef struct node {
    int vis;
    int p;
    vector<int> adj;
    vector<ll> cap;
} node;
node graph[519];
ll bfs(int n) {
    queue<int> qu;
    vector<bool> vis(510,0);
    vis[1] =1;
    qu.push(1);
    while(!qu.empty()) {
        int cur = qu.front();
        // printf("cur-- %d\n",cur);
        qu.pop();
        f(i,graph[cur].adj.size()) {
            int nex=graph[cur].adj[i];
            if(vis[nex] == 0 && graph[cur].cap[nex] > 0) { 
            graph[nex].p = cur; vis[nex]= 1;
            if(nex==n) break;
            qu.push(nex);
            }
        }
    }
    if(vis[n] == 0) return 0;
    ll maxflow = LLONG_MAX;
    int cur = n;
    while(cur != 1) {
         maxflow = min(maxflow, graph[graph[cur].p].cap[cur]);
         cur = graph[cur].p;
        //  printf("%d ",cur);
    }
    // printf("max %d\n", maxflow);
    cur = n;
    while(cur != 1) {
         graph[graph[cur].p].cap[cur] -= maxflow;
         graph[cur].cap[graph[cur].p] += maxflow;
         cur = graph[cur].p;
    }
    return maxflow;
}
int main() {
    int n,m;sd(n);sd(m);
    f(i,510+1) {
       graph[i].vis = 0;
       graph[i].p = 0;
       graph[i].cap.resize(510,0);
    }
    f(i,m) {
        int u,v,fl;sd(u);sd(v);sd(fl);
        graph[u].adj.push_back(v);
        graph[v].adj.push_back(u);
        graph[u].cap[v] += (ll)(fl);
        // graph[v].cap[u] = 0;
    }
    ll maxf = 0;
    ll flow = 0; 
    while (flow = bfs(n)) {;maxf += flow;}
    printf("%lld\n",maxf);
    
    return 0;
}