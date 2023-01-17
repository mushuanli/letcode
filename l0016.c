#include <stdio.h>
#include <stdlib.h> 
#include<string.h> 
#include <ctype.h>
#include <limits.h>

/** 
 * 题目：https://leetcode.cn/problems/3sum-closest/description/
 * 16. 最接近的三数之和
中等
1.3K
相关企业
给你一个长度为 n 的整数数组 nums 和 一个目标值 target。请你从 nums 中选出三个整数，使它们的和与 target 最接近。

返回这三个数的和。

假定每组输入只存在恰好一个解。
*/
/**
 * 解题：
 *  求最接近的和，那么意思就是排序后根据偏差调整范围， 也就是先固定一个数，然后用双指针找到合适的另外两个数
*/
int sort_cmpfunc (const void * a, const void * b)
{
   return ( *(int*)a - *(int*)b );
}

int threeSumClosest(int* nums, int numsSize, int target){
    if( numsSize <= 3 ){
        int sum = 0;
        for( int i = 0; i < numsSize ; i ++ ){
            sum += nums[i];
        }
        return sum;
    }
   
   int minans   = INT_MAX;
   int bestsum  = 0;
    qsort(nums, numsSize, sizeof(int), sort_cmpfunc);


    for( int i = 0; i < numsSize -2 ; i ++ ){
        if( i > 0 && nums[i] == nums[i-1] )
            continue;
        int left    = i +1;
        int right   = numsSize -1;
        int sum     = nums[i] + nums[left] + nums[right];
        int ans     = sum - target;
        if( ans == 0 )
            return sum;
        else if( abs(ans) < minans ){
            minans  = abs(ans);
            bestsum = sum;
        }
        while( ans != 0 && right != left +1 ){
            if( ans > 0 ){
                right --;
            }
            else{
                left ++;
            }
            sum     = nums[i] + nums[left] + nums[right];
            ans     = sum - target;
            if( ans == 0 )
                return sum;
            else if( abs(ans) < minans ){
                minans  = abs(ans);
                bestsum = sum;
            }
        }
    }

    return bestsum;
}

#define VERIFY(a,v)   threeSumClosest(a,sizeof(a)/sizeof(int),v)
int main()
{
    int n[] = {4,0,5,-5,3,3,0,-4,-5};
    int i = VERIFY(n,-2);
    printf("%d\n",i);
}
