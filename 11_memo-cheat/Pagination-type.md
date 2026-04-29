# Pagination
*W6 D4 — April 27, 2026*

---

## How It Works in This Project

This project uses **offset pagination** — every request sends a `skip` and `limit` parameter to the database.[cite:70]

```
GET /devices?skip=0&limit=10   → page 1 (rows 0–9)
GET /devices?skip=10&limit=10  → page 2 (rows 10–19)
GET /devices?skip=20&limit=10  → page 3 (rows 20–29)
```

Under the hood, this translates to a SQL query:[cite:74]

```sql
SELECT * FROM device_readings
ORDER BY timestamp DESC
LIMIT 10 OFFSET 20;
```

The database scans from row 0, discards the first 20 rows, and returns the next 10.[cite:74] Simple, predictable, and easy to implement.

---

## Why Offset Works Well for This Project

Offset pagination is the right choice here because:[cite:70][cite:68]

- **Small dataset** — IoT project with a limited number of devices. No millions of rows, so skipping a few hundred rows costs nothing.
- **Random access needed** — if a device suddenly shows faulty readings, you need to jump directly to page 5 or page 20 to inspect it fast. Offset lets you do this instantly.
- **Easy to implement** — `skip` and `limit` map directly to `OFFSET` and `LIMIT` in SQL. FastAPI + SQLAlchemy makes this trivial.
- **Human-friendly** — page numbers make sense for dashboards and admin panels where users think in terms of "go to page 3".[cite:70]

---

## Cursor Pagination — How It Works

Cursor pagination uses a **marker** (cursor) from the last row you fetched, and asks the database for rows *after* that marker.[cite:79]

```
GET /readings?cursor=<timestamp_of_last_row>&limit=10
```

This becomes:

```sql
SELECT * FROM device_readings
WHERE timestamp > '2026-04-27T10:00:00'
ORDER BY timestamp ASC
LIMIT 10;
```

The database hits an index directly — no scanning, no discarding.[cite:73] The cursor is usually an indexed column like `id` or `created_at`.

Key constraint: **you can only go forward, one page at a time**.[cite:69] You can't jump to page 50 — you must step through 1 → 2 → 3 → ... → 50.

---

## Why Cursor Beats Offset at Scale

The deeper you paginate with offset, the more rows the database silently scans and throws away.[cite:74]

```
Page 1:   OFFSET 0       → scans 0 rows before returning results    ✅ fast
Page 100: OFFSET 1000    → scans and discards 1000 rows             🐌 slower
Page 500: OFFSET 5000    → scans and discards 5000 rows             🐌🐌 slow
Page 5000: OFFSET 50000  → scans and discards 50,000 rows           ❌ unusable
```

This is **O(n) complexity** — query time grows linearly with page depth.[cite:70]

Cursor pagination has **O(1) complexity** — whether you're on page 1 or page 10,000, the query cost is the same because it always uses an indexed lookup instead of a scan.[cite:70]

A practical example: Twitter, Instagram, and activity feed apps all use cursor pagination because new data arrives every second. If a new tweet is inserted while you're on page 2, offset-based pagination would cause you to see a duplicate or skip a record. Cursor pagination is immune to this — it always fetches from a stable position.[cite:82]

---

## When to Use Each

| Factor | Offset Pagination | Cursor Pagination |
|--------|-------------------|-------------------|
| Dataset size | Small to medium | Large (10,000+ rows) |
| Data growth rate | Slow / stable | Rapid / real-time |
| Navigation style | Jump to any page | Sequential forward only |
| Implementation complexity | Simple | Moderate |
| Performance at depth | Degrades with offset | Constant O(1) |
| Consistency during inserts | Can skip/duplicate rows | Stable, no drift |
| Good for | Admin dashboards, IoT device lists | Feeds, logs, time-series streams |

---

## Decision Rule for Your Projects

**Use offset when:**
- Dataset is bounded and won't grow to millions of rows
- Users need to jump to a specific page or device directly
- You're building an admin panel or internal tool[cite:70]

**Use cursor when:**
- Data is appended continuously (every second, every minute)
- Users scroll forward through a feed and never need to jump
- Scale is the priority — you can't afford O(n) query cost[cite:73][cite:82]

**Your IoT project** stores device readings at intervals — manageable volume, and you need to jump to a faulty device fast → **offset is correct**.

**Real-time data at every second** (sensor stream, logs, activity feed) → rows pile up to millions → **cursor is correct**.

---

*Reference built: W6 D4, April 27, 2026*
