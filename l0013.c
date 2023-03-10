/** 题目: https://leetcode.cn/problems/roman-to-integer/
13. 罗马数字转整数
简单
2.2K
相关企业
罗马数字包含以下七种字符: I， V， X， L，C，D 和 M。

字符          数值
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
例如， 罗马数字 2 写做 II ，即为两个并列的 1 。12 写做 XII ，即为 X + II 。 27 写做  XXVII, 即为 XX + V + II 。

通常情况下，罗马数字中小的数字在大的数字的右边。但也存在特例，例如 4 不写做 IIII，而是 IV。数字 1 在数字 5 的左边，所表示的数等于大数 5 减小数 1 得到的数值 4 。同样地，数字 9 表示为 IX。这个特殊的规则只适用于以下六种情况：

I 可以放在 V (5) 和 X (10) 的左边，来表示 4 和 9。
X 可以放在 L (50) 和 C (100) 的左边，来表示 40 和 90。 
C 可以放在 D (500) 和 M (1000) 的左边，来表示 400 和 900。
给定一个罗马数字，将其转换成整数。


*/

/** 题解:
 简单的转换问题,
  但是优先判断特殊字符串(4,9)
*/

int romanToInt(char * s){
    int num=0;

    for( ;*s; s++ ){
        switch(*s){
            case 'I':
            if( s[1] == 'V' ){
                num += 4;
                s++;
            }
            else if( s[1] == 'X'){
                num += 9;
                s++;
            }
            else{
                num ++;
            }
            break;

            case 'V':
            num += 5;
            break;
        
            case 'X':
            if( s[1] == 'L' ){
                num += 40;
                s++;
            }
            else if( s[1] == 'C'){
                num += 90;
                s++;
            }
            else{
                num += 10;
            }
            break;

            case 'L':
            num += 50;
            break;

            case 'C':
            if( s[1] == 'D' ){
                num += 400;
                s++;
            }
            else if( s[1] == 'M'){
                num += 900;
                s++;
            }
            else{
                num += 100;
            }
            break;

            case 'D':
            num += 500;
            break;

            case 'M':
            num += 1000;
            break;
            default:
            break;
        }
    }
        return num;
}
