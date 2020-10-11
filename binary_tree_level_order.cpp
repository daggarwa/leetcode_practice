/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        
        vector<vector<int>> result;
        if (root==nullptr)
            return result;
        
        std::queue<TreeNode*> processq;
        
        processq.push(root);
        
        while(!processq.empty())
        {
            int queue_size = processq.size();
            vector<int> current_level_nodes;
            
            for(int i =0;i<queue_size;i++)
            {
                TreeNode* current_node = processq.front();
                processq.pop();
                if(current_node->left!=nullptr)
                {
                    processq.push(current_node->left);
                }
                if(current_node->right!=nullptr)
                {
                    processq.push(current_node->right);
                }
                
                current_level_nodes.push_back(current_node->val);
                
            }
            
            result.push_back(current_level_nodes);
        }
    
        return result;
        
        
    }
};