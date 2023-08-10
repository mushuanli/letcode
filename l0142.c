#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * a代表链表头节点到环的入口节点的节点数
b代表环的入口节点到fast和slow第一次相遇的节点的节点数
c代表第一次相遇节点到环的入口节点的节点数

此时，fast走过的节点数为 a+b+n(c+b) ，n表示fast在环中绕的圈数
slow走过的节点数为 a+b
fast和slow是一同移动的，所以任意时刻他们的移动步数是相同的，但是fast每次移动2个节点，相同的步数下，fast移动的节点数应该是slow的2倍
所以 a+b+n(c+b) = 2(a+b)
整理等式得：a=n(b+c)-b = nb+nc-b = (n-1)b+nc = (n-1)b+(n-1)c+c=(n-1)(b+c)+c
得 a = (n-1)(b+c)+c
*/
 struct ListNode {
      int val;
      struct ListNode *next;
  };

struct ListNode *detectCycle(struct ListNode *head) {
    struct ListNode* fast = head;
    struct ListNode* slow = head;
    while( fast && fast->next ){
        slow = slow->next;
        fast = fast->next->next;
        if( slow == fast )
          break;
    }

    if( fast && fast->next ){
       slow = head;
       while( slow != fast ){
        slow = slow->next;
        fast = fast->next;
       } 
       return slow;
    }

    return NULL;
}
