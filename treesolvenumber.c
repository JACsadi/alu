#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <malloc.h>
#include <math.h>
#define f(i,n) for(int i = 0; i <n; i++)
#define ll  long long 
int main() {
    int n,m;
    scanf("%d %d", &n, &m);
    int* check = (int*) calloc(m,sizeof(int));
int* tree = (int*) calloc(m,sizeof(int));
 tree[0]=n;
 int prev=-1;
 int sz=1;
 int steps = 0, joe=1;
 if(n == m) {printf("0\n"); joe=0;}
 while(joe) {
 int savesz = sz;
 int flag = 0;
 for(int i = prev+1; i < savesz; i++) {
    if(2*tree[i]==m) {
        printf("%d\n", steps+1);
        flag = 1;
        break;
    } else if(2*tree[i] < m && !check[2*tree[i]]) {
        tree[sz] = 2*tree[i];
        check[tree[sz]] = 1;
        sz++;
    }
     if(tree[i]+1==m) {
        printf("%d\n", steps+1);
        flag = 1;
        break;
    } else if(tree[i]+1 < m && !check[tree[i]+1]) {
        tree[sz] = tree[i]+1;
        check[tree[sz]] = 1;
        sz++;
    }
 }
 if(flag) break;
 steps++;
 prev= savesz-1;
 }
 f(i,m) printf("%d ", tree[i]);
 return 0;
}
// queue korbo
void pop(struct node* root)//popfront
{
    temp=(struct node*) calloc(sizeof(struct  node));
    temp=root;
    root=root->next;
    delete(temp);
   siz--;
}
void popback(struct node* last)
{
    temp=(struct node*) calloc(sizeof(struct  node));
    temp=last;
    last=last->prev;
    delete(temp);
   siz--;
}

void push(struct node* last, int val)//pushback
{
   temp ->prev=last;
   last = temp;
    siz++;

}

int  empty(struct node* root)
{
   if(root==NULL) return 1;
   return 0;
}

int size(struct node* root, int count)// count 0
{    
    if(root->next==NULL) return count;
    
    count++;
    size(struct node* root->next, int count);

}
void pushfront(struct node* root, struct node* temp)//pushfront
{
    temp->next=root;
    root=temp;
    siz++;
}
int front(struct node* root)
{
    return root->val;
}
int back(struct node* last)
{
    return last->val;
}