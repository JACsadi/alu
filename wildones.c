    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <math.h>
    #define ll unsigned long long
    #define f(i, n) for (int i = 0; i < n; i++)
    ll multiple(ll b, ll p, ll m) {
        ll ans = 0;
        while (p > 0) {
            if (p % 2 == 1) {
                ans = (ans + b) % m;
            }
            b = (b * 2) % m;
            p /= 2;
        }
        return ans % m;
    }
ll power(ll b, ll p, ll m) {
    ll ans = 1;
    while (p > 0) {
        if (p % 2 == 1) {
            ans = multiple(ans, b, m);
        }
        b = multiple(b, b, m);
        p /= 2;
    }
    return ans;
}

    int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
        ll x,m,n;
        scanf("%llu %llu %llu", &x, &m, &n);
        ll ans =  ((power(x, m + 1, n) - 1) * power(x - 1, n - 2, n)) % n;
        printf("%llu\n", ans);
        }
        return 0;
    }
