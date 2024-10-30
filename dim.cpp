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
using namespace std;

int main() {
    tcase {
        int n, k;
        sd(n);sd(k);
        vector<int> arr(n);
        map<int, vector<int>> my;
        
        f(i, n) {
            cin >> arr[i];
            my[arr[i] % k].push_back(arr[i]);
        }
        
        int odd = 0;
        for_each(my.begin(), my.end(), [](pair<const int, vector<int>>& pair) {
            sort(pair.second.begin(), pair.second.end());
        });
        
        for (const auto& pair : my) {
            int z = pair.second.size();
            if (z % 2) odd++;
        }
        
        if (odd > (n % 2)) {
            cout << "-1\n";
            continue;
        }
        
        long long ans = 0;
        for (const auto& pair : my) {
            int z = pair.second.size();
            if (z % 2 == 0) {
                for (int i = 0; i < z / 2; i++) {
                    ans += (long long)((pair.second[i * 2 + 1] - pair.second[i * 2]) / k);
                }
            } else {
                 ima(dp,ll,z+1);
                for (int i = z-2; i >=0;i--) {
                   dp[i] = dp[i+2] + (long long)((pair.second[i+1] - pair.second[i]) / k) ;
                  if(i < z-2) dp[i] = min(dp[i], dp[i+3] + (long long)((pair.second[i+1] - pair.second[i]) / k) + (ll)pair.second[i+2]);
                } 
                ans+= min(dp[0],dp[1]);
            }
        }
        
        cout << ans << "\n";
    }
    return 0;
}
