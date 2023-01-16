/** 题目: https://leetcode.cn/problems/longest-common-prefix/description/
14. 最长公共前缀
简单
2.6K
相关企业
编写一个函数来查找字符串数组中的最长公共前缀。

如果不存在公共前缀，返回空字符串 ""。

 

示例 1：

输入：strs = ["flower","flow","flight"]
输出："fl"
示例 2：

输入：strs = ["dog","racecar","car"]
输出：""
解释：输入不存在公共前缀。
*/

/** 题解:
  公共前缀就是前面的字符都相等
  
*/
char * longestCommonPrefix(char ** strs, int strsSize){
    if( strsSize == 0 )
       return 0;
    else if( strsSize == 1 )
       return strs[0];
    
   for( int i = 0; strs[0][i] ; i ++ ){
       for( int j = 1; j < strsSize ; j ++ ){
        if( strs[0][i] != strs[j][i] ){
            strs[0][i] = 0;
            return strs[0];
        }
       }

   }
    return strs[0];
}
