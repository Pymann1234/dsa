# Chapter 3: Data Structures

## 3.1 Classification of Data Structures

Data structures organize data and the relationships between its elements. They
can be viewed from two perspectives:

### Logical structure

- **Linear:** Elements follow a sequence. Examples include arrays, linked lists,
  stacks, and queues.
- **Non-linear:** Elements form hierarchies or networks. Trees and heaps have
  hierarchical relationships; graphs represent connections between many
  elements. Hash tables can be viewed in either category depending on how their
  relationships are described.

### Physical structure

- **Contiguous storage:** Elements occupy adjacent memory locations, as in an
  array. This supports direct access by position, but resizing may require
  allocating a new block and moving elements.
- **Dispersed storage:** Elements can be stored at separate memory locations
  and connected through references, as in a linked list. This allows the
  structure to grow during execution, but accessing a particular element
  requires following the connections.

Stacks, queues, trees, heaps, and graphs can be implemented with arrays, linked
lists, or combinations of them. The choice affects memory use and operation
efficiency. Arrays are often called static because their size is fixed after
initialization; linked lists are often called dynamic because they can grow or
shrink as elements are added or removed.

## 3.2 Basic Data Types

Basic data types describe the **kind of value** stored; data structures describe
**how values are organized**. The same structure, such as an array, can hold
integers, floating-point values, characters, or Boolean values.

Common C++ types include:

- `int` and other integer types for whole numbers
- `float` and `double` for floating-point numbers
- `char` for a single byte-sized character
- `bool` for `true` or `false`

Data is represented in binary. A bit stores a `0` or `1`, and a byte is commonly
eight bits. Type sizes and value ranges can depend on the language and platform,
so check the C++ implementation rather than assuming the Java sizes shown in
some reference tables. A `char` occupies one byte in C++; representing
characters outside a basic character set may require a different character type
or encoding.

**In short:** types define what each stored value means, while data structures
define the arrangement and relationships among those values.
