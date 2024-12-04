
# Binary Tree

<details>
  <summary>Specification</summary>
<br />

## Binary Tree Member type

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Done | Member type            | Definition                                                                             |
|------|------------------------|----------------------------------------------------------------------------------------|
| [x]  | key_type               | Key the first template parameter (Key)                                                |
| [x]  | value_type             | T the second template parameter (T)                                                   |
| [x]  | node_type              | internal class Node that holds a key-value pair and pointers to left and right children |
| [x]  | reference              | reference to node_type                                                                  |
| [x]  | const_reference        | const reference to node_type                                                           |
| [x]  | iterator               | internal class BinaryTreeIterator<T>                                                  |
| [x]  | const_iterator         | internal class BinaryTreeConstIterator<T>                                             |
| [x]  | size_type              | size_t defines the type of the container size (standard type is size_t)               |

## Binary Tree Member functions

| Done | Member functions       | Definition                                      |
|------|------------------------|------------------------------------------------|
| [x]  | binary_tree()           | default constructor, creates an empty binary tree|
| [x]  | binary_tree(const binary_tree &bt) | copy constructor                              |
| [x]  | binary_tree(binary_tree &&bt) | move constructor                              |
| [x]  | ~binary_tree()          | destructor                                     |
| [x]  | operator=(binary_tree &&bt) | assignment operator overload for moving an object |
| [x]  | insert(const key_type &key, const value_type &value) | inserts a node into the tree |
| [x]  | remove(const key_type &key) | removes a node with a specific key            |
| [x]  | search(const key_type &key) | searches for a node by key                   |
| [ ]  | clear()                 | clears the tree                               |

## Binary Tree Element access

| Done | Element access         | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | node_type* find(const key_type &key) | finds a node by key                        |
| [ ]  | const node_type* find(const key_type &key) | finds a node by key (const version)      |
| [ ]  | key_type root()         | returns the root key of the tree               |

## Binary Tree Iterators

| Done | Iterators              | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | iterator begin()        | returns an iterator to the root of the tree    |
| [ ]  | iterator end()          | returns an iterator to the end of the tree     |
| [ ]  | const_iterator begin()  | returns a const iterator to the root of the tree |
| [ ]  | const_iterator end()    | returns a const iterator to the end of the tree |

## Binary Tree Capacity

| Done | Capacity               | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | bool empty()            | checks whether the tree is empty               |
| [ ]  | size_type size()        | returns the number of nodes in the tree        |
| [ ]  | size_type max_size()    | returns the maximum possible number of nodes   |

## Binary Tree Modifiers

| Done | Modifiers              | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | void clear()            | clears the contents of the tree                |
| [ ]  | void swap(binary_tree &other) | swaps the contents of two trees           |

## Binary Tree Traversal

| Done | Traversal               | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | void inorder()          | performs an inorder traversal of the tree      |
| [ ]  | void preorder()         | performs a preorder traversal of the tree     |
| [ ]  | void postorder()        | performs a postorder traversal of the tree    |
| [ ]  | void level_order()      | performs a level-order traversal of the tree  |

</details>

# Map

<details>
  <summary>Specification</summary>
<br />

## Map Member type

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Done | Member type            | Definition                                                                             |
|------|------------------------|----------------------------------------------------------------------------------------|
| [ ]  | key_type               | Key the first template parameter (Key)                                                |
| [ ]  | mapped_type            | T the second template parameter (T)                                                   |
| [ ]  | value_type             | std::pair<const key_type, mapped_type> Key-value pair                                  |
| [ ]  | reference              | value_type & defines the type of the reference to an element                          |
| [ ]  | const_reference        | const value_type & defines the type of the constant reference                         |
| [ ]  | iterator               | internal class MapIterator<K, T> or binary_tree::iterator                              |
| [ ]  | const_iterator         | internal class MapConstIterator<K, T> or binary_tree::const_iterator                   |
| [ ]  | size_type              | size_t defines the type of the container size (standard type is size_t)               |

