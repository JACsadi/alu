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
#define mod 998244353
using namespace std;
using cd = complex<double>;
const double PI = acos(-1);

void fft(vector<cd>& a, bool invert) {
    int n = a.size();
    for(int i = 1,j=0; i <n;i++) {
        int bit = n >> 1;
        for(;j & bit; bit >>= 1) j^=bit;
        j^=bit;
        if(i < j) swap(a[i],a[j]);
    }
    for(int len = 2; len <= n; len <<= 1) {
        double ang = 2 * PI / len * (invert ? -1 : 1);
        cd wlen(cos(ang), sin(ang));
        for(int i = 0; i < n; i += len) {
            cd w(1);
            for(int j = 0; j < len / 2; j++) {
                cd u = a[i + j], v = a[i + j + len / 2] * w;
                a[i + j] = u + v;
                a[i + j + len / 2] = u - v;
                w *= wlen;
            }
        }
    }
    if(invert) {
        for(cd & x : a) x /= n;
    }
}

vector<ll> multiply(vector<ll> &a, vector<ll> &b) {
    vector<cd> fa(a.begin(), a.end()), fb(b.begin(), b.end());
    int n = 1;
    while(n < a.size() + b.size()) n <<= 1;
    fa.resize(n); fb.resize(n);
    fft(fa, false); fft(fb, false);
    f(i, n) fa[i] *= fb[i];
    fft(fa, true);
    vector<ll> result(n);
    f(i, n) result[i] = round(fa[i].real()) ;
    return result;
}

int main() {
    int n, m;
    sd(n); sd(m);
    vector<ll> arr(n);
    vector<int> count(11, 0);
    vector<vector<vector<ll>>> dp(11, vector<vector<ll>>(2, vector<ll>(m+1, 0)));

    f(i, n) { sd(arr[i]); count[arr[i]]++; }

    f(i, 11) {
        for(int j = 1; j <= count[i]; j++) {
            if(j * i <= m) {
                dp[i][j % 2][j * i] = (count[i] - j + 1) % mod;
            } else {
                break;
            }
        }
    }

    vector<ll> kzur = dp[1][0];
    vector<ll> kodd = dp[1][1];

    for(int i = 2; i <= 10; i++) {
        kzur.resize(m + 1);
        kodd.resize(m + 1);
       
        vector<ll> tempzur1 = multiply(dp[i][0], kzur);
        tempzur1.resize(m + 1);
        f(j,m) printf("%d ", tempzur1[j]);
        en;
        vector<ll> tempzur2 = multiply(dp[i][1], kodd);
        tempzur2.resize(m + 1);
        f(j,m) printf("%d ", tempzur2[j]);
        en;
        vector<ll> tempzur(m + 1);
        for(int j = 0; j <= m; j++) {
            tempzur[j] = (tempzur1[j] + tempzur2[j] + kzur[j] + dp[i][0][j]) % mod;
        }

        vector<ll> tempodd1 = multiply(dp[i][0], kodd);
        vector<ll> tempodd2 = multiply(dp[i][1], kzur);
        tempodd1.resize(m + 1);
        tempodd2.resize(m + 1);

        vector<ll> tempodd(m + 1);
        for(int j = 0; j <= m; j++) {
            tempodd[j] = (tempodd1[j] + tempodd2[j] + kodd[j] + dp[i][1][j]) % mod;
        }

        kzur = tempzur;
        kodd = tempodd;
    }

    printf("%lld\n", kodd[m]);
}
