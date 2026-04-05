# 01 — DSA: Arrays & HashMaps
> Patterns: HashMap · Sliding Window · Prefix/Suffix  
> Problems: LC #1, #121, #217, #242, #49, #347, #238, #3, #239

---

## 🧠 The Big Idea

Most array problems boil down to one question:

> **"How do I avoid checking every pair/subarray and still get the answer?"**

The answer is always: **store something smart as you go.**

- HashMap stores what you've **seen**
- Sliding window tracks what's in a **window**
- Prefix array stores what came **before**

---

# PATTERN 1 — HashMap

## The Core Idea

Instead of nested loops (O(n²)), you trade space for speed.  
You scan once, storing values in a map. When you need to look something up — it's O(1).

**Analogy:** Checking if you've met someone before.  
Bad way → go through every person you've ever met one by one.  
Smart way → check your contacts list instantly.

---

## LC #1 — Two Sum
**Given:** array of numbers, a target  
**Find:** indices of two numbers that add up to target

### The flow

```
nums = [2, 7, 11, 15], target = 9

i=0: num=2. Need 9-2=7. Is 7 in map? No. Store {2:0}
i=1: num=7. Need 9-7=2. Is 2 in map? YES → return [map[2], 1] = [0, 1]
```

### Why this works
At every step you ask: **"what number do I need to complete the pair?"**  
If that number was seen before, it's in the map. Done.

### Code
```cpp
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int,int> seen; // value → index
    for (int i = 0; i < nums.size(); i++) {
        int need = target - nums[i];
        if (seen.count(need)) return {seen[need], i};
        seen[nums[i]] = i;
    }
    return {};
}
```

**TC:** O(n) · **SC:** O(n)

---

## LC #217 — Contains Duplicate
**Given:** array  
**Find:** does any value appear more than once?

### The flow
```
nums = [1, 2, 3, 1]

Scan and insert into unordered_set.
When you try to insert 1 the second time → it's already there → return true.
```

### Code
```cpp
bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> seen;
    for (int n : nums) {
        if (seen.count(n)) return true;
        seen.insert(n);
    }
    return false; // ← don't forget this
}
```

**TC:** O(n) · **SC:** O(n)

⚠️ **Struggle:** Forgot `return false` at the end. Always close your function.

---

## LC #242 — Valid Anagram
**Given:** two strings s and t  
**Find:** is t a rearrangement of s?

### The flow
```
s = "anagram", t = "nagaram"

Count frequency of each char in s → {a:3, n:1, g:1, r:1, m:1}
For each char in t → decrement count
If any count goes negative → not an anagram
```

### Code
```cpp
bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    unordered_map<char,int> freq;
    for (char c : s) freq[c]++;
    for (char c : t) {
        freq[c]--;
        if (freq[c] < 0) return false;
    }
    return true;
}
```

**TC:** O(n) · **SC:** O(1) — only 26 letters max

---

## LC #49 — Group Anagrams
**Given:** array of strings  
**Find:** group strings that are anagrams of each other

### The key insight
Two strings are anagrams if and only if their **sorted versions are identical**.  
`"eat"` sorted → `"aet"`. `"tea"` sorted → `"aet"`. Same key → same group.

### The flow
```
words = ["eat","tea","tan","ate","nat","bat"]

"eat" → sort → "aet" → map["aet"] = ["eat"]
"tea" → sort → "aet" → map["aet"] = ["eat","tea"]
"tan" → sort → "ant" → map["ant"] = ["tan"]
"ate" → sort → "aet" → map["aet"] = ["eat","tea","ate"]
...
```

### Code
```cpp
vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> map;
    for (string& w : strs) {
        string key = w;
        sort(key.begin(), key.end());
        map[key].push_back(w);
    }
    vector<vector<string>> result;
    for (auto& p : map) result.push_back(p.second);
    return result;
}
```

**TC:** O(n · m log m) where m = avg word length · **SC:** O(n·m)

---

## LC #347 — Top K Frequent Elements
**Given:** array, integer k  
**Find:** k most frequent elements

### The flow
```
nums = [1,1,1,2,2,3], k = 2

Step 1: Count frequency → {1:3, 2:2, 3:1}
Step 2: Min-heap of size k. Push (freq, num).
        If heap size > k → pop the smallest frequency.
        At the end, heap has the k most frequent.
```

