   #include <bits/stdc++.h>
   #define ll long long
   #define ull unsigned long long
   #define f(i, n) for(int i = 0; i < (n); i++)
   #define sd(i) scanf(" %d", &i)
   #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
   #define en printf("\n")
   #define mod 1000000007
   using namespace std;
  int main() {
    int l1,r1,l2,r2;
    sd(l1);sd(r1);sd(l2);sd(r2);
    ll ans = (ll)(r1-l1+1)*(ll)(r2-l2+1);
    vector<ll> savegcd( min(r1,r2)+1);
    for(int i =  min(r1,r2); i > 1;i--) {
      int next = l1;
      int first = (((next-1)/i)+1);
      int last = (r1/i);
      int koita1= (last-first+1 < 0 ? 0 : last-first+1 );
      // if(first == 1 && sieve[i]==0 && last >= 1) koita1++;
      next = l2;
       first = (((next-1)/i)+1);
       last = (r2/i);
      int koita2 = (last-first+1 < 0 ? 0 : last-first+1 );
      ll mut = (ll)koita1*(ll)koita2;
      // printf("%d -- %d ",i,mut);
      for(int j = 2; j*i <=min(r1,r2);j++) mut -= savegcd[j*i];
      // if(first == 1 && sieve[i]==0 && last >= 1) koita2++;
      // printf("%d %d\n",koita1*koita2,mob[i]);
      // printf("%d\n",mut);
      savegcd[i] = mut;
      ans -= mut;
      // printf("%lld\n",ans);
    }
    printf("%lld\n",ans);
  }