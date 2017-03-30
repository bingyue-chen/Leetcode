/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1 == NULL && l2 == NULL) return NULL;
        ListNode *ans, *last, *current;
        ans = last = NULL;
        while(!(l1 == NULL && l2 == NULL)){
            if(l1 == NULL){
                current = l2;
                l2 = l2->next;
            }
            else if(l2 == NULL || l1->val <= l2->val){
                current = l1;
                l1 = l1->next;
            }
            else {
                current = l2;
                l2 = l2->next;
            }
            
            if(ans == NULL){
                ans = current;
            }else{
                last->next = current;
            }
            
            last = current;
        }
        return ans;
    }
};