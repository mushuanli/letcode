
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
