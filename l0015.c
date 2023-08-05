/** 题目: https://leetcode.cn/problems/3sum/
15. 三数之和
中等
5.5K
相关企业
给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，同时还满足 nums[i] + nums[j] + nums[k] == 0 。请

你返回所有和为 0 且不重复的三元组。

注意：答案中不可以包含重复的三元组。
*/

/** 题解:
  3数之和 = 两数之和 - 第三数 = 0
  思路： I + J <= 0, K >=0, 然后移动最后指针加快速度
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STEP_LEN  1024
struct matchCtl{
    int ** retList;
    int rows;
    int idx;
};

/**
*  1. sort
*  2. split <0 part and >0 part, then compare and find via 2 arrow
*/
int sort_cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

void saveMatchValue(struct matchCtl *pctl, int v1,int v2,int v3){
    if( pctl->retList == NULL ){
        pctl->retList   = malloc(STEP_LEN*sizeof(int *));
        pctl->rows      = STEP_LEN;
        pctl->idx       = 0;
    }
    else if( pctl->idx +1 == pctl->rows ){
        int ** retList   = malloc((pctl->rows+STEP_LEN)*sizeof(int *));
        memcpy(retList,pctl->retList,pctl->rows * sizeof(int *));
        free(pctl->retList);
        pctl->retList = retList;
        pctl->rows += STEP_LEN;
    }

    int *v = (int *)malloc(3*sizeof(int));
    v[0]  = v1;
    v[1]  = v2;
    v[2]  = v3;
    pctl->retList[pctl->idx++] = v;
}

int** ReturnMatchValue(struct matchCtl *pctl,int* returnSize, int** returnColumnSizes){
   *returnSize = pctl->idx;
   if( pctl->retList ){
      int *val = (int *)malloc(3*sizeof(int) * pctl->idx);
      (*returnColumnSizes) = val;
      // 本题中每一个元素都是3
      for (int i = 0; i < pctl->idx; i++) {
         val[i] = 3;
      }
   }
   else{
        pctl->retList   = malloc(sizeof(int *));
        pctl->retList[0]    = NULL;
   }

   return pctl->retList;
}

int** returnOne(int* returnSize, int** returnColumnSizes,int v1 ,int v2,int v3){
    struct matchCtl mctl = {0};
   saveMatchValue(&mctl,v1,v2,v3);
   return ReturnMatchValue(&mctl,returnSize, returnColumnSizes);
}

int** threeSum(int nums[], int numsSize, int* returnSize, int** returnColumnSizes){
   struct matchCtl mctl = {0};

   *returnSize          = 0;

   if( numsSize < 3){
      return NULL;
   }

   // sort first
   qsort(nums, numsSize, sizeof(int), sort_cmpfunc);

   // fast check border
   if( nums[0] >0 || nums[numsSize -1 ] < 0 ){
      return NULL;
   }
   if( nums[0] == 0 ){
       return nums[2] != 0 ? NULL: returnOne( returnSize,returnColumnSizes,0,0,0);
   }
   else if( nums[numsSize -1 ] == 0 ){
       return nums[numsSize-3] != 0 ? NULL: returnOne(returnSize,returnColumnSizes,0,0,0);
   }

   // find positive start pos
   int positive_start = 0;
   for( ; positive_start < numsSize && nums[positive_start] <= 0 ; positive_start ++ ) ;


   // move 2 arrow to find match, and will skip prev check item(same value)
   //|-> ^i  ^j  ^k     end<-|      nums[i]+nums[j] = nums[k] * -1 
   //                               nums[i]+nums[j] <= 0 ; nums[k] >= 0 
   int start = positive_start;
   int end = numsSize -1;   // last k index
   for( int i = 0; i < positive_start ; i ++ ){
      if( nums[i] == 0 ){
         if( positive_start - i >= 3){// -1,0,0,0,1
               saveMatchValue(&mctl,0,0,0);
         }
         break;
      }

      if( i > 0 && nums[i] == nums[i-1] )
        continue;

      int value = (nums[i]+nums[i+1])*(-1);
      if( value <= 0 )
        break;

    if( value < nums[end] ){
         while( value < nums[end-1] && end > i  ) end --;
      }
      else{
        if( i+1 == end || -1*(nums[i] + nums[end-1]) > nums[end] )
          continue;
      }

      int tmpend = end;
      for( int j = i+1; j < end; j ++ ){
         if( j > i+1 && nums[j] == nums[j-1] )
           continue;

         int value = (nums[i]+nums[j]);

        if( value > nums[positive_start] )
            break;
        
        value *= -1;

        // kstart <- k <- tmpend
        int kstart = j+1 > positive_start ? j+1 : positive_start;
         if( value > nums[tmpend] || value < nums[kstart] )
           continue;
        
         for( int k = tmpend ; k >= kstart ; k -- ){
            if( nums[k] == value ){
               saveMatchValue(&mctl,nums[i],nums[j],nums[k]);
               tmpend = k;
               break;
            }
            else if( nums[k] < value ){
                tmpend = k;
               break;
            }
         }
      }
   }

   return ReturnMatchValue(&mctl,returnSize, returnColumnSizes);
}

#define V(arr) threeSum(arr,sizeof(arr)/sizeof(int), &returnSize, &returnColumnSizes)
int main()
{
    int returnSize, *returnColumnSizes;

    int arr[]={1,-1,-1,0};
    int** retList= V(arr);
    int arr2[]={3,-2,0,1};
    retList = V(arr2);
    return 0;
}

