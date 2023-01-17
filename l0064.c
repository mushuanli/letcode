/** 题目： https://leetcode.cn/problems/minimum-path-sum/
64. 最小路径和
中等
1.4K
相关企业
给定一个包含非负整数的 m x n 网格 grid ，请找出一条从左上角到右下角的路径，使得路径上的数字总和为最小。

说明：每次只能向下或者向右移动一步。
*/

/**
  题解: 
  因为只能向上或向右移动，所以每个点的值由上一个或前一个的最小值确定
  转移函数: dp[i][j] = min(dp[i-1][j],dp[i][j - 1]) + grid[i][j];
*/

int minPathSum(int** grid, int gridSize, int* gridColSize){
   int dp[gridSize][*gridColSize];
   dp[0][0] = grid[0][0];  // 起点
   if( gridSize == 1 ){
      for( int j = 1; j < *gridColSize; j ++ )  // i = 0 的边界情况,路径只能从 j - 1 通过
         dp[0][j] = dp[0][j - 1] + grid[0][j];
   }
   else if( *gridColSize == 1){
      for( int i = 1; i < gridSize ; i ++ )
         dp[i][0] = dp[i-1][0] + grid[i][0];
   }
   else{
      for( int i = 1; i < gridSize ; i ++ ){
         dp[i][0] = dp[i-1][0] + grid[i][0];
         for( int j = 1; j < *gridColSize; j ++ ){
            dp[0][j] = dp[0][j - 1] + grid[0][j];
               if ( dp[i][j - 1] < dp[i-1][j] )
                  dp[i][j] = dp[i][j - 1] + grid[i][j];
               else
                  dp[i][j] = dp[i-1][j] + grid[i][j];
         }
      }
   }

   return dp[gridSize-1][*gridColSize -1];
}
