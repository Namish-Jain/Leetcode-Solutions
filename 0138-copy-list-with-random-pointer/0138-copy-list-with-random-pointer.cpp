/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> hashMap;

        Node* temp = head;
        while(temp) {
            hashMap[temp] = new Node(temp->val);
            temp = temp->next;
        }

        temp = head;
        while(temp) {
            Node* node = hashMap[temp];
            node->next = hashMap[temp->next];
            node->random = hashMap[temp->random];
            temp = temp->next;
        }

        return hashMap[head];
    }
};