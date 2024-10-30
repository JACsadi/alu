#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main(void) {
    int n;
    char c;
    scanf("%d", &n);
    getchar(); 
    getchar();
    while (n--) {
        char str[100];
        int j = 0;
        int k = 10;
        while(k--) {
        char temp[2];
        fgets(temp, sizeof(temp), stdin);
        if(strlen(temp) < 1) break;
        else {
            str[j] = temp[0];
            j++;
        }
    }
      printf("%s\n", str);
    }

    return 0;
}