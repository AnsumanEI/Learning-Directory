# 04 — DSA: Trees
> Patterns: Tree Recursion · BFS Level Order · BST Properties  
> Problems: LC #226, #104, #100, #572 (coming Mon Apr 6 & Wed Apr 8)  
> Status: 🔜 In progress — first session Mon Apr 6

---

## 🧠 The Big Idea

A tree is a **recursive structure**. Every node is the root of its own smaller tree.

This is the most important thing to understand about trees:

> **Any problem on a tree can be solved by solving the same problem on the left subtree and the right subtree, then combining the results.**

**Analogy:** You're a manager. You want to know the total headcount of your organisation. You don't count everyone yourself. You ask your two direct reports — they each ask their reports — all the way down to individual contributors who say "just me, 1 person." The answer bubbles back up. That's tree recursion.

---

## The Node Structure

Every tree problem in C++ starts here:

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

- `val` → the data at this node
- `left` → pointer to left child (nullptr if none)
- `right` → pointer to right child (nullptr if none)

---

## The Base Case — Always

Every recursive tree function needs a base case:

```cpp
if (root == nullptr) return ...; // what to return depends on the problem
```

- For counting → `return 0`
- For checking existence → `return true` or `return false`
- For returning a node → `return nullptr`

**If you forget the base case → infinite recursion → stack overflow.**

---

## The 3 Traversal Orders

How you visit nodes determines what you can solve:

```
        1
       / \
      2   3
     / \
    4   5
```

| Order | Pattern | Visits |
|---|---|---|
| Inorder | Left → Root → Right | 4, 2, 5, 1, 3 |
| Preorder | Root → Left → Right | 1, 2, 4, 5, 3 |
| Postorder | Left → Right → Root | 4, 5, 2, 3, 1 |

**Key fact:** Inorder traversal of a BST gives a **sorted sequence**. Always.

---

# PATTERN 1 — Tree Recursion (DFS)

## LC #226 — Invert Binary Tree
**Given:** root of a binary tree  
**Do:** flip the tree — every left child becomes right, every right becomes left

### The insight

To invert a tree rooted at `root`:
1. Invert the left subtree
2. Invert the right subtree
3. Swap left and right children of root

That's it. The recursion handles the rest.

### The flow

```
Original:          After invert:
     4                  4
    / \                / \
   2   7              7   2
  / \ / \            / \ / \
 1  3 6  9          9  6 3  1

Step 1: invert(root=4)
  → invert(left=2) → returns inverted subtree with 2 at root (1↔3 swapped)
  → invert(right=7) → returns inverted subtree with 7 at root (6↔9 swapped)
  → swap root->left and root->right
  → done
```

### Code

```cpp
TreeNode* invertTree(TreeNode* root) {
    if (root == nullptr) return nullptr;  // base case

    // recursively invert both subtrees
    invertTree(root->left);
    invertTree(root->right);

    // swap children
    swap(root->left, root->right);

    return root;
}
```

**TC:** O(n) — visit every node once · **SC:** O(h) — h = height of tree, recursion stack

---

## LC #104 — Maximum Depth of Binary Tree
**Given:** root  
**Find:** number of nodes along the longest path from root to a leaf

### The insight

The depth of a tree rooted at `root` =  
`1 + max(depth of left subtree, depth of right subtree)`

Base case: empty tree has depth 0.

### The flow

```
        3
       / \
      9  20
         / \
        15   7

depth(3):
  depth(9):
    depth(null) = 0
    depth(null) = 0
    return 1 + max(0,0) = 1
  depth(20):
    depth(15):
      return 1 + max(0,0) = 1
    depth(7):
      return 1 + max(0,0) = 1
    return 1 + max(1,1) = 2
  return 1 + max(1,2) = 3 ✅
```

### Code

```cpp
int maxDepth(TreeNode* root) {
    if (root == nullptr) return 0;  // base case

    int leftDepth  = maxDepth(root->left);
    int rightDepth = maxDepth(root->right);

    return 1 + max(leftDepth, rightDepth);
}
```

**TC:** O(n) · **SC:** O(h)

---

## LC #100 — Same Tree
**Given:** roots of two trees p and q  
**Find:** are they identical? (same structure AND same values)

### The insight

