/** 题目: https://leetcode.cn/problems/zigzag-conversion/
将一个给定字符串 s 根据给定的行数 numRows ，以从上往下、从左到右进行 Z 字形排列。

比如输入字符串为 "PAYPALISHIRING" 行数为 3 时，排列如下：

P   A   H   N
A P L S I I G
Y   I   R
之后，你的输出需要从左往右逐行读取，产生出一个新的字符串，比如："PAHNAPLSIIGYIR"。

请你实现这个将字符串进行指定行数变换的函数：

string convert(string s, int numRows);
 

示例 1：

输入：s = "PAYPALISHIRING", numRows = 3
输出："PAHNAPLSIIGYIR"
示例 2：
输入：s = "PAYPALISHIRING", numRows = 4
输出："PINALSIGYAHRPI"
解释：
P     I    N
A   L S  I G
Y A   H R
P     I
示例 3：

输入：s = "A", numRows = 1
输出："A"
*/

/** 题解:
   由列表得知排列规律是 2*numRows -2 (除第一列和最后一列外，一个循环内每列都有两个字符)
   所以问题就变成转换下标映射,也就是
   s[i++ *(2*numRows -2)]
   s[i *(2*numRows -2) +1 ] s[(i +1)*(2*numRows -2) -1 ] ; i ++
   ...
   s[i++ *(2*numRows -2) + numRows -1]
*/

char * convert(char * s, int numRows){
    if( numRows < 2 || !s || !s[0] || !s[1] )
      return s;

    int len = strlen(s);
    int loopnum = numRows * 2 - 2;
    char *v = strdup(s);
    char *p = v;
    for( int i = 0; i <  numRows ; i ++ ){
        for( int j = 0; j * loopnum + i < len; j ++ ){
            *p++ = s[j * loopnum + i];
            if( i == 0 || i == numRows -1 )
              continue;
            int k   = (j +1)* (loopnum) -i;
            if( k >= 0 && k < len )
            *p++ = s[k];
        }
    }
    return v;
}
