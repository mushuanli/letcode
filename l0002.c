/* 题目: 
https://leetcode.cn/problems/add-two-numbers/
给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。

请你将两个数相加，并以相同形式返回一个表示和的链表。

你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
*/
/* 
题解: 
  遍历链表然后增加进位标志
*/
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2){
    if( l1 == NULL ){
        if( l2 == NULL ) 
            return NULL;
        l1 = l2;
        l2 = NULL;
    }

  struct ListNode *head = NULL;
  struct ListNode *next = NULL;
  int carry = 0;
  while( l1 != NULL || l2 != NULL ){
      if( l1 == NULL || l2 == NULL ){
          if( l1 == NULL ){
              l1 = l2;
              l2 = NULL;
          }
      }
    int sum = l1->val + carry;
    if( l2 )
        sum += l2->val;
    carry   = sum /10;
    l1->val  = sum % 10;
    if( next == NULL ){
        head    = l1;
        next    = head;
    }
    else{
        next->next = l1;
        next       = l1;
    }
    l1         = l1->next;
    if( l2 ) l2 = l2->next;
  }
  if( carry > 0 ){
      struct ListNode *item = (struct ListNode *)malloc(sizeof(struct ListNode));
      item->val  = carry;
      next->next = item;
      next       = item;
  }
  next->next     = NULL;
  return head;
}