## Map Member functions

This table contains the main public methods for interacting with the class:

| Done | Member functions       | Definition                                      |
|------|------------------------|------------------------------------------------|
| [ ]  | map()                  | default constructor, creates an empty map      |
| [ ]  | map(std::initializer_list<value_type> const &items) | creates a map initialized using std::initializer_list<T> |
| [ ]  | map(const map &m)      | copy constructor                                |
| [ ]  | map(map &&m)           | move constructor                               |
| [ ]  | ~map()                 | destructor                                     |
| [ ]  | operator=(map &&m)     | assignment operator overload for moving an object |

## Map Element access

| Done | Element access         | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | T& at(const Key& key)   | access a specified element with bounds checking |
| [ ]  | T& operator[](const Key& key) | access or insert specified element       |

## Map Iterators

| Done | Iterators              | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | iterator begin()        | returns an iterator to the beginning          |
| [ ]  | iterator end()          | returns an iterator to the end                |

## Map Capacity

| Done | Capacity               | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | bool empty()           | checks whether the container is empty         |
| [ ]  | size_type size()       | returns the number of elements                |
| [ ]  | size_type max_size()   | returns the maximum possible number of elements |

## Map Modifiers

| Done | Modifiers              | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | void clear()           | clears the contents                           |
| [ ]  | std::pair<iterator, bool> insert(const value_type& value) | inserts a node and returns an iterator + success |
| [ ]  | std::pair<iterator, bool> insert(const Key& key, const T& obj) | inserts a value by key and returns iterator + success |
| [ ]  | void erase(iterator pos) | erases an element at pos                     |
| [ ]  | void swap(map& other)   | swaps the contents                            |
| [ ]  | void merge(map& other)  | splices nodes from another container          |

## Map Lookup

| Done | Lookup                 | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | bool contains(const Key& key) | checks if container contains an element with specific key |

</details>

# Set

<details>
  <summary>Specification</summary>
<br />

## Set Member type

| Done | Member type            | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | key_type               | Key the first template parameter (Key)        |
| [ ]  | value_type             | Key value type (the value itself is a key)    |
| [ ]  | reference              | value_type & defines the type of the reference to an element |
| [ ]  | const_reference        | const value_type & defines the type of the constant reference |
| [ ]  | iterator               | internal class SetIterator<T>                 |
| [ ]  | const_iterator         | internal class SetConstIterator<T>            |
| [ ]  | size_type              | size_t defines the type of the container size |
| [ ]  |

## Set Member functions

| Done | Member functions       | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | set()                  | default constructor, creates an empty set     |
| [ ]  | set(std::initializer_list<value_type> const &items) | creates the set initialized using std::initializer_list<T> |
| [ ]  | set(const set &s)      | copy constructor                              |
| [ ]  | set(set &&s)           | move constructor                              |
| [ ]  | ~set()                 | destructor                                    |
| [ ]  | operator=(set &&s)     | assignment operator overload for moving an object |

## Set Iterators

| Done | Iterators              | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | iterator begin()        | returns an iterator to the beginning          |
| [ ]  | iterator end()          | returns an iterator to the end                |

## Set Capacity

| Done | Capacity               | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | bool empty()           | checks whether the container is empty         |
| [ ]  | size_type size()       | returns the number of elements                |
| [ ]  | size_type max_size()   | returns the maximum possible number of elements |

## Set Modifiers

| Done | Modifiers              | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | void clear()           | clears the contents                           |
| [ ]  | std::pair<iterator, bool> insert(const value_type& value) | inserts a node and returns iterator + success |
| [ ]  | void erase(iterator pos) | erases an element at pos                     |
| [ ]  | void swap(set& other)  | swaps the contents                            |
| [ ]  | void merge(set& other) | splices nodes from another container          |

## Set Lookup

| Done | Lookup                 | Definition                                     |
|------|------------------------|------------------------------------------------|
| [ ]  | iterator find(const Key& key) | finds an element with a specific key    |
| [ ]  | bool contains(const Key& key) | checks if the container contains an element with a specific key |

