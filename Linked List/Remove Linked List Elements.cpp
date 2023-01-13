/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        while(head!=NULL && head->val==val) head=head->next;
        if(head==NULL) return head;
        ListNode* newHead=head;
        while(newHead->next!=NULL){
            if(newHead->next->val==val) newHead->next=newHead->next->next;
            else newHead=newHead->next;
        }
        return head;
    }
};
//Another approach using recurssion :)
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head==NULL) return NULL;
        head->next=removeElements(head->next,val);
        if(head->val==val) return head->next;
        else return head;
    }
};
