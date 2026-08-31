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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int> cri;
        ListNode* temp = head;
        ListNode* prev = temp;
        int ind = 0;
        while(temp != NULL){
            if(temp == prev){
                temp = temp->next;
                ind++;
                continue;
            }
            if(temp->next == NULL){
                temp = temp->next;
                ind++;
                continue;
            }
            if(temp->val > prev->val && temp->val > temp->next->val){
                cri.push_back(ind);
            }
            else if(temp->val < prev->val && temp->val < temp->next->val){
                cri.push_back(ind);
            }
            prev = temp;
            temp = temp->next;
            ind++;
        }
        if(cri.empty() || cri.size() <= 1) return {-1, -1};
        // int mini = INT_MAX;
        // int maxi = INT_MIN;
        sort(cri.begin(), cri.end());
        int maxi = abs(cri[0] - cri[cri.size()-1]);
        int mini = INT_MAX;
        for(int i = 0; i < cri.size(); i++){
            if(i > 0){
                int diff = abs(cri[i] - cri[i -1]);
                mini = min(mini, diff);
            }
        }
        return {mini, maxi};

    }
};