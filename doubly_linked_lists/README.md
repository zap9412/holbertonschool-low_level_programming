# Doubly Linked Lists

## General

A **doubly linked list** is a type of linked list in which each node contains a pointer to both the previous and the next node. This allows traversal of the list in both directions, making insertion and deletion operations more flexible compared to singly linked lists.

### How to Use Doubly Linked Lists

- **Creating a node:** Each node contains an integer (`n`), a pointer to the previous node (`prev`), and a pointer to the next node (`next`).
- **Adding nodes:** You can add nodes at the beginning or at the end of the list using the provided functions.
- **Accessing nodes:** Traverse the list from head to tail or tail to head.
- **Deleting nodes:** Remove a node at a specific index or free the entire list when done.

**Start exploring doubly linked lists:** Look for information online, in textbooks, or reliable C programming resources. Try to implement basic operations yourself before checking solutions. Focus on understanding memory allocation, pointers, and node connections.

## Requirements

### General

- **Allowed editors:** `vi`, `vim`, `emacs`
- **Compilation:** All files are compiled on Ubuntu 20.04 LTS using `python3` (version 3.8.5)
- **File format:** All files must end with a new line
- **README.md:** Must be included at the root of the project
- **Coding style:** Betty style (checked with `betty-style.pl` and `betty-doc.pl`)
- **Variables:** No global variables allowed
- **Functions:** No more than 5 functions per file
- **Allowed C standard library functions:** `malloc`, `free`, `printf`, `exit`
- **Main files:** Example `main.c` files may be provided for testing but are not required to be pushed; your own `main.c` will be used during evaluation
- **Header file:** All function prototypes must be included in `lists.h` and it must be include-guarded

## Data Structure

```c
/**
 * struct dlistint_s - doubly linked list
 * @n: integer
 * @prev: points to the previous node
 * @next: points to the next node
 *
 * Description: doubly linked list node structure
 */
typedef struct dlistint_s
{
    int n;
    struct dlistint_s *prev;
    struct dlistint_s *next;
} dlistint_t;
