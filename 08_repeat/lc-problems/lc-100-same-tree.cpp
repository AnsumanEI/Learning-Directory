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
//  LeetCode #100 — Same Tree
// ============================================================
//
//  PROBLEM:
//  Given roots of two binary trees p and q, return true
//  if they are structurally identical with same node values.
//
// ------------------------------------------------------------
//  INTUITION:
//  Two trees are the same if:
//    1. Both are empty (nullptr) → true
//    2. One is empty, other is not → false
//    3. Values differ at current node → false
//    4. Left subtrees are same AND right subtrees are same
//
// ------------------------------------------------------------
//  APPROACH: Recursive Pre-order
//
//  STEP 1 (Base cases — in order):
//      Both nullptr          → return true
//      One nullptr           → return false  (crash risk if skipped)
//      p->val != q->val      → return false
//
//  STEP 2 (Recurse):
//      Check left subtrees
//      Check right subtrees
//
//  STEP 3 (Combine):
//      Return left && right
//
// ------------------------------------------------------------
//  COMPLEXITY:
//      Time  : O(n) — visit every node once
//      Space : O(h) — call stack depth = height of tree
// ------------------------------------------------------------
//  MISTAKES TO AVOID:
//  ❌ p != q          — compares memory addresses, not values
//  ✅ p->val != q->val — correct value comparison
//  ❌ Null check after ->val access — causes crash
//  ✅ Null check must come FIRST
// ------------------------------------------------------------

bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    else if (p == nullptr || q == nullptr) return false;
    else if (p->val != q->val) return false;
    bool left  = isSameTree(p->left,  q->left);
    bool right = isSameTree(p->right, q->right);
    return left && right;
}




int main() {
    cout << "=== LC #100 Same Tree ===\n";

    // Input:  p = [1,2,3], q = [1,2,3]
    // Output: true
    vector<int> vp = {1, 2, 3};
    vector<int> vq = {1, 2, 3};
    TreeNode* tp = buildTree(vp);
    TreeNode* tq = buildTree(vq);
    cout << "Same Tree (expect 1): " << isSameTree(tp, tq) << "\n";

    // Input:  p = [1,2], q = [1,null,2]
    // Output: false
    vector<int> vp2 = {1, 2};
    vector<int> vq2 = {1, -1, 2};
    TreeNode* tp2 = buildTree(vp2);
    TreeNode* tq2 = buildTree(vq2);
    cout << "Same Tree (expect 0): " << isSameTree(tp2, tq2) << "\n";

    return 0;
}
