#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (ll i = 0; i < n; i++)
int  ph[1000001];
void totient()
{  
	for( int i=0; i<=1000000; i++) ph[i] = i;
	for( int j=2; j<=1000000; j++) {
		if (ph[j] == j)
		{
		  ph[j] = j - 1;
			for ( int i = 2*j; i<=1000000; i += j)
			{
			ph[i] = (ph[i]/j) * (j-1);
			}
		}
	}
}

int main() {
   int t;
   scanf("%d", &t);
   totient();
   while(t--) {
   ll n;
   scanf("%lld", &n);
   ll sum = ((n*(n-1)) - (ph[n]*n)) /2;
   printf("%lld\n", sum);
   }
  return 0;
}