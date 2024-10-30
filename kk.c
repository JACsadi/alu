#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define ull unsigned long long
#define f(i, n) for (int i = 0; i < n; i++)
#define ma(k, n) (k*) malloc(n*sizeof(k));
#define ima(y, k, n) k* y = (k*) malloc(n*sizeof(k));
#define sd(i) scanf("%d", &i)
typedef struct node {
    int val;
    struct node* left;
    struct node* right;
    int count;
} node;
node* add(int val, node* root) {
  ima(newnode,node,1);
  newnode->val = val;
  newnode->left = NULL;
  newnode->right = NULL;
  newnode->count = 1;
  if(root == NULL) root = newnode;
  else {
    node* currentnode = root;
    while(1) {
         if(currentnode->val == val) {
            currentnode->count++; free(newnode);break;
            }
         else if(currentnode->val < val) {
            if(currentnode->right != NULL)currentnode = currentnode->right;
            else {

                currentnode->right = newnode;
                break;
            }
        } else {
         if(currentnode->left != NULL)currentnode = currentnode->left;
            else {
                currentnode->left = newnode;
                break;
            }   
        }
    }
  }
  return root;
}
int printt(node* root, int i, node** sortarr) {
    if(root->left != NULL) i = printt(root->left, i,sortarr);
    // printf("%d %d\n", i, root->val);
    sortarr[i] = root;
    i++;
     if(root->right != NULL) i = printt(root->right, i,sortarr);
     return i;
}
int findd(int val, node** arr, int k) {
    int l = 0, r = k-1, f = 0;
    while(l <= r) {
     int m = (l+r)/2;
     if(arr[m]->val == val) {
        if(arr[m]->count == 1) f = 1;
        arr[m]->count--;
        break;
     } else if(arr[m]->val > val) r = m-1;
     else l = m+1;
    }
    return f;
}
int main() {
    int t;
    sd(t);
    while(t--) {
     node* root = NULL;
     int n;
     sd(n);
     ll ans = 0;
     ima(arr,int,n);
     f(i,n) {
       sd(arr[i]);
       root = add(arr[i], root);
     }
     ima(sortarr,node*,n);
     int* cow = (int*) calloc(n+1,sizeof(int));
     int k = printt(root,0, sortarr);
     f(i,n) {
        cow[i+1] = cow[i];
        if(findd(arr[i], sortarr,k)) cow[i+1]++;
        ans += cow[i+1];
     }
     printf("%lld\n", ans);
    }
    return 0;
}