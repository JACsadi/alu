#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define ll long long
#define f(i, n) for (int i = 0; i < n; i++)
# define ima(k,y, n) k* y = (k*) malloc(n*sizeof(k));
# define ma(k, n) (k*) malloc(n*sizeof(k));
typedef struct node {
    float val;
    struct node* left;
    struct node* right;
    struct node* parent;
} nod;
nod* root = NULL;
void addtree(float val) {
       ima(nod,newnode,1);
        newnode->val = val;
        newnode->left = NULL;
        newnode->right = NULL;
        if(root == NULL) {
            root = newnode;
        } else {
           nod* currentnode = root;
           while (currentnode != NULL)
           {
            if(currentnode->val > val) {
               if(currentnode->left == NULL) {
                currentnode->left = newnode;
                newnode->parent = currentnode;
                break;
               }
               currentnode = currentnode->left;
            } else {
                  if(currentnode->right == NULL) {
                currentnode->right = newnode;
                newnode->parent = currentnode;
                break;
               }
               currentnode = currentnode->right;
            }
           }
           
        }
}
nod* traverse(nod* p, int f) {
   if(f) {
    if(p->left==NULL) return p;
     return traverse(p->left,f);
   } else {
    if(p->right==NULL) return p;
     return traverse(p->right,f);
   }
}
nod* tnext(nod* p) {
    if(p->right != NULL) return traverse(p->right, 1);
    else {
       while(1) 
       {
        if(p->parent == NULL) return p;
       if(p == p->parent->left) return p->parent;
       else p = p->parent;
       }
    }
    return 0;
}
nod* tprev(nod* p) {
     if(p->left != NULL) return traverse(p->left, 0);
      else {
       while(p != NULL) 
       {
       if(p->parent == NULL) return p;
       if(p == p->parent->right) return p->parent;
       else p = p->parent;
       }
    }
     return 0;
}
int main() {
    int n;
    scanf("%d", &n);  
    nod* l; nod* r; float median = 0;
    f(i,n) {
        float a;
        scanf(" %f", &a);
        addtree(a);
        if(!i) {
            l = root;
            r = l;
            median = r->val;
        } else {
           if((i+1)%2) {
             if(a >= r->val) l = r;
             else if(a < l->val) r = l;
             else {
                l = tnext(l);
                r = tprev(r);
             }
           } else {
             if(a >= r->val) r = tnext(r);
             else l = tprev(l);
           }
           median = (l->val+r->val) / 2.0;
        }
        printf("%f\n", median);
    }
    return 0;
}