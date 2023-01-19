/** 题目: https://leetcode.cn/problems/remove-duplicates-from-sorted-list-ii/submissions/396342156/
82. 删除排序链表中的重复元素 II
中等
1K
相关企业
给定一个已排序的链表的头 head ， 删除原始链表中所有重复数字的节点，只留下不同的数字 。返回 已排序的链表 。
*/
/**
   解题： 
   1. 判断 head 是否是重复元素，如果是移动head指针
   2. 判断 p->next 开始是否是重复元素，如果是那么跳过这些
*/
struct ListNode* isDup(struct ListNode* p){
    if( !p || !p->next )
        return NULL;
    else if( p->val != p->next->val )
        return NULL;

    struct ListNode* tmp = p->next;
    while( tmp && tmp->val == p->val )  
        if(tmp->next )
            tmp = tmp->next;
        else
            break;

    return tmp;
}

struct ListNode* deleteDuplicates(struct ListNode* head){
    if( !head || !head->next ) return head;

    struct ListNode* p;
    while(1){
        p = isDup(head);
        if( !p )
            break;
        head    = p->val == head->val ? p->next : p;
    }

    p = head;
    while( p && p->next ){
    struct ListNode* tmp = isDup(p->next);
    if( tmp )
        p->next = tmp->val == p->next->val ? tmp->next : tmp;
    else
        p = p->next;
    }

  return head;
}
