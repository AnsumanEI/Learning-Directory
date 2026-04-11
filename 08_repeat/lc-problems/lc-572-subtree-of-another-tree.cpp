#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


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


bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    else if (p == nullptr || q == nullptr) return false;
    else if (p->val != q->val) return false;
    bool left  = isSameTree(p->left,  q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
}


// ============================================================
//  LeetCode #572 — Subtree of Another Tree
// ============================================================
//
//  PROBLEM:
//  Given roots of two trees root and subRoot, return true
//  if subRoot is a subtree of root (exists as an exact
//  subtree somewhere inside root).
//
// ------------------------------------------------------------
//  INTUITION:
//  For every node in root, check if the tree rooted there
//  is identical to subRoot using isSameTree.
//  Search left OR right — subRoot only needs to be on one side.
//
// ------------------------------------------------------------
//  APPROACH: Recursive DFS + isSameTree
//
//  STEP 1 (Base case):
//      If root is nullptr → return false (not found)
//
//  STEP 2 (Check current node):
//      If root->val == subRoot->val:
//          Call isSameTree(root, subRoot)
//          If true → return true immediately
//          If false → fall through and keep searching
//
//  STEP 3 (Search left and right):
//      bool left  = isSubtree(root->left,  subRoot)
//      bool right = isSubtree(root->right, subRoot)
//
//  STEP 4 (Combine):
//      Return left || right
//      (subRoot only needs to exist on ONE side)
//
// ------------------------------------------------------------
//  COMPLEXITY:
//      Time  : O(n * m) — for each of n nodes in root,
//              isSameTree runs up to m nodes of subRoot
//      Space : O(h) — call stack
// ------------------------------------------------------------
//  MISTAKES TO AVOID:
//  ❌ return true when isSameTree is false — keeps wrong result
//  ✅ only return true if isSameTree returns true
//  ❌ return left && right — both sides must match → wrong
//  ✅ return left || right — either side is enough
// ------------------------------------------------------------

bool isSubtree(TreeNode* root, TreeNode* subRoot) {
    if (root == nullptr) return false;
    if (root->val == subRoot->val) {
        if (isSameTree(root, subRoot)) return true;
    }
    bool left  = isSubtree(root->left,  subRoot);
    bool right = isSubtree(root->right, subRoot);
    return left || right;
}



int main() {
    cout << "=== LC #572 Subtree of Another Tree ===\n";

    // Input:  root = [3,4,5,1,2], subRoot = [4,1,2]
    // Output: true
    vector<int> vroot  = {3, 4, 5, 1, 2};
    vector<int> vsub   = {4, 1, 2};
    TreeNode* troot  = buildTree(vroot);
    TreeNode* tsub   = buildTree(vsub);
    cout << "Is Subtree (expect 1): " << isSubtree(troot, tsub) << "\n";

    // Input:  root = [3,4,5,1,2,null,null,null,null,0], subRoot = [4,1,2]
    // Output: false
    vector<int> vroot2 = {3, 4, 5, 1, 2, -1, -1, -1, -1, 0};
    vector<int> vsub2  = {4, 1, 2};
    TreeNode* troot2 = buildTree(vroot2);
    TreeNode* tsub2  = buildTree(vsub2);
    cout << "Is Subtree (expect 0): " << isSubtree(troot2, tsub2) << "\n";

    return 0;
}
