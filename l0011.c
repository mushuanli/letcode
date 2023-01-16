/** 题目: https://leetcode.cn/problems/container-with-most-water/
11. 盛最多水的容器
中等
4K
相关企业
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。

找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。

返回容器可以储存的最大水量。

说明：你不能倾斜容器。
*/

/** 题解：
    容量 = 两点距离 * 两点最小值
    所以题目转换成：
    从左右两边开始（距离最大）
    当某点的值小时，移动到下一个点。
*/

int maxArea(int* height, int heightSize){
    if( heightSize < 2 )
        return 0;
    else if ( heightSize == 2 ){
        int v   = height[0] < height[1] ? height[0] : height[1];
        return v *1;
    }

    int mid = heightSize/2;
    int left = 0;
    int right = heightSize -1;
    int max = 0;
    while( left < right ){
        int v   = height[left] < height[right] ? height[left] : height[right];
        int tmp = v*(right - left);
        if( tmp > max )
            max = tmp;

        if( height[left] < height[right] ){
            if( left +1 == right ){
                break;
            }
            left ++;
        }
        else{
            if( right - 1 == left )
                break;
            right --;
        }

    }
    return max;
}
