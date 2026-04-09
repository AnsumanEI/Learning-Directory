
// ============================================================
//  LeetCode #226 — Invert Binary Tree
// ============================================================
//
//  PROBLEM:
//  Given the root of a binary tree, invert it (mirror it)
//  and return the root.
//
// ------------------------------------------------------------
//  INTUITION:
//  At every node, swap left and right children.
//  Do this recursively bottom-up — invert subtrees first,
//  then swap at current node.
//
// ------------------------------------------------------------
//  APPROACH: Recursive Post-order
//
//  STEP 1 (Base case):
//      If root is nullptr → return nullptr (nothing to invert)
//
//  STEP 2 (Recurse):
//      Invert left subtree → store result
//      Invert right subtree → store result
//
//  STEP 3 (Swap):
//      root->left  = inverted right
//      root->right = inverted left
//
//  STEP 4 (Return):
//      Return root
//
// ------------------------------------------------------------
//  COMPLEXITY:
//      Time  : O(n) — visit every node once
//      Space : O(h) — call stack depth = height of tree
// ------------------------------------------------------------
//  MISTAKES TO AVOID:
//  ❌ invertTree(left) — wrong, left is a local var not a node
//  ✅ invertTree(root->left) — correct, pass the pointer
// ------------------------------------------------------------
