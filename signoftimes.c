#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void reverse(char* a) {
   static int len = k;
    len--;
    if(len) reverse(a);
    len++;
    printf("%c", a[len-1]);
}
int main() {
 char something[100];
 scanf("%[^\n]", something);
 reverse(something);
 int k = strlen(something);
 return 0;
}