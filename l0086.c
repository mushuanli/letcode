/** https://leetcode.cn/problems/partition-list/discussion/
86. 分隔链表
中等
670
相关企业
给你一个链表的头节点 head 和一个特定值 x ，请你对链表进行分隔，使得所有 小于 x 的节点都出现在 大于或等于 x 的节点之前。

你应当 保留 两个分区中每个节点的初始相对位置。

解决： 分两个数组就完了
*/
struct ListNode* partition(struct ListNode* head, int x){
    if( !head || !head->next ) return head;

    struct ListNode* bHead = NULL;
    struct ListNode* bNext = NULL;

    struct ListNode* lHead = NULL;
    struct ListNode* lNext = NULL;

    for(struct ListNode* p = head; p ; p = p->next ){
        if( p->val >= x){
            if( !bHead ){
                bHead=p;
                bNext=p;
            }
            else{
                bNext->next=p;
                bNext = p;
            }
        }
        else{
            if( !lHead ){
                lHead=p;
                lNext=p;
            }
            else{
                lNext->next=p;
                lNext   = p;
            }
        }
    }

    if( bNext )bNext->next = NULL;
    if( lNext )lNext->next = NULL;

    if( lNext ) lNext->next = bHead;

    return lHead ? lHead : bHead;
}
