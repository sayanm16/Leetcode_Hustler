class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head == NULL)
            return NULL;

        if(head->next == NULL)
            return head;

        ListNode* tempHead = head;

        //swapping
        ListNode* temp = tempHead->next;
        tempHead->next = tempHead->next->next;
        temp->next = tempHead;
        //tempHead = tempHead->next;

        tempHead->next = swapPairs(tempHead->next);

        return temp;
    }
};
