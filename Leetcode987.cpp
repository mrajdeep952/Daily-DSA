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
        vector<vector<int>> verticalTraversal(TreeNode* root) {
            
            int hlevel = 0;
            int vlevel = 0;
            int temp = 0;
            map<int, map<int, multiset<int>>>mpp;
            vector<vector<int>>result;
    
            queue<pair<TreeNode*, pair<int, int>>>levels;
            // levelwise assigning the hlevel and vlevel
            levels.push({root, {0, 0}});
            while(!levels.empty()){
                int size = levels.size();
                for( int i = 0; i < size; i++ ){
                    auto element = levels.front();
                    TreeNode* node = levels.front().first;
                    levels.pop();
                    int vlevel = element.second.first;
                    int hlevel = element.second.second;
                    // cout << " hit " << endl;
    
                    if(node->left)
                    levels.push({node->left, {vlevel-1, hlevel+1}});
    
                    if(node->right)  
                    levels.push({node->right, {vlevel+1, hlevel+1}});
    
                    // assigning the value
                    mpp[vlevel][hlevel].insert(node->val);
                }
            }
            for(auto itr : mpp){
                vector<int>temp;
                for(auto it : itr.second){
                    for(auto i : it.second)
                    temp.push_back(i);
                }
                result.push_back(temp);
            }
            return result;
        }
    };