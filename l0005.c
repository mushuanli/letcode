/**
题目： https://leetcode.cn/problems/longest-palindromic-substring/
5. 最长回文子串
中等
6.1K
相关企业
给你一个字符串 s，找到 s 中最长的回文子串。

如果字符串的反序与原始字符串相同，则该字符串称为回文字符串。
*/

/**
题解:
  最大回文从中间扩展比较快
  回文有两种情况: abba aba
  综上得知判断方法为，中点从中间开始向两边：
     左判断： aba abba
     又判断: aba abba
*/
const char* extend(int *len,const char *s,int i,int j){
    int offset = 0;
    char *l = s + i;
    char *r = s + j;
    if( *l == *r ){
        for( ; offset < i ; l--,r++,offset ++ ){
            if( l[-1] != r[1] )
                break;
        }
    }

    if( l == r || *l != *r){
        *len = 0;
        return NULL;
    }

    *len = r - l +1;
    return l;
}


char * longestPalindrome(char * s){
    int size = strlen(s);
    int mid = size/2;
    int maxlen = 0;
    char *maxstr=NULL;
    if( size == 0 )
        return NULL;

    for( int i = 0; i <= mid ; i ++ ){
        int len[4] = {0,0,0,0};
        char* start[4];
         start[0]=extend(&len[0],s,mid -i,mid -i);
         start[1]=extend(&len[1],s,mid -i,mid -i+1);
         if( i != 0 && mid +i < size ){
            start[2]=extend(&len[2],s,mid +i,mid +i);
            if( mid +i +1 < size )
                start[3]=extend(&len[3],s,mid +i,mid +i+1);
         }

        for( int j = 0; j < 4 ; j ++){
            if( len[j] > maxlen ){
                maxlen = len[j];
                maxstr = start[j];
            }
        }
    }

    if( maxlen == 0 ){
        maxlen = 1;
        maxstr=s;
    }
      maxstr[maxlen]=0;
      return maxstr;
}
