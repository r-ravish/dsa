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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head == NULL || head->next == NULL) return head;
        if(left == right) return head;

        ListNode* startPoint = head;
        ListNode* endPoint = head;
        ListNode* prevStart = head;

        for(int i=1; i<left-1; i++){
            prevStart = prevStart->next;
        }

        for(int i=1; i<left; i++){
            startPoint = startPoint->next;
        }
        for(int i=1; i<right; i++){
            endPoint = endPoint->next;
        }

        ListNode* prevNode = NULL;
        ListNode* curr = startPoint;
        ListNode* nextNode = NULL;


        while(prevNode != endPoint){
            nextNode=curr->next;

            curr->next = prevNode;
            prevNode = curr;
            curr=nextNode;
        }

        startPoint->next = curr;
        if(left == 1){
            head = endPoint;
        }else{
            prevStart->next = endPoint;
        }




        return head;


    }
};