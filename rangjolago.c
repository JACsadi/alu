#include <stdio.h>
#include <stdlib.h>
typedef struct tree
{
    int value;
    struct tree *left;
    struct tree *right;
} tree;
tree* start = NULL;
void addnewele(int v) {
   tree* ele = (tree*) malloc(1*sizeof(tree));
   ele->value = v;
   ele->right = NULL;
   ele->left = NULL;
    if(start == NULL) start = ele;
    else {
        int r = 0, k = 0; tree* lastturn = start; tree* a = start; tree* last;
        while (a != NULL)
        {
          if(a->value > v) {
            if(r!= 0) {
                r = 0;
                k = 0;
                lastturn = a;
            }
         if( a->right == NULL && a != lastturn) k++;
         else k = 0;
          if(a->left == NULL) {
          if(k >= 2) {
            tree* temp;
            temp = lastturn->left;
            lastturn->left = a;
            a->right = temp;
            a->left = ele;
            last->left = NULL;
          } else {
            a->left = ele;
          } 
          break;
          }
          last = a;
          a = a->left;
           } else {
            if(r!= 1) {
                r = 1;
                k = 0;
                lastturn = a;
            }
         if( a->left == NULL && a != lastturn) k++;
         else
          k = 0;
          if(a->right == NULL) {
          if(k >= 2) {
            tree* temp;
            temp = lastturn->right;
            lastturn->right = a;
            a->left = temp;
            a->right = ele;
            last->right = NULL;
          } else {
            a->right = ele;
          } 
          break;
          }
          last = a;
          a = a->right;
           }  
        }
         
    }
}
int remLast() {
     int k;
     tree*  a = start; tree*  last = start;
     while(a->left != NULL) {
      last = a;
      a = a->left;
     }
     k = a->value;
     if(a == start) start = a->right;
     else last->left = a->right;
     free(a);
     return k;
}
// void printss(tree* a) {
//     if(a != NULL) { 
//     printss(a->left);
//     printf("%d\n", a->value);
//      printss(a->right);
//     }
// }
int main() {
    int t;
    scanf("%d", &t);
    while (t--)
    {
      int n,m,d, j = 0;
      long long max =0 , sum = 0;
      scanf("%d %d %d", &n, &m, &d);
      for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        if(a > 0) {
           addnewele(a);
            sum += a;
            j++;
          if(j > m) {
            sum -= remLast();
            j--;
          }
          max = (max > sum - ((long long)(i+1)*(long long)d)) ? max : sum - ((long long)(i+1)*(long long)d);
        } 
      }
    //   printss(start);
      for(int i = 0; i < j; i++)  sum = remLast();
      printf("%lld\n", max);
    }
    return 0;
}