### Why min-heap?
You want to keep the k **largest** frequencies. A min-heap lets you quickly throw out the smallest one when the heap overflows k.

### Code
```cpp
vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int,int> freq;
    for (int n : nums) freq[n]++;

    // min-heap: pair<frequency, number>
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;
    for (auto& p : freq) {
        pq.push({p.second, p.first});
        if (pq.size() > k) pq.pop();
    }

    vector<int> result;
    while (!pq.empty()) {
        result.push_back(pq.top().second);
        pq.pop();
    }
    return result;
}
```

**TC:** O(n log k) · **SC:** O(n)

---

# PATTERN 2 — Sliding Window

## The Core Idea

When you need the best/longest/shortest **subarray or substring**, don't check all O(n²) subarrays. Use two pointers that define a **window** and slide it across.

**Analogy:** You're looking out of a train window. Instead of stopping at every spot and checking everything behind you, you just adjust what the window shows as you move forward.

Two types:
- **Fixed window** — window size is given (e.g. size k)
- **Variable window** — window grows and shrinks based on a condition

---

## LC #3 — Longest Substring Without Repeating Characters
**Type:** Variable window

### The flow
```
s = "abcabcbb"

Use a set to track chars in current window.
l=0, r=0: add 'a' → window="a"
l=0, r=1: add 'b' → window="ab"
l=0, r=2: add 'c' → window="abc" ← length 3
l=0, r=3: try 'a' → already in set!
           shrink from left: remove s[l]='a', l=1
           now try 'a' again → add it → window="bca"
...
```

### Code
```cpp
int lengthOfLongestSubstring(string s) {
    unordered_set<char> win;
    int l = 0, maxLen = 0;
    for (int r = 0; r < s.size(); r++) {
        while (win.count(s[r])) {
            win.erase(s[l]);
            l++;
        }
        win.insert(s[r]);
        maxLen = max(maxLen, r - l + 1);
    }
    return maxLen;
}
```

**TC:** O(n) · **SC:** O(n)

⚠️ **Struggle:** Still shaky on when to shrink. Rule: shrink with `while`, not `if`. Keep shrinking until the condition is satisfied.

---

## LC #239 — Sliding Window Maximum
**Type:** Fixed window of size k  
**Find:** maximum in every window of size k

### Why a deque?
At each position you want the max in the window. A max-heap would be O(n log n). A **deque** lets you do it in O(n) by storing indices in decreasing order of their values.

### The flow
```
nums = [1,3,-1,-3,5,3,6,7], k=3

Deque stores INDICES. Front = index of current max.

i=0: deque=[] → push 0 → deque=[0]  (val=1)
i=1: val=3 > nums[0]=1 → pop 0, push 1 → deque=[1]  (val=3)
i=2: val=-1 < 3 → push 2 → deque=[1,2]  window full → max=nums[1]=3
i=3: val=-3 < -1 → push 3 → deque=[1,2,3]
     front=1, i-k=0, 1>0 so front still valid → max=nums[1]=3
i=4: val=5 > all → pop 3,2,1 → push 4 → deque=[4] → max=5
...
```

### Two rules for the deque
1. **Pop from back** while `nums[back] <= nums[i]` — smaller values behind are useless
2. **Pop from front** when `front <= i - k` — that index has left the window

### Code
```cpp
vector<int> maxSlidingWindow(vector<int>& nums, int k) {
    deque<int> dq; // stores indices
    vector<int> result;
    for (int i = 0; i < nums.size(); i++) {
        // remove indices outside window
        while (!dq.empty() && dq.front() <= i - k) dq.pop_front();
        // remove smaller values from back
        while (!dq.empty() && nums[dq.back()] <= nums[i]) dq.pop_back();
        dq.push_back(i);
        // window is full
        if (i >= k - 1) result.push_back(nums[dq.front()]);
    }
    return result;
}
```

**TC:** O(n) · **SC:** O(k)

⚠️ **Struggle 1:** Used `if` instead of `while` when popping from back. Always `while`.  
⚠️ **Struggle 2:** Checked `dq.back()` before checking `!dq.empty()` → crash. Always check empty first.

---

# PATTERN 3 — Prefix/Suffix Array

## The Core Idea

