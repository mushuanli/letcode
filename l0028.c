
/** 
 * 题目：https://leetcode.cn/problems/find-the-index-of-the-first-occurrence-in-a-string/description/
 * 28. 找出字符串中第一个匹配项的下标
中等
1.7K
相关企业
给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出 needle 字符串的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
*/

/**
 * 解题：Boyer-Moore算法
 * https://www.ruanyifeng.com/blog/2013/05/boyer-moore_string_search_algorithm.html
 * https://zhuanlan.zhihu.com/p/156757171
 * https://favtutor.com/blogs/boyer-moore-algorithm
 *  1. 根据 Boyer-Moore算法 仅使用 bad_table加快跳转
 * 2. 可以扩展增加good suffix
 * 
*/

int max (int a, int b) { return (a > b)? a: b; }

static void build_bad_table(int bad_table[],char* needle ,int plen){
    for( int i = 0; i < 256; i ++ )
        bad_table[i]    = -1;
    for( int i = 0; needle[i] ; i ++)
        bad_table[(unsigned int )needle[i]] = i;    //  由于是倒着搜索，所以记录的是最后一个字符地址
}

int strStr(char * haystack, char * needle){
    if( !haystack || !*haystack || !needle || ! *needle )
        return -1;

    int slen    = strlen(haystack);
    int plen    = strlen(needle);

    if( plen > slen )   //如果模式串比主串长，没有可比性，直接返回-1
        return -1;

    int bad_table[256];
    build_bad_table(bad_table,needle,plen);
    for( int i = 0; i <= (slen - plen); ){
        int j = plen -1;
        while( j >= 0 && haystack[i + j ] == needle[j]) j --;

        if( j < 0 )
            return i;

        i += max(1, j - bad_table[haystack[i + j]]);
    }

    return -1;
}
