#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define f(i, n) for(int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k))	;
#define sd(i) scanf("%d", &i)
#define Max(a,b) a < b ? b : a;
#define Min(a,b) a > b ? b : a;
#define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
#define en printf("\n")
int main() {
    tcase {
        int n; sd(n);
        ll lcm = 1;
        f(i,n) {
            ll a;
            scanf("%lld", &a);
            lcm = (a*lcm) / __gcc<long long>(lcm,a);
        }
        printf("%lld\n", lcm*35);

    }
    return 0;
}