#include <iostream>
#include <stdio.h>
#include <math.h>
#define ll long long

int comparator(const void* p, const void* q) 
{ 
    
   
   return  *(const ll*)q > *(const ll*)p ? -1 : 1;
}


int main(){


    int t;
    scanf("%d",&t);
    for(int i=0;i<t;i++)
    {  
int n,k=0,sum=0;
long long p, max=0;
        scanf("%d",&n);
int arr[n];
          for(int i=0;i<n;i++)
    {  scanf("%lld",&p);
    //printf("%lld ",p);
           if(p<max){
            arr[k]=(int)(max-p); k++; //printf("%d ",arr[k-1]);
           }
           else {max=p;}
           
          
               }

//printf("\n%d\n",k);

qsort((void*)arr, k, 4, comparator);
            for(int i=0;i<k;i++)
            { //printf("%d ",arr[i]); 
            if(k==1){sum=2; break; }
            if(i==k-1) {  sum+=(i+2)*(arr[i]); break;}
            
            if(arr[i]==arr[i+1])  {i++; sum+=(i+2)*(arr[i]);}
               else  sum+=(i+2)*(arr[i]-arr[i+1]);
            
            }
  //if(k && !sum){sum=k;}
  
  printf("%d\n",sum);  }
    
return 0;
}

