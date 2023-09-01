#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int bs(char names[][100], int n, char name[100]) {
    int l = 0;
    int r = n-1;
    while (l <= r)
    {
        int mid = (l+r) /2;
        int k = strcmp(names[mid], name);
        if(!k) return 1;
        else if (k < 0) l = mid + 1;
        else r = mid -1;
    }
    return 0;
};
int main() {
    char some[6][100];
    for(int i =0; i < 6; i++) scanf("%s", some[i]);
    while(1) {
    char target[100];
    scanf("%s", target);
    printf("%d\n", bs(some, 6, target));
    }
    return 0;
}