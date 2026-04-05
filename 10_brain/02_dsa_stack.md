# 02 — DSA: Stack
> Patterns: Bracket Matching · Auxiliary Min Stack  
> Problems: LC #20, #155

---

## 🧠 The Big Idea

A stack is **Last In, First Out (LIFO)**. The last thing you put in is the first thing you take out.

**Analogy:** A stack of plates. You always take from the top. You always add to the top. You never reach into the middle.

### When does a stack help?
Whenever the problem has a **"most recent thing matters"** quality:
- Matching brackets → the most recent open bracket is the one that should close next
- Tracking minimum → the most recently pushed element carries the min at that moment

---

## STL Stack in C++

```cpp
stack<int> st;

st.push(x);      // add to top
st.pop();        // remove from top (returns nothing)
st.top();        // peek at top (does NOT remove)
st.empty();      // true if empty
st.size();       // number of elements
```

⚠️ **Golden rule:** Always check `st.empty()` before calling `st.top()` or `st.pop()`. Calling them on an empty stack = undefined behaviour = crash.

---

# PATTERN 1 — Bracket Matching

## The Core Idea

For every closing bracket you see, the **most recent unmatched open bracket** should be its pair.

That "most recent" part is exactly what a stack gives you.

**Analogy:** Reading a sentence with nested parentheses.  
`(a(b)c)` — when you hit the first `)`, it belongs to the `(` right before `b`, not the outer one. The inner one was pushed last, so it's on top of the stack.

---

## LC #20 — Valid Parentheses
**Given:** string of brackets `()[]{}` 
**Find:** is it valid? (every open bracket closed in correct order)

### The flow

```
s = "({[]})"

i=0: '(' → open bracket → push '('  → stack: ['(']
i=1: '{' → open bracket → push '{'  → stack: ['(', '{']
i=2: '[' → open bracket → push '['  → stack: ['(', '{', '[']
i=3: ']' → closing bracket
           top of stack = '[' → matches ']' → pop
                                              stack: ['(', '{']
i=4: '}' → closing bracket
           top of stack = '{' → matches '}' → pop
                                              stack: ['(']
i=5: ')' → closing bracket
           top of stack = '(' → matches ')' → pop
                                              stack: []
End: stack is empty → VALID ✅
```

```
s = "([)]"

i=0: '(' → push → stack: ['(']
i=1: '[' → push → stack: ['(', '[']
i=2: ')' → closing. top = '[' → does NOT match ')' → INVALID ❌
```

### The match map

You need to know: which open bracket does each closing bracket pair with?

```cpp
unordered_map<char,char> match;
match[')'] = '(';   // closing → expected open
match[']'] = '[';
match['}'] = '{';
```

⚠️ **Struggle:** Wrote `match[')'] = ')'` — value must be the **opposite** bracket, not the same one.

### Code

```cpp
bool isValid(string s) {
    stack<char> st;
    unordered_map<char,char> match;
    match[')'] = '(';
    match[']'] = '[';
    match['}'] = '{';

    for (char c : s) {
        if (c == '(' || c == '[' || c == '{') {
            st.push(c);
        } else {
            if (st.empty()) return false;        // closing with nothing open
            if (st.top() != match[c]) return false; // wrong pair
            st.pop();
        }
    }
    return st.empty(); // if anything left → unmatched open bracket
}
```

**TC:** O(n) · **SC:** O(n)

### Why `return st.empty()` at the end?
Consider `"((("` — you process all three, push all three, never return false inside the loop. But the stack isn't empty at the end → unmatched open brackets → invalid.

---

## Common mistakes on bracket matching

| Mistake | Why it fails | Fix |
|---|---|---|
| `match[')'] = ')'` | Value is the same bracket | Value must be the **open** version |
| Not checking `st.empty()` before `st.top()` | Crash on empty stack | Always check empty first |
| `return true` instead of `return st.empty()` | Misses unclosed brackets | Stack must be empty at end |

---

# PATTERN 2 — Stack with Auxiliary Data

## The Core Idea

Sometimes you need a stack that also answers extra questions in O(1) — like "what's the minimum element right now?"

The trick: **store the extra information alongside each element**.  
Instead of `stack<int>`, use `stack<pair<int,int>>` — store both the value AND the answer at that moment.

