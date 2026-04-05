# 03 — DSA: Binary Search
> Patterns: Standard Binary Search · Rotated Array Search  
> Problems: LC #704, #33

---

## 🧠 The Big Idea

Binary search is about **eliminating half the search space** at every step.

**Analogy:** You're looking for a word in a dictionary. You don't start from page 1. You open the middle. If your word comes after that page — throw away the left half. If it comes before — throw away the right half. Repeat. You find the word in O(log n) steps instead of O(n).

The catch: **the array must be sorted** (or at least partially sorted — more on that with LC #33).

---

## The Template — Memorise This Cold

```cpp
int lo = 0, hi = n - 1;

while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;  // NEVER (lo + hi) / 2 → overflow risk

    if (nums[mid] == target) return mid;
    else if (nums[mid] < target) lo = mid + 1;  // target is in right half
    else hi = mid - 1;                           // target is in left half
}

return -1; // not found
```

### Why `lo + (hi - lo) / 2` and not `(lo + hi) / 2`?

If `lo` and `hi` are both large (near INT_MAX), `lo + hi` overflows a 32-bit integer and gives a wrong (negative) result.

`lo + (hi - lo) / 2` gives the exact same mathematical result but never overflows.

---

### Why `lo <= hi` not `lo < hi`?

Consider searching for `target = 3` in `[3]`.  
`lo = 0`, `hi = 0`. They're equal. If you use `<`, you skip the only element.  
`<=` means: when lo and hi converge on one element, still check it.

---

## LC #704 — Binary Search
**Given:** sorted array, target  
**Find:** index of target, or -1

### The flow

```
nums = [-1, 0, 3, 5, 9, 12], target = 9

lo=0, hi=5
  mid = 0 + (5-0)/2 = 2 → nums[2]=3 < 9 → lo = 3

lo=3, hi=5
  mid = 3 + (5-3)/2 = 4 → nums[4]=9 == 9 → return 4 ✅
```

### Code

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;
    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (nums[mid] == target) return mid;
        else if (nums[mid] < target) lo = mid + 1;
        else hi = mid - 1;
    }
    return -1;
}
```

**TC:** O(log n) · **SC:** O(1)

---

# PATTERN 2 — Binary Search on Rotated Array

## The Core Idea

A rotated sorted array looks like this:

```
Original:  [1, 2, 3, 4, 5, 6, 7]
Rotated:   [4, 5, 6, 7, 1, 2, 3]
                       ↑
                  rotation point
```

It's no longer fully sorted. But here's the key insight:

> **When you split a rotated array at mid, at least one of the two halves is always fully sorted.**

This is the trick. You find which half is sorted, check if target lives there, and search that half. Otherwise search the other half.

---

## LC #33 — Search in Rotated Sorted Array
**Given:** rotated sorted array, target  
**Find:** index of target, or -1

### How to know which half is sorted?

```
If nums[mid] >= nums[lo] → LEFT half is sorted
Otherwise               → RIGHT half is sorted
```

Why `>=` and not `>`?  
When `lo == mid` (two elements left), `nums[mid] == nums[lo]`. Using `>` would wrongly say neither half is sorted. `>=` handles this edge case.

### Once you know which half is sorted — is target in it?

```
Left half sorted  [nums[lo] ... nums[mid]]:
  target is in left half if: nums[lo] <= target <= nums[mid]
  otherwise: search right half

Right half sorted [nums[mid] ... nums[hi]]:
  target is in right half if: nums[mid] <= target <= nums[hi]
  otherwise: search left half
```

Why `<=` on the boundaries?  
Target could **equal** a boundary element. Using `<` would miss it.

---

### The flow

```
nums = [4, 5, 6, 7, 0, 1, 2], target = 0

lo=0, hi=6
  mid=3 → nums[3]=7
  nums[mid]=7 >= nums[lo]=4 → LEFT half [4,5,6,7] is sorted
  Is target=0 in [4..7]? No (0 < 4)
  → search right half: lo = mid+1 = 4

