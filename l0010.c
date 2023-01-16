/** 题目: https://leetcode.cn/problems/regular-expression-matching/
给你一个字符串 s 和一个字符规律 p，请你来实现一个支持 '.' 和 '*' 的正则表达式匹配。

'.' 匹配任意单个字符
'*' 匹配零个或多个前面的那一个元素
所谓匹配，是要涵盖 整个 字符串 s的，而不是部分字符串。

 
示例 1：

输入：s = "aa", p = "a"
输出：false
解释："a" 无法匹配 "aa" 整个字符串。
示例 2:

输入：s = "aa", p = "a*"
输出：true
解释：因为 '*' 代表可以匹配零个或多个前面的那一个元素, 在这里前面的元素就是 'a'。因此，字符串 "aa" 可被视为 'a' 重复了一次。
示例 3：

输入：s = "ab", p = ".*"
输出：true
解释：".*" 表示可匹配零个或多个（'*'）任意字符（'.'）。

*/

/** 题解：
    1. 快速跳过没有正则部分
    2. 对于正则部分，使用动态规划记录状态
       dp[i]  [j]  表示当 s[0:i] p[0-j] 时匹配情况, 由于 i ++ , j++ 都独立循环，所以可以判断所有的匹配可能
*/

int isMatch(char * s, char * p){
    while( *s && *p && (*s == *p || *p == '.') && p[1] != '*'){
        s++;
        p++;
    }

    if( *s == 0 )
        return *p == 0 || (p[1] == '*' && p[2] == 0 )? 1 : 0;
    else if( *p == 0 )
        return 0;
    else if( *p != '.' && p[1] != '*' )
        return 0;

    int slen    = strlen(s);
    int dlen    = strlen(p);
    int *dp[25];
    int *cache  = (int *)malloc(sizeof(int)*(slen+1)*(dlen+1));
    for( int i = 0; i <= slen ; i ++ )
        dp[i]   = cache + i *(dlen+1);

    memset(cache,0,sizeof(int)*(slen+1)*(dlen+1));
    /*
     This problem has a typical solution using Dynamic Programming. We define the state P[i][j] to be true if s[0..i) matches p[0..j) and false otherwise. Then the state equations are: 
         a. P[i][j] = P[i - 1][j - 1], if p[j - 1] != ‘*’ && (s[i - 1] == p[j - 1] || p[j - 1] == ‘.’); 
         b. P[i][j] = P[i][j - 2], if p[j - 1] == ‘*’ and the pattern repeats for 0 times; 
         c. P[i][j] = P[i - 1][j] && (s[i - 1] == p[j - 2] || p[j - 2] == ‘.’), if p[j - 1] == ‘*’ and the pattern repeats for at least 1 times. 
   Putting these together, we will have the following code.*/
    dp[0][0]    = 1;
    for (int i = 0; i <= slen; i++)
        for (int j = 1; j <= dlen; j++)
            if (p[j - 1] == '*')
                dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') && dp[i - 1][j]);
            else 
                dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
    return dp[slen][dlen];
}