**Analogy:** Every time you add a plate to the stack, you write a sticky note on it saying "the lightest plate in the stack right now is X." When you remove that plate, the sticky note on the plate below still has the correct answer for that state.

---

## LC #155 — Min Stack
**Design a stack that supports:** `push`, `pop`, `top`, and `getMin` — all in O(1)

### Why not just scan for minimum?
Scanning is O(n). We need O(1). So we precompute the minimum **at every state** and store it.

### The flow

```
Operations: push(5), push(3), push(7), push(2), pop(), getMin()

push(5): current min = min(5, ∞) = 5  → store (5, 5)   stack: [(5,5)]
push(3): current min = min(3, 5) = 3  → store (3, 3)   stack: [(5,5),(3,3)]
push(7): current min = min(7, 3) = 3  → store (7, 3)   stack: [(5,5),(3,3),(7,3)]
push(2): current min = min(2, 3) = 2  → store (2, 2)   stack: [(5,5),(3,3),(7,3),(2,2)]
pop():   remove (2,2)                                   stack: [(5,5),(3,3),(7,3)]
getMin(): top().second = 3  ← correct! ✅
```

When you pop `(2,2)`, the minimum of the remaining stack is automatically revealed — it's stored in the new top's `.second`.

### Code

```cpp
class MinStack {
    stack<pair<int,int>> st; // {value, minAtThisPoint}
public:
    void push(int val) {
        int currentMin = st.empty() ? val : min(val, st.top().second);
        st.push({val, currentMin});
    }

    void pop() {
        st.pop();
    }

    int top() {
        return st.top().first;
    }

    int getMin() {
        return st.top().second;
    }
};
```

**TC:** O(1) for all operations · **SC:** O(n)

---

## Stack of Pairs — Syntax to memorise

This is where most mistakes happened. Know this cold:

```cpp
stack<pair<int,int>> st;

// Push a pair — use curly braces
st.push({value, minVal});      // ✅ correct
st.push.first(value);          // ❌ wrong — doesn't exist

// Access top
st.top().first    // ✅ value — first is a FIELD, no brackets
st.top().second   // ✅ min   — second is a FIELD, no brackets
st.top.first()    // ❌ wrong — top() needs brackets, first does not
st.top().second() // ❌ wrong — second is not a function
```

---

## ⚠️ All Stack Struggles (from real sessions)

| Mistake | What happened | Fix |
|---|---|---|
| `seen.count()` on a stack | `stack` has no `.count()`. Only maps/sets do | Use `st.empty()` and `st.top()` |
| Pushed `s[0]` before loop | First character processed twice | Start loop from index 0, don't pre-push |
| `match[')'] = ')'` | Wrong bracket in match map | Value must be the opposite bracket |
| `st.push.first(val)` | Wrong syntax | `st.push({val, min})` |
| `st.top().second()` | `second` is a field not a function | `st.top().second` — no brackets |
| `st.top.first()` | `top` is a function, `first` is not | `st.top().first` |
| `st.top()` on empty stack | Crash | Always `if (!st.empty())` first |

---

## 🔁 Quick Revision Cheatsheet

### The two stack patterns

| Pattern | When to use | Extra storage |
|---|---|---|
| Basic stack | "Most recent thing must match/be processed next" | `stack<char>` or `stack<int>` |
| Pair stack | "Need O(1) answer about the whole stack at any point" | `stack<pair<int,int>>` |

### Full STL syntax

```cpp
// Basic stack
stack<char> st;
st.push(c);
if (!st.empty()) {
    char top = st.top();
    st.pop();
}

// Pair stack
stack<pair<int,int>> st;
st.push({val, extraInfo});
st.top().first;    // val
st.top().second;   // extraInfo
```

### TC/SC

| Problem | TC | SC |
|---|---|---|
| LC #20 Valid Parentheses | O(n) | O(n) |
| LC #155 Min Stack | O(1) all ops | O(n) |

### The mental checklist before submitting any stack problem

```
□ Did I check st.empty() before st.top()?
□ Did I check st.empty() before st.pop()?
□ Does my match map have the RIGHT bracket as the value?
□ Did I return st.empty() at the end (not just return true)?
□ Am I using st.push({a,b}) not st.push.first()?
□ Is .second a field access (no brackets) not a function call?
```