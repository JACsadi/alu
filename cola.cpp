#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
int comp(const void *a, const void *b) {
    return *(const int*)a - *(const int*)b; 
}
int find_mddian(int count, ...) {
    int total = 0;
    va_list args;
    va_start(args, count);
    int arr[count];
    for (int i = 0; i < count; i++) {
        arr[i] = va_arg(args, int);
    }
    qsort(arr, count, sizeof(int), comp);
    if(!(count & 1)) printf("%.2lf", ((float)(arr[count/2])+(float)arr[(count/2)-1]) / 2.0);
    printf("%d", arr[count/2]);
    return 0;
}
int main() {
   find_mddian(8, 1,4,2,3,4,5,7,2);
   return 0;
}