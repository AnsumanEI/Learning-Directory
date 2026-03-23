# C++ Key-Value Store

A simple in-memory key-value store built in C++ using unordered_map.

## Commands
- `SET key value` — store a value
- `GET key` — retrieve a value  
- `DELETE key` — remove a key
- `EXIT` — quit the program

## How to run
```bash
g++ main.cpp -o kvstore
.\kvstore
```

## What I learned
- unordered_map for O(1) storage and retrieval
- Parsing user input with cin
- Basic CRUD operations in C++