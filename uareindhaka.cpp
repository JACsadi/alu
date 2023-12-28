    #include <stdio.h>
    #include <stdarg.h>
    #include <string.h>
    #include <stdlib.h>
    #include <math.h>
    #define ll  long long
    #define f(i, n) for (int i = 0; i < n; i++)

    int main() {
        int t;
        scanf("%d", &t);
        while(t--) {
            int n,k,d;
            scanf("%d %d %d", &n,&k,&d);
            ll* arr = (ll*) calloc(n, sizeof(ll));
            int* v  = (int*) calloc(k, sizeof(int));
            ll ans = 0;
            int c = 0;
            f(i,n) {
                ll a;
                scanf("%lld", &a);
                if(a == i+1) c++;
                arr[i] = a - (i+1);
            }
            f(i,k) scanf("%d", &v[i]);
            int sincestep = 0;
            int laststep = 0;
            for(int step = 1; step <= (2*n)+1 && step <= d-1; step++) {
            int otherwoman = 0;
            sincestep++;
            f(i, v[(step-1) % k]) arr[i]++;
            f(i,n) if(!arr[i]) otherwoman++;
            if(otherwoman > c+((sincestep-1)/2)) {
                c = otherwoman;
                sincestep = 0;
                laststep = step;
            } 
            }
            ans = c + ((d-laststep-1)/2);
            printf("%lld\n", ans);
        }
        return 0;
    }