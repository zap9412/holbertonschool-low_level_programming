```markdown
# Hash Tables Project

## General
- What is a hash function
- What makes a good hash function
- What is a hash table, how they work, and how to use them
- What is a collision and common collision-handling methods
- Advantages and drawbacks of hash tables
- Common use cases of hash tables

## Requirements
- Allowed editors: vi, vim, emacs
- All files compiled on **Ubuntu 20.04 LTS** using:
```

gcc -Wall -Werror -Wextra -pedantic -std=gnu89

```
- All files must end with a new line
- A `README.md` file at the root is **mandatory**
- Code must follow **Betty style** (`betty-style.pl` & `betty-doc.pl`)
- No global variables allowed
- Max **5 functions per file**
- Allowed: **C standard library**
- All function prototypes must be in **hash_tables.h** (push this file!)
- All header files must be include-guarded

## Data Structures
```

/**

* struct hash_node_s - Node of a hash table
* @key: The key, string (unique)
* @value: The value linked to the key
* @next: Pointer to the next node (Chaining)
  */
  typedef struct hash_node_s
  {
  char *key;
  char *value;
  struct hash_node_s *next;
  } hash_node_t;

/**

* struct hash_table_s - Hash table data structure
* @size: Size of the array
* @array: Array of linked list heads (Chaining)
  */
  typedef struct hash_table_s
  {
  unsigned long int size;
  hash_node_t **array;
  } hash_table_t;

```

## Additional Information
- Python dictionaries use hash tables → this project helps understand them.
- Collaboration on tests is encouraged.
- Hash tables ≠ dictionaries (though often implemented similarly).

```