lo=4, hi=6
  mid=5 → nums[5]=1
  nums[mid]=1 >= nums[lo]=0? → nums[lo]=nums[4]=0. 1>=0 → LEFT half [0,1] is sorted
  Is target=0 in [0..1]? Yes (0 >= 0 and 0 <= 1)
  → search left half: hi = mid-1 = 4

lo=4, hi=4
  mid=4 → nums[4]=0 == target → return 4 ✅
```

---

### Code

```cpp
int search(vector<int>& nums, int target) {
    int lo = 0, hi = nums.size() - 1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (nums[mid] == target) return mid;

        // left half is sorted
        if (nums[mid] >= nums[lo]) {
            // is target in the sorted left half?
            if (target >= nums[lo] && target <= nums[mid]) {
                hi = mid - 1;  // search left
            } else {
                lo = mid + 1;  // search right
            }
        }
        // right half is sorted
        else {
            // is target in the sorted right half?
            if (target >= nums[mid] && target <= nums[hi]) {
                lo = mid + 1;  // search right
            } else {
                hi = mid - 1;  // search left
            }
        }
    }

    return -1;
}
```

**TC:** O(log n) · **SC:** O(1)

---

## ⚠️ The Edge Cases That Trip Everyone

### Edge case 1 — `lo == mid`

```
nums = [3, 1], target = 1
lo=0, hi=1 → mid=0

nums[mid]=3, nums[lo]=3
If you use >  : 3 > 3 is false → wrongly says right half is sorted
If you use >= : 3 >= 3 is true → correctly identifies left half [3] as sorted
```

**Rule:** Always use `>=` when comparing `nums[mid]` to `nums[lo]`.

---

### Edge case 2 — target equals a boundary

```
nums = [4, 5, 6, 7, 0, 1, 2], target = 4

lo=0, hi=6, mid=3 → nums[3]=7
Left half sorted: [4..7]
Is target=4 in range?
  If you use < and <  : 4 < 4 is false → wrongly skips left half
  If you use >= and <= : 4 >= 4 is true → correctly searches left half
```

**Rule:** Always use `>=` and `<=` in the range check. Target can equal a boundary.

---

## ⚠️ All Binary Search Struggles (from real sessions)

| Mistake | What happened | Fix |
|---|---|---|
| `(lo + hi) / 2` | Overflow on large arrays | Use `lo + (hi - lo) / 2` |
| `lo < hi` instead of `lo <= hi` | Misses the last element | Use `<=` |
| `nums[mid] > nums[lo]` | Fails when lo == mid | Use `>=` |
| `target > nums[lo]` in range check | Misses when target == boundary | Use `>=` and `<=` |
| `target < nums[mid]` in range check | Same problem | Use `<=` |

---

## 🔁 Quick Revision Cheatsheet

### The full template with rotated array rules

```cpp
int lo = 0, hi = n - 1;
while (lo <= hi) {
    int mid = lo + (hi - lo) / 2;

    if (nums[mid] == target) return mid;

    if (nums[mid] >= nums[lo]) {          // left half sorted — use >=
        if (target >= nums[lo] && target <= nums[mid])  // use >= and <=
            hi = mid - 1;
        else
            lo = mid + 1;
    } else {                               // right half sorted
        if (target >= nums[mid] && target <= nums[hi])  // use >= and <=
            lo = mid + 1;
        else
            hi = mid - 1;
    }
}
return -1;
```

### The 4 rules to never forget

```
1. mid = lo + (hi - lo) / 2          — never overflow
2. while (lo <= hi)                   — check when lo == hi
3. nums[mid] >= nums[lo]              — use >= to detect sorted half
4. target >= boundary && target <= boundary  — use >= and <= in range check
```

### TC/SC

| Problem | TC | SC |
|---|---|---|
| LC #704 Binary Search | O(log n) | O(1) |
| LC #33 Search Rotated Array | O(log n) | O(1) |

### The mental checklist before submitting

```
□ Am I using lo + (hi - lo) / 2?
□ Am I using lo <= hi?
□ Am I using >= when comparing nums[mid] to nums[lo]?
□ Am I using >= and <= in the range check?
□ Did I handle the case where target equals a boundary?
```