</details>

### Multiset

<details>
  <summary>Specification</summary>
<br />

*Multiset Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Checkbox | Member type            | Definition                                                                             |
|----------|------------------------|----------------------------------------------------------------------------------------|
| [ ]      | `key_type`               | `Key` the first template parameter (Key)                                                     |
| [ ]      | `value_type`             | `Key` value type (the value itself is a key)                                                    |
| [ ]      | `reference`              | `value_type &` defines the type of the reference to an element                                                             |
| [ ]      | `const_reference`        | `const value_type &` defines the type of the constant reference                                         |
| [ ]      | `iterator`               | internal class `MultisetIterator<T>` or `binary_tree::iterator` as internal iterator of tree subclass; defines the type for iterating through the container                                                 |
| [ ]      | `const_iterator`         | internal class `MultisetConstIterator<T>` or `binary_tree::const_iterator` as internal const iterator of tree subclass; defines the constant type for iterating through the container                                           |
| [ ]      | `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Multiset Member functions*

This table contains the main public methods for interacting with the class:

| Checkbox | Member functions      | Definition                                      |
|----------|------------------------|-------------------------------------------------|
| [ ]      | `multiset()`           | default constructor, creates an empty set                                 |
| [ ]      | `multiset(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates the set initizialized using std::initializer_list<T>    |
| [ ]      | `multiset(const multiset &ms)`  | copy constructor  |
| [ ]      | `multiset(multiset &&ms)`  | move constructor  |
| [ ]      | `~multiset()`  | destructor  |
| [ ]      | `operator=(multiset &&ms)`      | assignment operator overload for moving an object                                |

*Multiset Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Checkbox | Iterators              | Definition                                                                             |
|----------|------------------------|----------------------------------------------------------------------------------------|
| [ ]      | `iterator begin()`            | returns an iterator to the beginning                                                   |
| [ ]      | `iterator end()`                | returns an iterator to the end                                                         |

*Multiset Capacity*

This table contains the public methods for accessing the container capacity information:

| Checkbox | Capacity       | Definition                                      |
|----------|----------------|-------------------------------------------------|
| [ ]      | `bool empty()`          | checks whether the container is empty           |
| [ ]      | `size_type size()`           | returns the number of elements                  |
| [ ]      | `size_type max_size()`       | returns the maximum possible number of elements |

*Multiset Modifiers*

This table contains the public methods for modifying a container:

| Checkbox | Modifiers              | Definition                                                                             |
|----------|------------------------|----------------------------------------------------------------------------------------|
| [ ]      | `void clear()`                  | clears the contents                                                                    |
| [ ]      | `iterator insert(const value_type& value)`                 | inserts a node and returns an iterator to where the element is in the container                                        |
| [ ]      | `void erase(iterator pos)`                  | erases an element at pos                                                                        |
| [ ]      | `void swap(multiset& other)`                   | swaps the contents                                                                     |
| [ ]      | `void merge(multiset& other)`                  | splices nodes from another container                                                   |

*Multiset Lookup*

This table contains the public methods for viewing the container:

| Checkbox | Lookup                 | Definition                                                                             |
|----------|------------------------|----------------------------------------------------------------------------------------|
| [ ]      | `size_type count(const Key& key)`                  | returns the number of elements matching a specific key                                   |
| [ ]      | `iterator find(const Key& key)`                   | finds element with a specific key                                                        |
| [ ]      | `bool contains(const Key& key)`               | checks if the container contains element with a specific key                             |
| [ ]      | `std::pair<iterator,iterator> equal_range(const Key& key)`            | returns range of elements matching a specific key                                      |
| [ ]      | `iterator lower_bound(const Key& key)`            | returns an iterator to the first element not less than the given key                   |
| [ ]      | `iterator upper_bound(const Key& key)`            | returns an iterator to the first element greater than the given key                    |

</details>