When you need something that depends on **everything to the left** or **everything to the right** of a position — precompute it.

**Analogy:** You're a cashier and someone asks "what's the product of all items except mine?" You don't multiply everything fresh each time. You precompute a running total from both directions and combine them.

---

## LC #238 — Product of Array Except Self
**Given:** array  
**Find:** for each index i, product of all elements except nums[i]  
**Constraint:** no division allowed

### The flow
```
nums = [1, 2, 3, 4]

Prefix (product of everything to the LEFT):
prefix = [1, 1, 2, 6]
         ↑  ↑  ↑  ↑
         nothing  left of 0
                  nums[0]
                     nums[0]*nums[1]
                           nums[0]*nums[1]*nums[2]

Suffix (product of everything to the RIGHT):
suffix = [24, 12, 4, 1]

result[i] = prefix[i] * suffix[i]
result = [1*24, 1*12, 2*4, 6*1] = [24, 12, 8, 6]
```

### Optimised — O(1) space
Instead of a suffix array, carry a running suffix multiplier from the right.

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
    int n = nums.size();
    vector<int> result(n, 1);

    // left pass — result[i] = product of everything left of i
    int prefix = 1;
    for (int i = 0; i < n; i++) {
        result[i] = prefix;
        prefix *= nums[i];
    }

    // right pass — multiply in suffix on the fly
    int suffix = 1;
    for (int i = n - 1; i >= 0; i--) {
        result[i] *= suffix;
        suffix *= nums[i];
    }

    return result;
}
```

**TC:** O(n) · **SC:** O(1) (output array doesn't count)

⚠️ **Struggle:** Hardcoded `b` instead of loop variable `i` in suffix pass. Always use the loop variable.

---

## LC #121 — Best Time to Buy Stock I
**Pattern:** Array scan — track running minimum

### The flow
```
prices = [7,1,5,3,6,4]

Track minPrice seen so far. At each price, check profit = price - minPrice.
day 0: price=7, min=7, profit=0
day 1: price=1, min=1, profit=0
day 2: price=5, min=1, profit=4 ← best so far
day 3: price=3, min=1, profit=2
day 4: price=6, min=1, profit=5 ← new best
day 5: price=4, min=1, profit=3
Answer: 5
```

```cpp
int maxProfit(vector<int>& prices) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int p : prices) {
        minPrice = min(minPrice, p);
        maxProfit = max(maxProfit, p - minPrice);
    }
    return maxProfit;
}
```

**TC:** O(n) · **SC:** O(1)

---

## 🔁 Quick Revision Cheatsheet

### When to use which pattern?

| Situation | Pattern |
|---|---|
| "Two values that sum/multiply to target" | HashMap |
| "Frequency of elements" | HashMap |
| "Group by some property" | HashMap |
| "Longest/shortest subarray with condition" | Sliding Window |
| "Max/min in every window of size k" | Sliding Window + Deque |
| "Product/sum of everything except self" | Prefix/Suffix |

### STL you need

```cpp
// HashMap
unordered_map<int,int> freq;
freq[x]++;
freq.count(x);      // 1 if exists, 0 if not
freq.find(x) != freq.end();  // same thing, more explicit

// HashSet
unordered_set<int> seen;
seen.insert(x);
seen.erase(x);
seen.count(x);

// Min-heap
priority_queue<int, vector<int>, greater<int>> pq;
pq.push(x); pq.top(); pq.pop();

// Deque
deque<int> dq;
dq.push_back(x);  dq.pop_back();
dq.push_front(x); dq.pop_front();
dq.front(); dq.back();
// ALWAYS check !dq.empty() before front() or back()
```

### TC/SC summary

| Problem | TC | SC |
|---|---|---|
| LC #1 Two Sum | O(n) | O(n) |
| LC #217 Contains Duplicate | O(n) | O(n) |
| LC #242 Valid Anagram | O(n) | O(1) |
| LC #49 Group Anagrams | O(n·m log m) | O(n·m) |
| LC #347 Top K Frequent | O(n log k) | O(n) |
| LC #3 Longest Substring | O(n) | O(n) |
| LC #239 Sliding Window Max | O(n) | O(k) |
| LC #238 Product Except Self | O(n) | O(1) |
| LC #121 Best Time to Buy | O(n) | O(1) |