
void merge(int arr[], int l, int m, int r) {
    if(l != r) {
        int L[m - l + 1], R[r - m];
        for(int i = l; i <= m; i++) L[i-l] = arr[i];
        for(int i = m + 1; i <= r; i++) R[i - m - 1] = arr[i];
        int i = 0 , j = 0;
        while(i + j < r - l + 1) {
            if(j == r - m) {
                 arr[l+i+j] = L[i];
                 i++;
            } else if(i == m - l + 1) {
                 arr[l+i+j] = R[j];
                 j++;
            } else if(L[i] < R[j]){
                arr[l+i+j] = L[i];
                 i++;
            } else {
                 arr[l+i+j] = R[j];
                 j++;
            }
        } 
    }
}
void sortttt(int arr[], int l,int r) {
    int mid = (l+r)/2;
    if(r > l) {
        sortttt(arr, l ,mid);
        sortttt(arr, mid + 1, r);
    }
    merge(arr,l,mid,r);
}
int bs(int arr[], int r, int value) {
     int m= (l+r)/2;
     while(l <= r) {
     if(arr[m] < value) {
          return m;
     } else {
      r = m -1;      
     }
}
 return 1e8 +1;
}
#define f(i,n) for(int i = 0; i <n; i++)
int main() {
     int t;
     scanf("%d", &t);
     while (t--)
     {
          int n, m;
          scanf("%d %d", &n, &m);
          int *arr = (int*) malloc(n * sizeof(int));
          f(i,n) scanf("%d", &arr[i]);
          sortttt(arr, 0, n-1);
          f(i,m) {
          int a,b,c;
          scanf("%d %d %d", &a, &b, &c);
          if(c <= 0 ) {
               printf("NO\n");
               continue;
          }
          int k1 = ceil((float)b+(float)sqrt(4*a*c));
          int k2 = ceil((float)b-(float)sqrt(4*a*c));
           k1 = bs(arr, n-1, k1);
           k2 = bs(arr, n-1, k2);
           if(k1 > 1e8 && k2 > 1e8) {
                 printf("NO\n");
               continue;
           } else {
             printf("YES");
             printf("%d\n", k1 < k2 ? k1 : k2);
           }
          }
     }
     
}