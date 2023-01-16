/** 题目: https://leetcode.cn/problems/reverse-integer/
给你一个 32 位的有符号整数 x ，返回将 x 中的数字部分反转后的结果。

如果反转后整数超过 32 位的有符号整数的范围 [−231,  231 − 1] ，就返回 0。

假设环境不允许存储 64 位整数（有符号或无符号）。
 

示例 1：

输入：x = 123
输出：321
*/

/** 题解：反转就是 ((x/N) %10) * 10 + x %10, 也就是从低到高，sum += sum * 10 + 最低位数字
    但是要注意边界，也就是当是10位数时是否会越界
    以下可优化
*/

int reverse_(int x,int num){
    #define PALINDROME_C(num,x,whole)   ( x/whole) + end*whole + reverse_((x%whole)/10,num-2) * 10
    if( num <= 1 || x == 0 ) return x;
    int end = x % 10;
    switch( num ){
        case 10: return PALINDROME_C( 10,x,1000000000);
        case 9:  return PALINDROME_C( 9,x,100000000);
        case 8:  return PALINDROME_C( 8,x,10000000);
        case 7:  return PALINDROME_C( 7,x,1000000);
        case 6:  return PALINDROME_C( 6,x,100000);
        case 5:  return PALINDROME_C( 5,x,10000);
        case 4:  return PALINDROME_C( 4,x,1000);
        case 3:  return PALINDROME_C( 3,x,100);
        case 2:  return ( x/10) + end*10;
        default: break;
    }
    return x;
}

int ifinrange(x){
    char buf[12];
    sprintf(buf,"%d",x);
    char *p = buf + strlen(buf)-1;
    char maxvalue[]="2147483647";
    for( int i = 0; i < 10;i++,p--){
        if( *p > maxvalue[i] )
            return 0;
        if( *p < maxvalue[i] )
            return 1;
        if( i == 10 && ((x < 0 && *p <= 8) || (x > 0 && *p >= 7)))
            return 1;
    }
    return 0;
}

int reverse(int x){
  if( x == 0 ) return 0;
  for( ; x %10 == 0 ; x = x /10);

  if( x > -10 && x < 10  ) return x;
  else if( x > -100 && x < 100  ) return reverse_(x,2);
  else if( x > -1000 && x < 1000  ) return reverse_(x,3);
  else if( x > -10000 && x < 10000  ) return reverse_(x,4);
  else if( x > -100000 && x < 100000  ) return reverse_(x,5);
  else if( x > -1000000 && x < 1000000  ) return reverse_(x,6);
  else if( x > -10000000 && x < 10000000  ) return reverse_(x,7);
  else if( x > -100000000 && x < 100000000  ) return reverse_(x,8);
  else if( x > -1000000000 && x < 1000000000  ) return reverse_(x,9);
  else{
    if( !ifinrange(x))
        return 0;
        // -2147483648~2147483647
    return reverse_(x,10);
  }
}
