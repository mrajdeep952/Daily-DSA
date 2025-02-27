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
        bool isEvenOddTree(TreeNode* root) {
            
            if(root->val % 2 == 0) return false;
            queue<TreeNode*>treeLevel;
            treeLevel.push(root);
            int levelIndex = 0;
    
            while(treeLevel.empty() != 1){
                int prev = 0;
                int size = treeLevel.size();
                for( int i = 0; i < size; i++ ){
                    TreeNode* node = treeLevel.front();
                    treeLevel.pop();
                    
                    // for current even level next level values must be even
                    if(levelIndex % 2 == 0){
                        if(node->left){
                            if(node->left->val % 2 != 0 || (prev != 0 && node->left->val >= prev)){
                                // cout << "false even left" << levelIndex << " " << node->left->val << " " << prev << endl;
                                return false;
                            }
                            treeLevel.push(node->left);
                            prev = node->left->val;
                        }
                        if(node->right){
                            if(node->right->val % 2 != 0 || (prev != 0 && node->right->val >= prev)){
                                // cout << "false even right" << levelIndex << "  " << node->right->val << " " << prev << endl;
                                return false;
                            }
                            treeLevel.push(node->right);
                            prev = node->right->val;
                        }
                    }
                    // for current odd level next level values must be odd
                    else{
                        if(node->left){
                            if(node->left->val % 2 == 0 || (prev != 0 && node->left->val <= prev)){
                                // cout << "false odd left" << levelIndex << " " << node->left->val << " " << prev << endl;
                                return false;
                            }
                            treeLevel.push(node->left);
                            prev = node->left->val;
                        }
                        if(node->right){
                            if(node->right->val % 2 == 0 || (prev != 0 && node->right->val <= prev)){
                                // cout << "false odd right" << levelIndex << " " << node->right->val << " " << prev << endl;
                                return false;
                            }
                            treeLevel.push(node->right);
                            prev = node->right->val;
                        }
                    }
                }
                levelIndex++;
            }
            return true;
        }
    };