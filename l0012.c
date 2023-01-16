/** 题目: https://leetcode.cn/problems/integer-to-roman/
 12. 整数转罗马数字
中等
1K
相关企业
罗马数字包含以下七种字符： I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给你一个整数，将其转为罗马数字。
*/

/**
  题解： 问题就是简单的转换问题，但是:
        1. 从大到小转换
        2. 如果有特殊数字优先转换(4,9)
        3. 其他的正常转
*/


char near_pre[] = "IXC";
char near_4[]   = "VLD";
char near_9[]   = "XCM";
char roman_v[]  = "VLD";
char roman_i[]  = "IXCM";
char cache[20];

char* rostr(char *buf, int num,int step){
    if( num == 9 || num == 4 ){
        *buf++  = near_pre[step];
        *buf++  = num == 9 ? near_9[step] : near_4[step];

        return buf;
    }
    int five = num /5;
    num     = num %5;
    if( five )
        *buf++  = roman_v[step];
    for( int i = 0; i < num ; i ++ ){
        *buf++  = roman_i[step];
    }

    return buf;
}

char * intToRoman(int num){
    if( num < 1 )
        return "";

    char *p = cache;
    if( num >= 1000 ){
        p = rostr(p,(num / 1000)%10 , 3);
        num %= 1000;
    }
    if( num >= 100 ){
        p = rostr(p,num / 100 , 2);
        num %= 100;
    }
    if( num >= 10 ){
        p = rostr(p,num / 10 , 1);
        num %= 10;
    }
    p = rostr(p,num % 10 , 0);

    *p++=0;
    return cache;
}
