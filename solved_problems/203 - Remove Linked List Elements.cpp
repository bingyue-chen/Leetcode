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
    ListNode* removeElements(ListNode* head, int val) {
        
        ListNode *current, *prev;
        
        while(head != NULL && head->val == val){
            head = head->next;
        }
        
        if(head != NULL){
            
            prev = head;
            current = head->next;
            
            while(current != NULL){
                if(current->val == val){
                    prev->next = current->next;
                    current = current->next;
                }
                else{
                    prev = current;
                    current = current->next;
                }
            }
            
        }
            
        return head;
    }
};