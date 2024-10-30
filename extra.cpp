    #include <bits/stdc++.h>
    #define ll long long
    #define ull unsigned long long
    #define f(i, n) for(int i = 0; i < (n); i++)
    #define sd(i) scanf(" %d",&i);
    #define tcase int t; sd(t); for(int casee = 1; casee <= t; casee++)
    #define en printf("\n")
    #define mod1 1000000007LL
    #define mod2 998244353
    #define mod3 7983413291LL
    using namespace std;
    int main() {
        tcase {
            int n; sd(n);
            vector<ll> arr(n);
            int fixedmoves = 0;
            int unfixed = 0;
            f(i,n) {
                scanf("%lld ", &arr[i]);
            }
               unordered_map<ll,int> fixed;
        fixed[1] = 1;
        fixed[2] = 2;
        fixed[3] = 3;
        fixed[5] = 4;
        ll lastodd = 3ll; ll nextodd = 5ll;
        
        
        while(lastodd < (ll)1000000000000000000) {
        ll tempodd = (lastodd*2ll)+1ll;
        fixed[tempodd] = (fixed[nextodd]+1);
        lastodd = nextodd;
        nextodd = tempodd;
        printf("%lld %d\n",nextodd,fixed[nextodd]);
        }
                // printf("%llu ",arr[i]);
            f(i,n) {   
             if(fixed[arr[i]] < 1) unfixed++;
                else {
                    fixedmoves += (fixed[arr[i]] - 1)%2;
                    // printf("%d \n",fixedmoves);
                }  
            }
        
            if(unfixed == 0) {
            if((fixedmoves % 2) == 1) printf("YES\n");
            else printf("NO\n");
            } else {
            if(unfixed % 2 == 1) printf("YES\n");
            else printf("NO\n");
            }

        }
    return 0;
    } 
