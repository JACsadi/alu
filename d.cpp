   #include <bits/stdc++.h>
   #define ll long long
   #define ull unsigned long long
   #define f(i, n) for(int i = 0; i < (n); i++)
   #define sd(i) scanf(" %d", &i)
   #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
   #define en printf("\n")
   #define mod 1000000007
   using namespace std;
   stack<pair<int,int>> st;
   int parent[200000];
   int sizee[200000];
   int findp(int u) {
      if(parent[u] == u) return u;
      else return parent[u] = findp(parent[u]);
   }
   void uni(int u,int v) {
     int pu = findp(u);
     int pv =findp(v);
   //   printf("%d %d %d %d\n",u,v,pu,pv);
      if(sizee[pu] < sizee[pv]) swap(pu,pv);
      parent[pv] = pu;
      sizee[pu] += sizee[pv]; 
   }
   int main() {
     tcase{
      int n; sd(n);
      f(i,n+1) parent[i] = i;
      f(i,n+1) sizee[i] = 1;
      vector<int> arr(n,0);
      map<int,vector<int>> mymap;
      f(i,n) {sd(arr[i]); mymap[arr[i]].push_back(i);}
      int last = 0;
    //   for(int i = 1; i<=n;i++) {
    //      if(parent[i]==i) {
    //         if(last==0) last = i;
    //         else {
    //            printf("%d %d %d %d\n",st.top().first,st.top().second,last,i);
    //            last = i;
    //            st.pop();
    //         }
    //      }
    //   }
         ll ans = 0;
         for(auto& p: mymap) {
            int u = p.first;
            int lastvis = -1;
            for(auto& ind :p.second) {
               if(ind != 0 && arr[ind-1] <= arr[ind]) {
                if(lastvis != ind-1) {
                    uni(ind+1,ind);
                    ans += (ll)(sizee[ind+1]-1);
                } else {
                    uni(ind+1,ind);
                }
               } 
               lastvis = ind;
               if(ind != n-1 && arr[ind+1] < arr[ind]) {
                int agersize = sizee[ind+1];
                  uni(ind+1,ind+2);
                  ans += (ll)(sizee[ind+1]-agersize);
                  lastvis += sizee[ind+1]-agersize;
               }
           
            }

         }
         printf("%lld\n",ans);
     }
      return 0;
   }