#include <stdio.h>
#include <stdlib.h> 
#include<string.h> 
#include <ctype.h>
#include <limits.h>

/** 
 * 题目：https://leetcode.cn/problems/merge-k-sorted-lists/description/
 * 23. 合并K个升序链表
困难
2.3K
相关企业
给你一个链表数组，每个链表都已经按升序排列。

请你将所有链表合并到一个升序链表中，返回合并后的链表。


*/

/**
 * 解题：
 *  1. 直接对每一个链表从头进行遍历，每次提取最小元素, 但是由于队列长度不同，循环效率不高
 * 2. 两个两个的合并, 效率同上
 * 3. 分治算法，一半一半的合并，效率最好
*/

struct ListNode {
      int val;
      struct ListNode *next;
 };

struct ListNode* merge2List(struct ListNode* l1,struct ListNode* l2){
    if( !l1 )    return l2;
    if( !l2 )    return l1;

    struct ListNode*    head = NULL;
    if( l1->val < l2->val ){
        head    = l1;
        head->next = merge2List(l1->next,l2);
    }
    else{
        head    = l2;
        head->next = merge2List(l2->next,l1);
    }
    return head;
}

struct ListNode* mergeKLists(struct ListNode** lists, int listsSize){
    if( listsSize < 2 )
        return listsSize == 0 ? NULL : lists[0];

    struct ListNode*    tmpLists[listsSize];
    int tmpSize = 0;
    for( int i = 0; i < listsSize ; i ++ ){
        if( lists[i] )
            tmpLists[tmpSize++]     = lists[i];
    }

    if( tmpSize < 2 )
        return tmpSize == 0 ? NULL : tmpLists[0];
    else if( tmpSize == 2)
        return merge2List(tmpLists[0],tmpLists[1]);

#if 1
    int mid = tmpSize/2;
    return merge2List(mergeKLists(tmpLists,mid),mergeKLists(&tmpLists[mid],tmpSize - mid));
#endif

#if 0
    for( int i = 0; i < tmpSize)
    struct ListNode*    head = merge2List(tmpLists[0],tmpLists[1]);
    for( int i = 2; i < tmpSize ; i ++ )
        head = merge2List(head,tmpLists[i]);
    return head;
#endif

#if 0
    struct ListNode*    head = NULL;
    struct ListNode*    tail = NULL;

    while( tmpSize > 0 ){
        int min = 0;
        for( int i = 1; i < tmpSize ; i ++ ){
            if( tmpLists[i]->val < tmpLists[min]->val ){
                min=i;
            }
        }
    
        if( head == NULL ){
            head    = tmpLists[min];
            tail    = head;
        }
        else{
            tail->next   = tmpLists[min];
            tail    = tail->next;
        }
    
        if( tmpLists[min]->next == NULL ){
            if( min != tmpSize -1 )
                tmpLists[min]   = tmpLists[tmpSize -1];
        }
        else{
            tmpLists[min]   = tmpLists[min]->next;
        }
    }

    return head;
#endif
}


struct ListNode* genList(int *nums,int size){
    if( size == 0 )
    return NULL;
    struct ListNode*    head = malloc(sizeof(struct ListNode));
    head->val= nums[0];
    struct ListNode*    tail = head;
    for( int i = 1; i < size ; i ++ ){
        tail->next = malloc(sizeof(struct ListNode));
        tail->next->val= nums[i];
        tail = tail->next;
    }
    tail->next  = NULL;
    return head;
}

#define NODELIST(a)      genList(a,sizeof(a)/sizeof(int))
#define VERIFY(a)   mergeKLists(a,sizeof(a)/sizeof(void *))

int main()
{
    int a[]={},b[]={},c[]={2,6};
    struct ListNode *m[]    = {NODELIST(a),NODELIST(b),NODELIST(c)};
    void* i = VERIFY(m);
    printf("%d\n",i);
}
