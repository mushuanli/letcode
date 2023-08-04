#include <stdio.h>
#include <stdlib.h>

int cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int findidx(int val,int *nums,int size, int next){
    for( int i = 0; i < size ; i ++ )
      if( nums[i] == val ){
        if( next -- == 0 )
        return i;
      }
    return size;
}


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target, int* returnSize){
  *returnSize = 2;
  int *pret = malloc(2*sizeof(int));
    if( numsSize <= 2 ){
        pret[0]=0;
        pret[1]=1;
        return pret;
    }

  unsigned int sortarr[numsSize];
  for( int i = 0; i < numsSize; i++){
    sortarr[i]=nums[i];
  }

  qsort(sortarr,numsSize,sizeof(int),&cmpfunc);

  for( int i = 0; i < numsSize-1; i ++ ){
      int val       = sortarr[i];

      for( int j = i+1; j < numsSize; j ++ ){
        int sum    = sortarr[j] + val;
        if( sum == target ){
            pret[0]=findidx(val,nums,numsSize, 0);
            pret[1]=findidx(sortarr[j],nums,numsSize, sortarr[j] == val ? 1:0);

            return pret;
        }
          
        if( sum > target )
            break;
      }
  }
  return NULL;
}

/**
* 1. sort
* 2. move two arrow 
*/

#define V(v,chk0,chk1,arr) do{ int retsz=0;\
int *ret=twoSum(arr,sizeof(arr)/sizeof(int),v,&retsz); \
if( ret[0]== chk0 && ret[1] == chk1) printf("%d check ok %d,%d\n",v, ret[0],ret[1]); \
else printf("%d check fail %d,%d\n",v, ret[0],ret[1]); \
free(ret); \
}while(0)

int main()
{
    int v1[]={2,7,11,15};
    V(9,0,1,v1);
    int v2[]={2,3,3};
    V(6,1,2,v2);
    int v3[]={3,3};
    V(6,0,1,v3);

    return 0;
}
