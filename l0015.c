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
*/

int sort_cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int** threeSum(int nums[], int numsSize, int* returnSize, int** returnColumnSizes){
   int retsize          = 0;
   int **retcode        = NULL;
   
   *returnSize          = 0;

   if( numsSize < 3){
      return NULL;
   }

   // sort first
   qsort(nums, numsSize, sizeof(int), sort_cmpfunc);

   // check border
   if( nums[numsSize -1 ] < 0 ){
      return NULL;
   }

   int cstart  = 0;
   int cend    = numsSize -1;
   for( ; cstart < numsSize && nums[cstart] < 0 ; cstart ++ ) ;
   if( cstart == numsSize )
       return NULL;
   if( nums[cstart] == 0 && cstart == numsSize -1 ){
      if( nums[cstart-1] != 0 &&  nums[cstart-2] != 0 )
         return NULL;
   }

   int astart  = 0;

   if(numsSize < 2000 )
      retcode  = (int**)malloc(numsSize *3* sizeof(int*));
   else
      retcode  = (int**)malloc(100000* sizeof(int*));

   for( int i = astart ; i < numsSize && nums[i] <= 0 ; i ++ ){
      if( i > astart && nums[i] == nums[i-1] )
         continue;

      int ctmp  = cend;
      int value = nums[i] + nums[i +1];
      if( value > nums[cstart] )
         break;
      value    *= -1;
      for( ctmp = cend ; nums[ctmp] > value ; ctmp -- );
      if( nums[ctmp] == value )
         cend  = ctmp;
      else if( ctmp < cend )
         cend  = ctmp +1;

      for( int j = i+1; j < numsSize ; j ++ ){
         if( j > i+1 && nums[j] == nums[j-1] )
            continue;
         value = nums[i] + nums[j];
         if( value > 0 ){
            break;
         }

         value *= -1;
         if( value < nums[j] )
            break;
   
         int cindex = ctmp;
         for( ; nums[cindex] > value && cindex > cstart && cindex > j; cindex -- ) ;
         
         if( nums[cindex] == value ){
            if( cindex > j ){
               int *v = (int *)malloc(3*sizeof(int));
               v[0]  = nums[i];
               v[1]  = nums[j];
               v[2]  = value;
               retcode[retsize++]  = v;
            }
            
            ctmp  = cindex;
            continue;
         }
         else if( cindex < ctmp )
            ctmp  = cindex +1;
      }
   }

end:
   *returnSize          = retsize;
   (*returnColumnSizes) = (int *)malloc(sizeof(int) * (*returnSize));
   // 本题中每一个元素都是3
   for (int i = 0; i < (*returnSize); i++) {
      (*returnColumnSizes)[i] = 3;
   }
   return retcode;
}
