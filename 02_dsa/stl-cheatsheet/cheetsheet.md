============================================================
C++ STL CHEAT SHEET (FOR COMPETITIVE PROGRAMMING)
============================================================

---

# VECTOR

---

#include <vector>
vector<int> v;

// Add element
v.push_back(10);

// Remove last element
v.pop_back();

// Size of vector
int sz = v.size();

// Access element at index
int x = v[2];

// Iterate
for (int i : v) { }

// Reverse iterate
for (auto it = v.rbegin(); it != v.rend(); ++it) { }

// Clear all elements
v.clear();

// Check if empty
if (v.empty()) { }

---

# ARRAY (Fixed-size)

---

#include <array>

array<int, 5> arr = {1, 2, 3, 4, 5};

int n = arr.size();

---

# STRING

---

#include <string>

string s = "hello";

// Access character
char c = s[1]; // 'e'

// Length
int len = s.length();

// Substring
string sub = s.substr(1, 3); // "ell"

// Find first occurrence of substring
size_t pos = s.find("ll");
if (pos != string::npos) { }

// Erase part of string
s.erase(1, 2); // remove 2 characters from index 1

---

# SET

---

#include <set>

set<int> s;

// Insert element
s.insert(10);

// Erase element
s.erase(10);

// Check existence
if (s.count(10)) { }

// Lower bound (first element >= x)
auto it = s.lower_bound(5);

// Upper bound (first element > x)
auto it2 = s.upper_bound(5);

// Iterate
for (int x : s) { }

---

# MULTISET

---

#include <set>

multiset<int> ms;

// Allows duplicates
ms.insert(5);
ms.insert(5);

// Erase all instances
ms.erase(5);

// Erase only one instance
ms.erase(ms.find(5));

// Count occurrences
int cnt = ms.count(5);

---

# UNORDERED_SET

---

#include <unordered_set>

unordered_set<int> us;

// Faster than set, but unordered

us.insert(10);
us.erase(10);

if (us.count(10)) { }

---

# MAP

---

#include <map>

map<char, int> m;

m['a'] = 5;

if (m.count('a')) { }

m.erase('a');

// Iterate
for (auto [key, value] : m) { }

---

# MULTIMAP

---

#include <map>

multimap<int, string> mm;

mm.insert({1, "hello"});
mm.insert({1, "world"});

// Find all values with same key
auto range = mm.equal_range(1);
for (auto it = range.first; it != range.second; ++it) {
// it->first, it->second
}

---

# UNORDERED_MAP

---

#include <unordered_map>

unordered_map<string, int> um;

um["hello"] = 10;

if (um.count("hello")) { }

---

# STACK

---

#include <stack>

stack<int> st;

st.push(5);
st.top(); // returns top element
st.pop();

if (st.empty()) { }

---

# QUEUE

---

#include <queue>

queue<int> q;

q.push(10);
q.front(); // first element
q.pop();

---

# DEQUE

---

#include <deque>

deque<int> dq;

dq.push_front(10);
dq.push_back(20);
dq.pop_front();
dq.pop_back();

int x = dq.front();
int y = dq.back();

---

# PRIORITY_QUEUE (MAX HEAP)

---

#include <queue>

priority_queue<int> pq;

pq.push(10);
int t = pq.top();
pq.pop();

---

# PRIORITY_QUEUE (MIN HEAP)

---

#include <queue>

priority_queue<int, vector<int>, greater<int>> pq;

pq.push(10);
int t = pq.top();
pq.pop();

---

# PAIR

---

#include <utility>

pair<int, int> p = {10, 20};

int a = p.first;
int b = p.second;

---

# TUPLE

---

#include <tuple>

tuple<int, string, double> t(5, "hello", 3.14);

int x;
string y;
double z;

tie(x, y, z) = t;

---

# LIST (DOUBLY LINKED LIST)

---

#include <list>

list<int> lst;

lst.push_back(10);
lst.push_front(5);
lst.pop_back();
lst.pop_front();

for (int x : lst) { }

---

# BITSET

---

#include <bitset>

bitset<8> b(string("10101010"));

b.count(); // number of 1s
b.any(); // true if any bit is 1
b.none(); // true if all bits are 0
b.flip(); // flips all bits
b.set(2); // set bit at pos 2 to 1
b.reset(2); // set bit at pos 2 to 0
b.to_ulong(); // convert to unsigned long

---

# SORTING

---

#include <algorithm>

vector<int> v = {4, 1, 7};

sort(v.begin(), v.end()); // ascending

sort(v.begin(), v.end(), greater<int>()); // descending

---

# BINARY SEARCH

---

#include <algorithm>

vector<int> v = {1, 3, 5, 7};

if (binary_search(v.begin(), v.end(), 3)) {
// exists
}

auto it = lower_bound(v.begin(), v.end(), 5);

---

# COMMON TYPEDEFS

---

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pii;

---

# USEFUL FUNCTIONS

---

// Find max
int m = max(5, 10);

// Find min
int n = min(5, 10);

// Sum of vector
#include <numeric>
int total = accumulate(v.begin(), v.end(), 0);

// Reverse a string
reverse(s.begin(), s.end());

// Remove duplicates in vector
sort(v.begin(), v.end());
v.erase(unique(v.begin(), v.end()), v.end());
