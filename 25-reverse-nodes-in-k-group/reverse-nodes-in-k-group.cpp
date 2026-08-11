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
    ListNode* findkthNode(ListNode* curr, int k){
        int count=1;
        while(curr != NULL){
            if(count == k){
                return curr;
            }
            count++;
            curr=curr->next;
        }

        return NULL;
    }

    ListNode* reverseLL(ListNode* head){
        ListNode* curr = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;

        while(curr != NULL){
            nextNode = curr->next;
            curr->next = prevNode;
            prevNode = curr;
            curr=nextNode;
        }

        return prevNode;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* temp = head;
        ListNode* nextNode = NULL;
        ListNode* prevNode = NULL;
        while(temp != NULL){
            ListNode* kthNode = findkthNode(temp, k);
            if(kthNode == NULL){
                if(prevNode){
                    prevNode->next = temp;
                }
                break;
            }
            nextNode = kthNode->next;
            kthNode->next = NULL;
            reverseLL(temp);

            if(temp == head){
                head = kthNode;
            }else{
                prevNode->next = kthNode;
            }

            prevNode = temp;
            temp = nextNode;

        }

        return head;
    }
};