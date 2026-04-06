# Obsidian — End of Session Update Routine
> Do this in the last 5 minutes of every session. Not tomorrow. Right now.

---

## After a DSA Session (Mon/Wed/Fri)

### 1. `HOME.md`
- [ ] Tick off today's task in **This Week** table → change `🔜` to `✅`
- [ ] Update **Stats** → increment LC Problems Solved count

### 2. Relevant DSA file (`01_arrays_hashmap` / `02_stack` / `03_binary_search` / `04_trees`)
- [ ] Add the new problem under the right pattern heading:
  ```markdown
  ## LC #XXX — Problem Name
  ### The flow
  [walk through with actual values]
  
  ### Code
  [your solution]
  
  ### Why this works
  [the insight]
  ```
- [ ] Add TC/SC to the table at the bottom
- [ ] Add the problem to the revision cheatsheet at the bottom

### 3. `00_progress.md`
- [ ] Add new problem to the LC Problems Solved table:
  ```markdown
  | LC #XXX | Problem Name | Pattern | Difficulty |
  ```
- [ ] Update total count

### 4. `09_struggles.md`
- [ ] If you made any mistakes → add a new row to the right section:
  ```markdown
  | # | Mistake | Why it happened | Fix |
  ```
- [ ] If it's a recurring pattern → add to Pre-Session Checklist at bottom

---

## After a Backend Session (Tue/Thu)

### 1. `HOME.md`
- [ ] Tick off today's task → `✅`

### 2. `07_fastapi.md` (or new backend file if big enough topic)
- [ ] Add new section for what was learned:
  ```markdown
  ## Week X — Topic Name
  ### The flow
  ### Key concepts
  ### Code
  ### Test with curl
  ```
- [ ] Update Quick Revision Cheatsheet at bottom

### 3. `00_progress.md`
- [ ] Note the backend concept as completed

### 4. `09_struggles.md`
- [ ] Add any mistakes made

---

## After a Linux Session (Thu)

### 1. `HOME.md`
- [ ] Tick off today's task → `✅`

### 2. `08_linux.md`
- [ ] Add new commands under the right section
- [ ] Add to Quick Revision Cheatsheet at bottom

### 3. `09_struggles.md`
- [ ] Add any command mistakes

---

## After a Project Session (Sat)

### 1. `HOME.md`
- [ ] Tick off today's task → `✅`
- [ ] Add project to **Projects Built** table

### 2. Create a new project file in `Projects/`
Name it: `ProjectName.md`

Use this structure:
```markdown
---
tags: [project, backend/linux/networking]
---

# Project Name
> Built: [date]
> Location: `path/to/project/`
> Compile/Run: `command here`

## What I Built
[2-3 sentences]

## The Full Flow
[stage by stage with actual values]

## Key Concepts Learned
| Concept | What it does |
|---|---|

## Bugs Found
| Bug | Cause | Fix |
|---|---|---|

## 🔗 Related Notes
- [[HOME]]
- [[relevant topic files]]
- [[09_struggles]]
- [[00_progress]]
```

### 3. `00_progress.md`
- [ ] Add project to Projects Built table
- [ ] Add GitHub path

### 4. `09_struggles.md`
- [ ] Add any bugs found during the project

---

## After a Review Session (Sun)

### 1. `HOME.md`
- [ ] Update **This Week** table for the coming week
- [ ] Update **Stats** — recount everything
- [ ] Update the **Daily Revision** priorities if any pattern moved from High → Medium

### 2. `00_progress.md`
- [ ] Recount total LC problems
- [ ] Update current week number
- [ ] Update "What's Next" table for the new week

### 3. `09_struggles.md`
- [ ] Review the Pre-Session Checklist — still relevant?
- [ ] Archive old struggles that no longer trip you up (add ✅ next to them)

---

## After Adding a New Topic (any session)

When you learn something big enough for its own file:

### 1. Create the file using Templater
- Right click the right folder → New note
- Templater auto-fills the structure
- Fill in the content

### 2. Add backlinks to the new file
Always add at the bottom:
```markdown
## 🔗 Related Notes
- [[HOME]]
- [[00_progress]]
- [[09_struggles]]
- [[relevant files]]
```

### 3. Add forward links FROM related files TO the new file
Go to every related file and add a link to the new file in their **Related Notes** section.

### 4. Add to `HOME.md` Quick Links table

### 5. Git push
```bash
cd ~/Brain
git add .
git commit -m "added: topic name"
git push
```

---

## The 5-Minute Rule

When the session ends, set a 5-minute timer. In those 5 minutes:

```
1 min → HOME.md — tick off today, update stats
2 min → Topic file — add what you learned
1 min → 09_struggles — add any mistakes
1 min → git add . && git commit -m "session: date" && git push
```

That's it. 5 minutes. Every single session. No exceptions.

---

## Git Push Command (end of every session)

```bash
cd ~/Brain
git add .
git commit -m "session: Apr 5 — 3-week checkpoint + obsidian setup"
git push
```

Change the date and topic each time.