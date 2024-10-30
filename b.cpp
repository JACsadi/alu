#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < (n); i++)
#define sd(i) scanf(" %d", &i)
#define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
#define mod 998244353
using namespace std;
// typedef struct node {
//    int val;
//    int tempt;
//    int tempv;
// } node;
// node tree[400050];
// void update(int u, int type,int ind, int l, int r) {
//   if(l <= r) {
//    if(tree[ind].tempt != type) {
//     tree[ind].tempt = type;
//     tree[ind].tempv= 0;
//    }
//    if(l==r) {
//       tree[ind].tempv = 1;
//    } else {
//       int m = (l+r)/2;
//       if(u <= m) update(u,type,(2*ind)+1,l,m);
//       else update(u,type,(2*ind)+2,m+1,r);
//       tree[ind].tempv = (tree[(2*ind)+1].tempt == type ? tree[(2*ind)+1].tempv:0)+(tree[(2*ind)+2].tempt == type ? tree[(2*ind)+2].tempv:0);
//    }
//    tree[ind].val = max(tree[ind].val,tree[ind].tempv/2);
//   }
// }
// int sum(int l, int r, int s, int e, int ind) {
//    if(r < l || s > e) return 0;
//    if(l==s && r==e) return tree[ind].val;
//    else {
//       int m = (s+e)/2;
//       return sum(l,min(r,m),s,m,(2*ind)+1) + sum(max(l,m+1),r,m+1,e,(2*ind)+2);
//    }
// }
int main() {
    int n; sd(n);

   return 0;
}