/* 题目: https://leetcode.cn/problems/median-of-two-sorted-arrays/
给定两个大小分别为 m 和 n 的正序（从小到大）数组 nums1 和 nums2。请你找出并返回这两个正序数组的 中位数 。

算法的时间复杂度应该为 O(log (m+n)) 。

 

示例 1：

输入：nums1 = [1,3], nums2 = [2]
输出：2.00000
解释：合并数组 = [1,2,3] ，中位数 2
示例 2：

输入：nums1 = [1,2], nums2 = [3,4]
输出：2.50000
解释：合并数组 = [1,2,3,4] ，中位数 (2 + 3) / 2 = 2.5

*/

/* 题解：
   中位数是 list[mid]（奇数个） 或 (list[mid -1] + list[mid])/2（偶数个）
   其中 mid = (nums1Size+nums2Size)/2
   1。 因为两个都是有序数组，所以问题转化成合并后 list[mid] 和 list[mid -1] 是哪两个数
   2.  利用排序方法找到这两个数
*/
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int i = 0, j = 0, m1 = 0, m2 = 0;
    int mid = (nums1Size+nums2Size)/2;
    if( nums1Size == 0 && nums2Size == 0 )
        return 0;
    if( nums1Size == 0 )
        return nums2Size%2 == 0 ? (double)(nums2[mid -1] + nums2[mid])/2.0 : nums2[mid];
    else if( nums2Size == 0 )
        return nums1Size%2 == 0 ? (double)(nums1[mid -1] + nums1[mid])/2.0 : nums1[mid];

    int prev   = NULL;
    int next   = nums1[0] <= nums2[0] ? nums1[0] : nums2[0];

    while( (i + j ) <= mid ){
        prev    = next;
        if( i < nums1Size ){
            if( j == nums2Size || nums1[i] <= nums2[j] ){
                next = nums1[i];
                i ++;
                continue;
            }
        }

        next = nums2[j];
        j ++;
    }

    return (nums1Size+nums2Size)%2 ? next : (double)(prev + next)/2.0;
}