Two trees are the same if:
1. Both are null → true (both empty, identical)
2. One is null, other isn't → false (different structure)
3. Values differ → false
4. Otherwise → recursively check left and right subtrees

### The flow

```
p:   1        q:   1
    / \            / \
   2   3          2   3

isSameTree(1,1):
  both not null, vals equal (1==1)
  → isSameTree(2,2):
      both not null, vals equal
      → isSameTree(null,null) = true
      → isSameTree(null,null) = true
      return true
  → isSameTree(3,3):
      return true
  return true ✅
```

### Code

```cpp
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;   // both empty
    if (p == nullptr || q == nullptr) return false;  // one empty
    if (p->val != q->val) return false;              // different values

    return isSameTree(p->left, q->left) &&
           isSameTree(p->right, q->right);
}
```

**TC:** O(n) · **SC:** O(h)

---

## LC #572 — Subtree of Another Tree
**Given:** roots of tree s and tree t  
**Find:** does t appear as a subtree somewhere in s?

### The insight

At every node in s, ask: is the tree rooted here identical to t?  
Use `isSameTree` from LC #100 as a helper.

### The flow

```
s:       3          t:  4
        / \            / \
       4   5          1   2
      / \
     1   2

Check node 3: isSameTree(s=3, t=4)? No
Check node 4: isSameTree(s=4, t=4)? Yes ✅
```

### Code

```cpp
bool isSubtree(TreeNode* s, TreeNode* t) {
    if (s == nullptr) return false;       // ran out of nodes in s
    if (isSameTree(s, t)) return true;    // found it here

    // check left and right subtrees of s
    return isSubtree(s->left, t) || isSubtree(s->right, t);
}

// reuse isSameTree from LC #100
bool isSameTree(TreeNode* p, TreeNode* q) {
    if (p == nullptr && q == nullptr) return true;
    if (p == nullptr || q == nullptr) return false;
    if (p->val != q->val) return false;
    return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
}
```

**TC:** O(n·m) where n = size of s, m = size of t · **SC:** O(h)

---

# PATTERN 2 — BFS (Level Order)

## The Core Idea

DFS goes **deep** — all the way down one branch before another.  
BFS goes **wide** — processes all nodes at one level before going deeper.

**Tool:** A queue (FIFO — first in, first out). You enqueue a node, then enqueue its children. By the time you process them, all nodes at the current level are done.

**Analogy:** Flooding. Water spreads level by level — it doesn't rush down one path first.

```cpp
// BFS template
queue<TreeNode*> q;
q.push(root);

while (!q.empty()) {
    int levelSize = q.size();  // nodes at current level

    for (int i = 0; i < levelSize; i++) {
        TreeNode* node = q.front();
        q.pop();

        // process node here

        if (node->left)  q.push(node->left);
        if (node->right) q.push(node->right);
    }
}
```

---

## 🔁 Quick Revision Cheatsheet

### Which traversal for which problem?

| Problem type | Use |
|---|---|
| Process children before returning to parent | Postorder DFS |
| Process parent before children | Preorder DFS |
| Level-by-level processing | BFS with queue |
| BST sorted order | Inorder DFS |

### Recursion template for any tree problem

```cpp
ReturnType solve(TreeNode* root) {
    // 1. Base case
    if (root == nullptr) return BASE_VALUE;

    // 2. Recurse on children
    auto leftResult  = solve(root->left);
    auto rightResult = solve(root->right);

    // 3. Combine and return
    return combine(root->val, leftResult, rightResult);
}
```

### The 3 questions to ask before writing any tree function

```
1. What is my base case? (what do I return for nullptr?)
2. What do I need from my left child?
3. What do I need from my right child?
4. How do I combine them with my own value?
```

### TC/SC

| Problem | TC | SC |
|---|---|---|
| LC #226 Invert BT | O(n) | O(h) |
| LC #104 Max Depth | O(n) | O(h) |
| LC #100 Same Tree | O(n) | O(h) |
| LC #572 Subtree | O(n·m) | O(h) |

Where h = height of tree. For balanced tree h = O(log n). For skewed tree h = O(n).

### Node struct — write this from memory

```cpp
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
```

---

## 📌 Note
> Trees are being learned starting Mon Apr 6.  
> This file will be updated after each tree session.  
> Come back and fill in your struggles after the session.