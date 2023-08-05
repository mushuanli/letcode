#include <stdio.h>
#include <stdlib.h>

/**
 * 1. p0 指向开头第一个非0元素
 * 2. p2 指向结尾第一个非2元素
 * 3. p1 指向还没排序的元素，正常情况下应该是1
 * 4. 当p1指向的元素不是1时，与p0 或p2交换, 然后继续调整p0和p2位置
*/
void sortColors(int* nums, int numsSize){
    // | -> p0  p1    p2 <- |
    int *p0 = nums;
    int *p2 = nums+numsSize-1;
    int *p1 = nums;

    while( p0[0] == 0 && p0 != p2 ) p0++;
    if( p0 == p2 )
       return ;

    while( p2[0] == 2 && p2 != p0 ) p2--;
    if( p2 == p0 )
       return ;

    p1 = p0;
    while( p1 <= p2 ){
        if( *p1 == 1 ){
            p1 ++;
            continue;
        }

        if( *p1 == 0 ){
            *p1 = *p0;
            *p0++ = 0;
        }
        else if( *p1 == 2){
            *p1 = *p2;
            *p2-- = 2;
        }
        while( *p0 == 0 && p0 != p2 ) p0++;
        while( p2[0] == 2 && p2 != p0 ) p2--;
        if( p1 < p0)
          p1 = p0;

    }

}


#define V(arr)  sortColors(arr,sizeof(arr)/sizeof(int))

int main()
{
    int arr1[]={2,0,1};
    V(arr1);
    return 0;
}
