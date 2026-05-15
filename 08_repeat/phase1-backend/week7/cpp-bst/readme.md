# C++ Binary Search Tree (BST)

A full BST implementation in C++ split across 3 files.
Covers insert, delete, search, traversals, height, and LCA.

---

## File Structure

```
bst.h        — Node struct + BST class declaration (the blueprint)
bst.cpp      — BST class implementation (the actual logic)
main.cpp     — Creates a BST, runs all operations, prints results
```

---

## Why 3 files?

This is standard C++ project structure. Think of it like this:

- `bst.h` = the **menu** (what operations exist)
- `bst.cpp` = the **kitchen** (how each operation works)
- `main.cpp` = the **customer** (uses the operations)

`main.cpp` includes `bst.h` to know what's available. It doesn't need to know how it works — just that it works.

---

## `#pragma once` — what is it?

At the top of `bst.h`:

```cpp
#pragma once
```

This tells the compiler: **include this file only once**, even if multiple files include it.

Without it, if two files both include `bst.h`, the compiler sees the Node struct twice and throws a redefinition error. `#pragma once` prevents that.

---

## The Node Struct

```cpp
struct Node {
    int Value;
    Node* LeftNode;
    Node* RightNode;
};
```

Each node holds a value and two pointers — left child and right child.
Pointers start as `nullptr` (nothing attached yet).

Three constructors are defined:

- `Node()` — empty node, both children null
- `Node(int Value)` — node with a value, children null
- `Node(int Value, Node* left, Node* right)` — node with value and children

**Why `this->Value = Value`?**
When the parameter name is the same as the member name, `this->` tells the compiler
"I mean the member variable, not the parameter." Without it, you'd be assigning Value to itself.

---

## The BST Class — Public vs Private

```cpp
class BST {
private:
    Node* root;
    Node* insert(Node* root, int val);   // recursive helper

public:
    void insert(int val);                // what main.cpp calls
};
```

**Why two versions of every function?**

This is called the **public wrapper / private recursive helper** pattern.

- `main.cpp` calls `tree1.insert(5)` — clean, simple, no need to pass root
- Internally, `insert(int val)` calls `insert(root, val)` — the recursive version that does the actual work

The user never sees the recursion. This is encapsulation — hide complexity, expose simplicity.

---

## How Insert Works

```cpp
Node* BST::insert(Node* root, int val) {
    if (root == nullptr) return new Node(val);   // empty spot found — place node here
    if (val < root->Value)
        root->LeftNode = insert(root->LeftNode, val);  // go left
    else
        root->RightNode = insert(root->RightNode, val); // go right
    return root;
}
```

BST rule: left < root < right. Every insert follows this rule recursively.

The public wrapper:

```cpp
void BST::insert(int value) {
    root = insert(root, value);  // root gets updated and returned back up
}
```

Why `root = insert(root, value)`? Because if tree is empty, insert returns a new Node.
We need to capture that and assign it as root.

---

## How Delete Works — 3 Cases

Deletion is the hardest BST operation. Three cases:

**Case 1 — Leaf node (no children):**
Just remove it. Return nullptr.

**Case 2 — One child:**
Replace the node with its only child. Return that child.

**Case 3 — Two children (the hard case):**
Find the **inorder successor** — smallest node in the right subtree.
Copy its value into current node. Delete the successor from right subtree.

```cpp
Node* inorderSuccessor = minNode(root->RightNode);
root->Value = inorderSuccessor->Value;
root->RightNode = del(root->RightNode, inorderSuccessor->Value);
```

Why inorder successor? Because it's the next largest value — it can safely replace
the deleted node and maintain BST property.

`minNode()` finds it by going left until there's no more left child.

---

## Traversals — 3 Types

All traversals visit every node. The difference is **when you process the current node**.

```
Tree:      5
          / \
         3   8
        / \ / \
       2  4 6  9
```

**Inorder (Left → Root → Right):** 2 3 4 5 6 8 9
Always gives sorted order for a BST.

**Preorder (Root → Left → Right):** 5 3 2 4 8 6 9
Useful for copying/serializing a tree.

**Postorder (Left → Right → Root):** 2 4 3 6 9 8 5
Useful for deleting a tree (children before parent).

Each traversal passes a `vector<int>& res` by reference — results accumulate as recursion unwinds.

---

## Height

```cpp
int BST::height(Node* root) {
    if (root == nullptr) return 0;
    int left = height(root->LeftNode);
    int right = height(root->RightNode);
    return max(left, right) + 1;
}
```

Height = longest path from root to a leaf.
At each node: take the taller subtree, add 1 for current node.
Base case: nullptr has height 0.

---

## LCA — Lowest Common Ancestor

LCA of two nodes p and q = the deepest node that is an ancestor of both.

BST makes this easy — use the BST property:

```cpp
if (p < root->Value && q < root->Value)  → both in left subtree, go left
if (p > root->Value && q > root->Value)  → both in right subtree, go right
else                                      → root is the split point = LCA
```

The "split point" means one value is on each side of root — so root must be their common ancestor.

---

## How to Compile and Run

```bash
g++ -std=c++17 main.cpp bst.cpp -o bst
./bst
```

Note: compile **both** `main.cpp` and `bst.cpp` together. The header `bst.h` is included automatically.

---

## Key Concepts to Revise

| Concept                                   | Where it appears                  |
| ----------------------------------------- | --------------------------------- |
| `#pragma once`                            | bst.h — prevents double inclusion |
| Public wrapper + private recursive helper | Every BST method                  |
| `this->` keyword                          | Node constructors                 |
| Pass by reference `vector<int>& res`      | All traversals                    |
| Inorder successor                         | Delete case 3                     |
| `root = insert(root, val)` pattern        | Insert + Delete public wrappers   |
| `new Node(val)`                           | Creates node on heap              |

---

## What You Built

A production-style C++ BST with:

- Full insert / delete / search
- All 3 traversals
- Height calculation
- LCA for BST

Split cleanly across header, implementation, and main — the standard way real C++ projects are structured.
