/* 题目: https://leetcode.cn/problems/longest-substring-without-repeating-characters/
给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。


*/

/* 题解：
   利用滑动窗口，用 map 保存窗口中字符的存在状况
   1。 向右滑动, 直到map判断有重复, 或是已经移动到最后
   2.  这时左指针右移（同时清除map对应标志）
*/
int getmax(int left, int right){
    return right < left  ? left : right;
}

int lengthOfLongestSubstring(char * s){
    if( !s || !*s )
      return 0;
      
    char map[256]   = {0};

    char *left = s ;
    char *right = s + 1;
    int max = 0;
    map[*left] = 1;
    while( *right ){
        if( map[*right] == 0 ){
            map[*right] = 1;
            right ++;
        }
        else{
            max = getmax( max ,right - left);
            map[*left] = 0;
            left ++;
        }
    }

    return getmax( max ,right - left);
}
