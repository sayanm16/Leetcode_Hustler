class Solution {
public:
    
    int lengthOfLinkedList(ListNode* head){
        int length = 0;
        ListNode* temp = head;
        while(temp != NULL){
            temp = temp->next;
            length++;
        }
        return length;
    }
    
    ListNode* reverseKGroup(ListNode* head, int k, int length){
        if(length < k){
            return head;
        }
        
        int count = 0;
        ListNode* prev = NULL, *nex = NULL, *curr = head;
        while(count < k && curr != NULL){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
            count++;
        }
        
        if(nex != NULL){
            head -> next = reverseKGroup(nex, k, length - k);
        }
        
        return prev;
        
    }
    
    ListNode* reverseKGroup(ListNode* head, int k) {
        int length = lengthOfLinkedList(head);
        return reverseKGroup(head, k, length);
    }
};

