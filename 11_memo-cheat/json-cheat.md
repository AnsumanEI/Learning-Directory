
---

## 1 — Simple message
```python
return {"message": "User created"}
```

---

## 2 — Message + single object
```python
return {"message": "User created", "user": {"name": user.name, "role": user.role}}
```

---

## 3 — Message + list
```python
return {"message": "Users fetched", "users": users}
```

---

## 4 — Just a token
```python
return {"access_token": token}
```

---

## 5 — Error (via HTTPException, not return)
```python
raise HTTPException(status_code=401, detail="Invalid credentials")
```

---

## The rules to remember

| Situation | Pattern |
|---|---|
| Returning one object | `{"key": {"field": value}}` |
| Returning a list | `{"key": variable}` — no extra `{}` |
| Returning a token | `{"access_token": token}` |
| Returning an error | always `raise HTTPException` never `return` |
| Always use | `detail` not `details` |

---

## The golden rule
JSON is just a Python dictionary. Nested object = nested `{}`. List = just pass the variable directly, no extra `{}` around it.

That's all you need. Now rewrite the full file with all 7 fixes.