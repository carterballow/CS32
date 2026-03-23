# CS32 @ UCLA — Data Structures & Algorithms

A collection of four C++ projects completed for CS32 at UCLA. Each project builds on the previous, progressing from basic object-oriented programming through advanced data structures and algorithm analysis.

---

## Projects

### Project 1 — Blood Donation Vacation Account
**Concepts:** Classes, constructors/destructors, arrays of pointers, date validation

A system that tracks vacation time accrued from blood donations. Introduces basic class design with encapsulation, getter/setter methods, and static utility functions for date validation (including leap year logic).

**Files:** `BloodDonation.h/.cpp`, `VacationAccount.h/.cpp`, `DateUtility.h/.cpp`

---

### Project 2 — Doubly-Linked List Task Manager
**Concepts:** Dynamic memory, linked lists, Rule of Three, pointer arithmetic

Implements a doubly-linked list from scratch to manage a list of tasks. The core challenge is manual memory management — writing a correct destructor, copy constructor, and copy assignment operator to avoid memory leaks and double-free errors.

**Files:** `TaskList.h/.cpp`
**Key methods:** `addBack()`, `removeFront()`, `get()`, `find()`, `clear()`

---

### Project 3 — SmartCatalog (Polymorphic Product System)
**Concepts:** Inheritance, abstract base classes, virtual functions, polymorphism

An abstract `Product` base class with three concrete subclasses: `Book`, `Clothing`, and `Electronics`. Demonstrates runtime polymorphism — a single `Product*` pointer can call the correct subclass behavior at runtime via virtual dispatch.

**Files:** `Product.h/.cpp`, `Book.h/.cpp`, `Clothing.h/.cpp`, `Electronics.h/.cpp`

---

### Project 4 — MiniHub Search Engine
**Concepts:** Hash tables, BSTs, sorting algorithms, smart pointers, Big-O analysis

A capstone project that builds a small search engine by combining multiple data structures:

| Component | Implementation | Complexity |
|-----------|---------------|------------|
| `HashTable` | Separate chaining with `std::vector<std::list<Node>>` | O(1) avg insert/find/erase |
| `BST` | Binary search tree with inorder traversal | O(log n) avg, O(n) worst |
| Insertion Sort | Stable sort, in-place | O(n²) avg, O(n) best |
| Merge Sort | Stable sort, recursive | O(n log n) all cases |
| `Engine` | Combines hash table + BST for search | — |

Smart pointers (`std::unique_ptr`) are used throughout to eliminate manual memory management. See `project4/report.md` for the full Big-O analysis.

**Files:** `hashtable.h/.cpp`, `bst.h/.cpp`, `sorts.h/.cpp`, `engine.h/.cpp`, `item.h/.cpp`

---

## How to Build

Each project can be compiled with:

```bash
g++ -std=c++17 main.cpp *.cpp -o program
./program
```

Project 1 also has an Xcode project file (`project1.xcodeproj`) if you prefer the IDE.

---

## Languages & Tools

- **C++17**
- Standard Library: `<vector>`, `<list>`, `<memory>`, `<string>`, `<functional>`
- Build: g++ / Xcode
