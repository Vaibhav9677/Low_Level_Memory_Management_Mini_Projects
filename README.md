# 🧠 Low-Level Memory Programming – Mini Projects  

---

## 🎯 Project Overview

This repository demonstrates **low-level programming in C**, where each mini-program operates **entirely within a single memory block** (using only one unsigned character array).  
The goal is to simulate memory handling and data manipulation **without using any external variables, arrays, or data structures** — just like working with real hardware memory.

Each program represents a different concept of system-level computation, using **pointer arithmetic, bit manipulation, and byte-level operations** to achieve a complete algorithm within fixed-size memory.

---

## 🧩 Base Idea

- Treat a single `unsigned char mem[]` array as **raw memory (RAM)**.  
- Use memory offsets and typecasting to simulate variables, pointers, and temporary registers.  
- All logical operations (sorting, comparison, swapping, counting) happen **within the same memory block**.  
- Programs follow **strict memory constraints** (e.g., 4 KB or 2 KB) to emulate embedded systems or low-level environments.  
- Demonstrates how algorithms can be implemented when **direct access to data structures is restricted**.

---

## 🧠 Key Concepts Used

- **Pointer arithmetic** – direct address access and offset manipulation.  
- **Typecasting** – reinterpret bytes as `int`, `short`, or `char` values.  
- **Bit manipulation** – extract or combine specific bit fields (like 18-bit extraction).  
- **In-place operations** – sorting and calculation without extra memory usage.  
- **Memory mapping** – manually reserving bytes for "variables" inside the memory array.

---

## ⚙️ Mini Programs Included

| Program | File | Description |
|----------|------|--------------|
| 🧾 Word Sorter | `word_sorter.c` | Sorts words alphabetically inside a 4 KB memory block using ASCII comparison. |
| 🔢 Min/Max 18-Bit | `min_max_18Bit.c` | Extracts 18-bit values from memory using bit-shift operations and finds min/max. |
| 🧮 List Min/Max | `list_min_max.c` | Finds min/max within multiple lists stored sequentially in memory using subroutines. |

---

## 💾 Memory Constraint Example

Each program reserves a specific portion of memory for "variables" instead of declaring them separately:
mem[len - 2] → Pointer to list
mem[len - 6] → Return value (min/max)
mem[len - 7] → Error flag
mem[len - 11] → Counter or offset pointer

This technique mimics **register-level programming** or **bare-metal embedded design**, where every byte has a defined purpose.

---

## 🚀 Compilation & Execution

Each program can be compiled and run independently:

```bash
gcc -o program_name source_file.c
./program_name
```

## Example:

```bash
gcc -o word_sorter word_sorter.c
./word_sorter
```

---

## 🎓 Learning Outcome

Through these programs, the following system-level concepts were explored:

Memory layout & addressing

Data abstraction at byte level

Custom variable simulation in memory

Algorithm design under constrained environments

Bitwise and arithmetic logic implementation

---

## 🧠 Why Low-Level Programming?

This mini-project series was designed to:

Strengthen understanding of how memory actually works in computers.

Show that even complex algorithms (sorting, searching, extraction) can run without arrays, structs, or dynamic allocation.

Simulate the logic used in embedded systems, OS kernels, and device drivers.

---


