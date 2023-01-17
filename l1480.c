/** 题目: https://leetcode.cn/problems/running-sum-of-1d-array/
1480. 一维数组的动态和
简单
321
相关企业
给你一个数组 nums 。数组「动态和」的计算公式为：runningSum[i] = sum(nums[0]…nums[i]) 。

请返回 nums 的动态和。
*/

/* 题解:
       入门题，sum[i] = sum[i-1] + nums[i]]
*/
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* runningSum(int* nums, int numsSize, int* returnSize){
    *returnSize = numsSize;
    if(numsSize < 1)
      return NULL;
    
    for( int i = 1;i < numsSize ; i ++ ){
            nums[i] = nums[i] + nums[i-1];
    }
    return nums;
}
