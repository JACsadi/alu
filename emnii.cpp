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
  #define mod 1000000007
  using namespace std;
  ll dp[5011][5011][4];
  bool vis[5011][5011][4];
  ll rangedp0(int l,int r) {
      if(l > r) return 0;
      if(vis[l][r][0] != 0){ return dp[l][r][0];}
      vis[l][r][0] = 1;
      if(l==r) return dp[l][r][0] = ((dp[l][l][2] > 0) ? (ll)dp[l][l][2] : 0);  
      ll one = ((dp[l][l][2] > 0 )? (ll)dp[l][l][2] : 0); 
      ll two = ((((ll)dp[l][l][2]*(ll)dp[l+1][l+1][2]) > 0) ?( (ll)dp[l][l][2]*(ll)dp[l+1][l+1][2]) : 0);  
        for(int j = r; j >= l; j--) {
           vis[l][j][0] = 1;
           dp[l][j][0] = max(dp[l][j][0],one+rangedp0(l+1,j));
          if(j > l) dp[l][j][0] = max(dp[l][j][0],two+rangedp0(l+2,j));
         }
        return dp[l][r][0];
    }
  ll rangedp1(int l,int r) {
      if(l > r) return 0;
      if(vis[l][r][2] != 0){ return dp[l][r][2];}
      vis[l][r][2] = 1;
      if(l==r) return dp[l][r][2] = (ll)dp[l][l][2];  
      ll one = (ll)dp[l][l][2]; 
      ll two = (ll)dp[l][l][2]*(ll)dp[l+1][l+1][2];  
        for(int j = r; j >= l; j--) {
           vis[l][j][2] = 1;
           dp[l][j][2] = one+rangedp1(l+1,j);
          if(j > l) dp[l][j][2] = max(dp[l][j][2],two+rangedp1(l+2,j));
         }
        return dp[l][r][2];
    }
     
  ll rangedp(int l,int r, int p) {
   if(l > r) return 0;
   if(vis[l][r][1+p] != 0){ return dp[l][r][1+p];}
   vis[l][r][1+p] = 1;
   if(l==r) return dp[l][r][1+p] = dp[l][l][p];  
   ll one = dp[l][l][p]; 
   ll two = dp[l][l+1][p];   
    for(int j = r; j >= l; j--) {
      vis[l][j][1+p] = 1;
      dp[l][j][1+p] = max(dp[l][j][p],one+rangedp(l+1,j,p));
      if(j > l){
        ll sp =( (((ll)dp[l][l][2]*(ll)dp[j][j][2]) > 0) || (p==2 )? (ll)dp[l][l][2]*(ll)dp[j][j][2] : 0);  
        dp[l][j][1+p] = max(dp[l][j][1+p],two+rangedp(l+2,j,p));
        dp[l][j][1+p] = max(dp[l][j][1+p],sp+rangedp(l+1,j-1,2));
       }
      // if(l == 2) printf("%d - %lld %lld %lld %lld\n",p,j,dp[l][j][1+p],((j < r) ? dp[j+1][r][p] : 0),dp[l][r][p]);
      dp[l][r][1+p] = max(dp[l][r][p],max(dp[l][r][1+p],dp[l][j][1+p] + ((j < r) ? dp[j+1][r][p] : 0)));
      }
      return dp[l][r][1+p];
    }
  int main() {
    int n; sd(n);
    // vector<int> arr(n);
    f(i,n) scanf("%lld",&dp[i+1][i+1][2]);
     ll k = rangedp1(1,n);
     k = rangedp0(1,n);
   
    k = rangedp(1,n,0);
    printf("%lld\n",dp[1][n][1]);
    return 0;
  }