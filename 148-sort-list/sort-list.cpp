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
    ListNode* merge(ListNode* left, ListNode* right){
        ListNode* tail = new ListNode();
        ListNode* dummy = tail;

        while(left != NULL && right != NULL){
            if(left->val <= right->val){
                tail->next = left;
                left = left->next;
            }else{
                tail->next=right;
                right = right->next;
            }

            tail = tail->next;
        }

        while(left != NULL){
            tail->next = left;
            tail=tail->next;
            left = left->next;
        }

        while(right != NULL){
            tail->next = right;
            tail=tail->next;
            right = right->next;
        }

        return dummy->next;
    }

    ListNode* findMiddle(ListNode* head){
        ListNode* mid = head;
        ListNode* fast = head->next;
        while(fast != NULL && fast->next != NULL){
            mid = mid->next;
            fast = fast->next->next;
        }

        return mid;
    }

    ListNode* mergeSort(ListNode* head){
        if(head == NULL || head->next == NULL) return head;

        ListNode* middle = findMiddle(head);

        ListNode* leftHead = head;
        ListNode* rightHead = middle->next;
        middle->next = NULL;

        leftHead = mergeSort(leftHead);
        rightHead = mergeSort(rightHead);

        return merge(leftHead, rightHead);
    }

    ListNode* sortList(ListNode* head) {
        return mergeSort(head);
    }
};