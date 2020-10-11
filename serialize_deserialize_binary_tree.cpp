/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        
        if(root==nullptr) return "X,";
        string leftSubtree = serialize(root->left);
        string rightSubtree = serialize(root->right);
        return to_string(root->val) +"," + leftSubtree + rightSubtree;
        
        
    }
    
    std::vector<std::string> split(const std::string& s, char delimiter)
    {
       std::vector<std::string> tokens;
       std::string token;
       std::istringstream tokenStream(s);
       while (std::getline(tokenStream, token, delimiter))
       {
          tokens.push_back(token);
       }
       return tokens;
    } 
    
    TreeNode* deserializeHelper(std::queue<string>& nodes)
    {
        if(nodes.size()==0){
            return nullptr;
        }
        string element = nodes.front();
        nodes.pop();
        if(element=="X") return nullptr;
        TreeNode* currentNode = new TreeNode(stoi(element));
        currentNode->left = deserializeHelper(nodes);
        currentNode->right = deserializeHelper(nodes);
        return currentNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
        std::queue<string> nodes;
        std::cout<<"Print data: "<<data<<std::endl;
        data.erase(data.size()-1);
        std::vector<string> elements = split(data,',');
        for(auto x: elements)
        {
            nodes.push(x);
            
        }
        return deserializeHelper(nodes);
        
        
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));