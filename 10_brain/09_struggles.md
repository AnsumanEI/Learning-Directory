# 09 — Struggles & Mistakes
> Every mistake I've made, why it happened, and how to never make it again.  
> Read this before every revision session.

---

## 🧠 Why this file exists

Every mistake has a pattern. If you just fix the bug and move on, you'll make it again. This file forces you to understand **why** it happened — so your brain flags it before you make it next time.

---

## DSA — Arrays & HashMaps

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 1 | Forgot `return false` at end of Contains Duplicate | Assumed loop always returns | Every non-void function must have a return at the end |
| 2 | `values[nums[1]]` instead of `values[nums[i]]` | Hardcoded index while writing fast | Read every variable name before you type it |
| 3 | LC #238: hardcoded `b` in suffix loop instead of `i` | Copy-paste thinking | Use your loop variable. Always. |
| 4 | `unordered_set` vs `unordered_map` confusion | Both start with `unordered_` | Set = unique values only. Map = key → value pairs. |

---

## DSA — Stack

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 5 | `seen.count()` on a stack | Thought stack has `.count()` like a map | Stack has no `.count()`. Only `map`/`set`/`unordered_map`/`unordered_set` do |
| 6 | Pushed `s[0]` before the loop | Tried to initialise stack manually | Start loop from index 0. Let the loop handle everything |
| 7 | `match[')'] = ')'` | Forgot the value should be the opposite bracket | Closing bracket maps TO its opening bracket: `match[')'] = '('` |
| 8 | `pval.push.first(val)` | Made up syntax | `st.push({val, min})` — curly braces, not dot-first |
| 9 | `pval.top().second()` | Thought `second` is a method | `second` is a field: `st.top().second` — no brackets |
| 10 | `pval.top.first()` | Confused which part needs brackets | `top()` is a method (needs brackets). `first` is a field (no brackets) |
| 11 | Called `st.top()` on empty stack | Forgot to guard | Always: `if (!st.empty())` before `st.top()` or `st.pop()` |

---

## DSA — Sliding Window

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 12 | Used `if` instead of `while` when shrinking window | Thought one shrink was enough | Use `while` — keep shrinking until condition is satisfied |
| 13 | `win.back()` before `!win.empty()` check | Assumed deque wasn't empty | Always check `!dq.empty()` before `front()` or `back()` |
| 14 | Deque: used `if` instead of `while` when kicking from back | Same as #12 | Monotonic deque always uses `while` — not `if` |

---

## DSA — Binary Search

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 15 | `nums[mid] > nums[lo]` in rotated array | Didn't consider `lo == mid` case | Use `>=` — when lo equals mid, left half [lo..mid] is still "sorted" (one element) |
| 16 | `target > nums[lo]` in range check | Didn't consider target equalling boundary | Use `>=` and `<=` — target can equal boundary elements |

---

## Networking / libcurl

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 17 | SSL errors on curl | Used `https://` for localhost | Use `http://` for localhost or add `-k` flag to ignore SSL |
| 18 | Missing `-lcurl` flag | Forgot to link libcurl library | Compile: `g++ main.cpp -o client -lcurl` |
| 19 | `curl_easy_reset()` not called between requests | Didn't know state persists | Call `curl_easy_reset(curl)` between requests to clear previous settings |

---

## TCP Server

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 20 | `iss >> value` twice for SET | First line already extracted value, second read got empty string | Extract all words in one line: `iss >> cmd >> key >> value`. Don't repeat inside if block |
| 21 | Unknown command block left `response` empty | Forgot to assign | Always assign `response` in every branch. For echo: `response = string(buf)` |
| 22 | Duplicate `using namespace std` | Pasted twice | Keep only one at top of file |

---

## Linux

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 23 | `grep "text"` without dot | Forgot to specify search path | Always: `grep -r "text" .` — the dot means current directory |
| 24 | Cron: `* 12 * * *` thought it was midnight | Misread the fields | `* 12 * * *` = every minute of hour 12. Midnight = `0 0 * * *` |

---

## FastAPI / SQLite

| # | Mistake | Why it happened | Fix |
|---|---|---|---|
| 25 | `VALUE` instead of `VALUES` | SQL syntax written from memory | It's always `VALUES (?, ?)` — plural. No exceptions |

---

## 🔁 Pre-Session Checklist

Read these 5 before starting any coding session:

```
1. Empty stack → check !st.empty() before st.top() or st.pop()
2. Deque → use while not if when popping. Check empty before front()/back()
3. Binary search rotated → use >= not > for sorted half detection
4. Binary search range check → use >= and <= not > and <
5. grep → always add the dot: grep -r "text" .
```

---

## How to Update This File

After every session where you make a mistake:

```
1. Identify the exact mistake
2. Write WHY it happened (not just what was wrong)
3. Write the fix in one clear sentence
4. Add it to the right section above
5. Add it to the pre-session checklist if it's a recurring pattern
```

> The goal is not to record failures.  
> The goal is to never make the same mistake twice.