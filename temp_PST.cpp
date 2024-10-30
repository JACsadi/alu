#include <bits/stdc++.h>
#include <vector>
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
 int n,q,k;
 typedef struct node {
   int val;
   struct node* left;
   struct node* right;
 } node;
 node* root[100010];
 node* update(node* prev, int l, int r, int tar) {
   node* neww = (node*) calloc(1,sizeof(node));
   if(prev == NULL) {
      neww->val = 1;
      neww->left = NULL;
      neww->right = NULL;
   } else {
      neww->val = prev->val +1;
      neww->left = prev->left;
      neww->right = prev->right;
   }
   if(l != r) {
      int m = (l+r)/2;
      if(m >= tar) neww->left = update(neww->left,l,m,tar);
      else neww->right = update(neww->right,m+1,r,tar);
   }
   // printf("l-%d r-%d v-%d\n",l,r,neww->val);
   return neww;
 }
 int query(node* root, int l, int r,int s,int e) {
   if(s > e || root == NULL) return 0;
   if(l == s && r == e) return root->val;
   else {
      int m = (l+r)/2;
      return query(root->left,l,m,s,min(m,e)) + query(root->right,m+1,r,max(s,m+1),e);
   }
 }

int main() {
    
    sd(n);sd(k);
    ima(arr,int,n);
    ima(brr,int,n);
    vector<vector<int>> mirror(100010);
    vector<vector<int>> vec(100010);
    f(i,n) {
      sd(arr[i]);
      vec[arr[i]].push_back(i+1);
      if(vec[arr[i]].size() <= k) brr[i] = 0;
      else brr[i] = vec[arr[i]][vec[arr[i]].size() - k - 1]; 
      mirror[brr[i]].push_back(i);
    }
    root[0] = NULL;
    for(int l = 1; l <= n; l++) {
      // printf("l -- %d\n", l);
      root[l] = root[l-1];
      for(int i = 0; i < mirror[l-1].size(); i++) root[l] = update(root[l],0,n-1,mirror[l-1][i]);
    }
     sd(q);
     int last = 0;
     while(q--) {
        int x,y;sd(x);sd(y);
        int l = ((x + last) % n) + 1;
        int r = ((y + last) % n) + 1;
        if(l > r) {r = l+r; l = r - l; r -= l; }
        last = query(root[l],0,n-1,l-1,r-1);
        printf("%d\n", last);
     }
    
    return 0;
}