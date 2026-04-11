#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

// ============================================================
//  TREE NODE DEFINITION
// ============================================================
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// ============================================================
//  HELPER — Build tree from array (LeetCode style)
//  -1 = null node
// ============================================================
TreeNode* buildTree(vector<int>& vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (i < vals.size() && vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// ============================================================
//  HELPER — Print tree (level order)
// ============================================================
void printTree(TreeNode* root) {
    if (!root) { cout << "null\n"; return; }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else {
            cout << "null ";
        }
    }
    cout << "\n";
}


// ============================================================
//  LeetCode #104 — Maximum Depth of Binary Tree
// ============================================================
//
//  PROBLEM:
//  Given the root of a binary tree, return its maximum depth.
//  Maximum depth = number of nodes along the longest path
//  from root to a leaf node.
//
// ------------------------------------------------------------
//  INTUITION:
//  Depth of a tree = 1 + max(depth of left, depth of right)
//  A nullptr node contributes 0 — it is not a real node.
//
// ------------------------------------------------------------
//  APPROACH: Recursive Post-order
//
//  STEP 1 (Base case):
//      If root is nullptr → return 0
//
//  STEP 2 (Recurse):
//      Get depth of left subtree
//      Get depth of right subtree
//
//  STEP 3 (Combine):
//      Return max(left, right) + 1
//      (+1 for current node)
//
// ------------------------------------------------------------
//  COMPLEXITY:
//      Time  : O(n) — visit every node once
//      Space : O(h) — call stack depth = height of tree
// ------------------------------------------------------------
//  MISTAKES TO AVOID:
//  ❌ return 1 for nullptr — nullptr is not a node
//  ✅ return 0 for nullptr — correct base case
// ------------------------------------------------------------

int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;
    int left  = maxDepth(root->left);
    int right = maxDepth(root->right);
    return max(left, right) + 1;
}


// ============================================================
//  MAIN — Test LC #104
// ============================================================

int main() {
    // Input:  [3, 9, 20, -1, -1, 15, 7]
    // Output: 3
    cout << "=== LC #104 Max Depth ===\n";
    vector<int> v104 = {3, 9, 20, -1, -1, 15, 7};
    TreeNode* t104 = buildTree(v104);
    cout << "Tree: "; printTree(t104);
    cout << "Max Depth: " << maxDepth(t104) << "\n";
    return 0;
}
