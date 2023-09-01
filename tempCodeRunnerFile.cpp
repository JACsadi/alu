#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>

#define ll long long
int main() {
    int t;
    scanf("%d", &t);
    while(t--) {
        ll a,b;
        scanf("*%lld %lld %lld *%lld", &a, &b);
        printf("%lld %lld %lld\n", a, b, b);
    }
    return 0;
} 