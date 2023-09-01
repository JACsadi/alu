#include <stdio.h>
#include <stdlib.h>
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
typedef struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
} tree;
tree *end = NULL;
tree* btree(int arr[], int l, int r) {
   int m = (l+r)/2;
   tree* ele = (tree*) malloc(1*sizeof(tree));
   end = ele;
   ele->value = arr[m];
   ele->right = NULL;
   ele->left = NULL;
   if(r > l) {
   ele-> right = btree(arr, m+1, r);
  if(l != m) ele-> left = btree(arr, l, m - 1);
   }
   return ele;
}  
void printss(tree* a) {
    if(a != NULL) { 
    printss(a->left);
    printf("%d\n", a->value);
     printss(a->right);
    }
}
tree* remLast(tree* a) {
    printf("%d\n", a->value);
   tree* temp = (tree*) malloc(1*sizeof(tree));
     temp = a->right;
     a->right = temp->left; 
     temp->left = a;
     while(a->left->left != NULL) a = a->left;
     a->left = a->left->right;
     return temp;
}
void addnew( tree* a, int k) {
   tree* ele = (tree*) malloc(1*sizeof(tree));
   ele->value = k;
   ele->right = NULL;
   ele->left = NULL;
    while(a != NULL) {
    printf("%d \n", a->value);
    if(a->value < k) {
        if(a->right == NULL) {
            a->right = ele;
            break;
        }
        a = a->right;
    }
    else {
        if(a->left == NULL) {
            a->left = ele;
            break;
        }
        a = a->left;
    }}
}
int main () {
    int n;
    scanf("%d", &n);
    int *a = (int*) malloc(n * sizeof(int));
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    sortttt(a, 0, n-1);
    tree* start = btree(a,0,n-1);
    while (1)
    {
        int b;
        scanf("%d", &b);
        if(b == 1) printss(start);
        else if(b == 2) {
            int c;
            scanf("%d", &c);
            addnew(start, c);
        } else if(b == 3) start = remLast(start);
    }
    
}