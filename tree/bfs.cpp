#include "includes.h"

using namespace std;

typedef struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
} TreeNode;

vector<TreeNode *> bfsIterative(TreeNode* root) {
    queue<TreeNode *> q;
    if (!root) {
        return ;
    }
    
    q.push(root);

    vector<TreeNode *> retval;

    while (!q.empty()) {
        TreeNode * node = q.front();
        q.pop();

        retval.push_back(node);

        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);

    }

    return retval;

}

