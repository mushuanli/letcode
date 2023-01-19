/** 题目: https://leetcode.cn/problems/remove-duplicates-from-sorted-list/description/
给定一个已排序的链表的头 head ， 删除所有重复的元素，使每个元素只出现一次 。返回 已排序的链表 。
*/
/* 简单的判断： 如果后一个节点和当前节点重复，那么跳过 */
struct ListNode* deleteDuplicates(struct ListNode* head){
    struct ListNode* p = head;
    while( p && p->next){
        if( p->val == p->next->val )
            p->next = p->next->next;
        else
            p = p->next;
    }
    return head;
}
