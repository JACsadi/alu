   #include <bits/stdc++.h>
      #define ll long long
      #define ull unsigned long long
      #define f(i, n) for(int i = 0; i < n; i++)
      #define ma(k, n) (k*) malloc(n*sizeof(k));
      #define ima(y, k, n) k* y = (k*) calloc((n),sizeof(k));
      #define sd(i) scanf("%d", &i)
      #define Max(a,b) ((a) < (b) ? (b) : (a))
      #define Min(a,b) ((a) > (b) ? (b) : (a))
      #define tcase int t;sd(t);for(int casee = 1; casee <= t; casee++)
      #define en printf("\n")
      #define inf -10000000
      using namespace std;
      void build(int** tree, int* init, int l, int r, int ind) {
         tree[ind][1] = 1;
         // tree[ind][2] = 1;
        if(l == r) {
            //  printf("%d %d\n",l,ind);
            tree[ind][0] = init[l];
            // if(tree[ind][0] < 0) tree[ind][2] = -1;
        } else if(l < r) {
           int m = (l+r)/2;
           build(tree,init,l,m,(2*ind)+1);
           build(tree,init,m+1,r,(2*ind)+2);
           tree[ind][0] = tree[(2*ind)+1][0]+tree[(2*ind)+2][0];
         //   if(tree[(2*ind)+1][2] < 0 || tree[ind][0] < 0 ) tree[ind][2] = -1;
        }
      }
       void buildorefix(int** tree, int* init, int l, int r, int ind) {
        if(l == r) {
            
            tree[ind][2] = (init[l] == 1 ? 0 : 1);
              tree[ind][3] = !tree[ind][2];
            // printf("%d %d\n", l, tree[ind][3]);
        } else if(l < r) {
           int m = (l+r)/2;
            buildorefix(tree,init,l,m,(2*ind)+1);
            buildorefix(tree,init,m+1,r,(2*ind)+2);
           tree[ind][2] = tree[(2*ind)+1][2] > (tree[(2*ind)+2][2] + (tree[(2*ind)+1][0]*-1)) ? tree[(2*ind)+1][2] :  (tree[(2*ind)+2][2] + (tree[(2*ind)+1][0]*-1));
            tree[ind][3] = tree[(2*ind)+1][3] > (tree[(2*ind)+2][3] + (tree[(2*ind)+1][0])) ? tree[(2*ind)+1][3] :  (tree[(2*ind)+2][3] + (tree[(2*ind)+1][0]));
         //   printf("%d %d --- %d\n", l,r, tree[ind][3]);
        }
      }
       
      int sum(int** tree,int asols, int s, int e, int l, int r, int ind,int val) {
           if(s>e) return 0;
           val = tree[ind][1]*val;
           if((s == l) && (e == r)) {
             return tree[ind][0]*val;
           }
           int m = (l+r)/2;
           return  sum(tree,asols,s, Min(e,m),l,m,(2*ind)+1,val) + sum(tree,asols,max(s,m+1),e,m+1,r,(2*ind)+2,val);;
           
      }
       int sumpre(int** tree,int asols, int s, int e, int l, int r, int ind,int val) {
         // printf("%d %d\n", s,e,val);
          val = tree[ind][1]*val;
           if(s>e) return 0;
           if((s == l) && (e == r)) {

             if(val > 0) return tree[ind][2];
             return tree[ind][3];
           }
           int m = (l+r)/2;
           int a = sumpre(tree,asols,s, Min(e,m),l,m,(2*ind)+1,val);
           int b = sumpre(tree,asols,max(s,m+1),e,m+1,r,(2*ind)+2,val);
           int c = sum(tree,asols,s, Min(e,m),l,m,(2*ind)+1,val) *-1;
           return   (a > (c+b)) ? a : c+b ;
           
      }
       void update(int** tree, int s, int e, int l, int r, int ind) {
          if(s<=e){ 
           if((s == l) && (e == r)) {
            tree[ind][1] *= -1;
            // tree[ind][2] *= -1;
           }
        //    if(s > e) return 0;
        else {
           int m = (l+r)/2;
           update(tree,s, Min(e,m),l,m,(2*ind)+1);
           update(tree,max(s,m+1),e,m+1,r,(2*ind)+2);
           tree[ind][0] = (tree[(2*ind)+1][0]*tree[(2*ind)+1][1])+(tree[(2*ind)+2][0]*tree[(2*ind)+2][1]);
           int a1,a2;
           if(tree[(2*ind)+1][1] == 1) {a1 = tree[(2*ind)+1][2];a2=tree[(2*ind)+1][3];}
           else{
             a1 = tree[(2*ind)+1][3];
             a2 = tree[(2*ind)+1][2];
             }
           int b1,b2;
            if(tree[(2*ind)+2][1] == 1) {b1 = tree[(2*ind)+2][2];b2=tree[(2*ind)+2][3];}
           else {b1 = tree[(2*ind)+2][3];b2=tree[(2*ind)+2][2];}
           tree[ind][2] = (a1 > (b1 +(tree[(2*ind)+1][0]*tree[(2*ind)+1][1]*-1))) ? a1 :(b1 +(tree[(2*ind)+1][0]*tree[(2*ind)+1][1]*-1));
           tree[ind][3] = (a2 > (b2 +(tree[(2*ind)+1][0]*tree[(2*ind)+1][1]))) ? a2 :(b2 +(tree[(2*ind)+1][0]*tree[(2*ind)+1][1]));
            // if(tree[(2*ind)+1][2] == 0 || tree[ind][0] < 0 ) tree[ind][2] = 0;
        }
          }
      }
      int main() {
        int n,q;
        sd(n);sd(q);
        char str[n+1];
        scanf("%s", str);
        ima(init,int,n);
        f(i,n) {
            if(str[i] == '(') init[i] =1;
            else init[i] = -1;
        }
       
         ima(tree,int*,(4*n));
         f(i,4*n) tree[i] = (int*) calloc(4,sizeof(int));
            build(tree,init,0,n-1,0);
            buildorefix(tree,init,0,n-1,0);
        //   f(i,n) printf("%d", init[i]);
      
         f(i,q) {
         int v,l,r;
         sd(v);sd(l);sd(r);
         if(v==2) {
         //  printf("%d\n",sumpre(tree,l-1,l-1,r-1,0,n-1,0,1));
          if(sum(tree,l-1,l-1,r-1,0,n-1,0,1) == 0 && sumpre(tree,l-1,l-1,r-1,0,n-1,0,1) <= 0) {
            printf("YES\n");
            }
          else printf("NO\n");
         } else {
            update(tree,l-1,r-1,0,n-1,0);
         }
         }
      }