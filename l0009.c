/** 题目： https://leetcode.cn/problems/palindrome-number/
给你一个整数 x ，如果 x 是一个回文整数，返回 true ；否则，返回 false 。

回文数是指正序（从左向右）和倒序（从右向左）读都是一样的整数。

例如，121 是回文，而 123 不是。
 
*/

/** 题解： 1. 判断数字的位数
          2. 获取某位数字, 判断是否等于它的对称数字
    下面实现可以优化成先把整数转换成一个个数字的数组，然后一一判断
*/

int isPalindrome_(int x,int num){
    #define PALINDROME_C(num,x,whole)   ( x/whole) == end && isPalindrome_((x%whole)/10,num-2)
    if( num <= 1 || x == 0 ) return 1;
    int end = x % 10;
    switch( num ){
        case 10: return PALINDROME_C( 10,x,1000000000);
        case 9:  return PALINDROME_C( 9,x,100000000);
        case 8:  return PALINDROME_C( 8,x,10000000);
        case 7:  return PALINDROME_C( 7,x,1000000);
        case 6:  return PALINDROME_C( 6,x,100000);
        case 5:  return PALINDROME_C( 5,x,10000);
        case 4:  return PALINDROME_C( 4,x,1000);
        case 3:  return x / 100 == end ? 1 : 0;
        case 2:  return x % 11 == 0 ? 1 : 0;
        default: break;
    }
    return 1;
}

int isPalindrome(int x){
  if( x < 0 ) return 0;
  else if( x < 10 ) return 1;
  else if( x < 100 ) return x % 11 == 0 ? 1 : 0;
  if( x >= 1000000000 ) return isPalindrome_(x,10);
  else if( x >= 100000000 ) return isPalindrome_(x,9);
  else if( x >= 10000000 ) return isPalindrome_(x,8);
  else if( x >= 1000000 ) return isPalindrome_(x,7);
  else if( x >= 100000 ) return isPalindrome_(x,6);
  else if( x >= 10000 ) return isPalindrome_(x,5);
  else if( x >= 1000 ) return isPalindrome_(x,4);
  else if( x >= 100 ) return isPalindrome_(x,3);
  else return 1;
}
