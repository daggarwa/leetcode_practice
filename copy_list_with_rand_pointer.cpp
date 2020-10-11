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
             
        
        Node* current= head;        
        Node * current_copy = nullptr;
        Node * head_copy = nullptr;
        
        if(head==nullptr)
            return nullptr;
        
        // create clone node for every node in original list
        while(current!=nullptr)
        {
            current_copy = new Node(current->val);
            current_copy->next = current->next;
            current->next = current_copy;
            current = current_copy->next;                       
            
        }
        
        current = head;
        
        //assign random ptrs from original to clone nodes
        while(current!=nullptr)
        {   
            current_copy = current->next;
            if(current->random)
                current_copy->random = current->random->next;
            current = current_copy->next;
            
        }
        
        
        current = head;
        head_copy = head->next;
        
        while(current!=nullptr)
        {
            current_copy = current->next;
            Node* next_original_after_copy = current_copy->next;
            current->next = next_original_after_copy;
            if(next_original_after_copy)
                current_copy->next = next_original_after_copy->next;
            current = current->next;
            
        }
        
        return head_copy;       
        
        
        
        
    }
};