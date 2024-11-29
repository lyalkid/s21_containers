
# Map

<details>
  <summary>Specification</summary>
<br />

## Map Member type

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                             | Done |
|------------------------|----------------------------------------------------------------------------------------|------|
| key_type               | Key the first template parameter (Key)                                                | [x]  |
| mapped_type            | T the second template parameter (T)                                                   | [ ]  |
| value_type             | std::pair<const key_type, mapped_type> Key-value pair                                  | [ ]  |
| reference              | value_type & defines the type of the reference to an element                          | [ ]  |
| const_reference        | const value_type & defines the type of the constant reference                         | [ ]  |
| iterator               | internal class MapIterator<K, T> or BinaryTree::iterator                              | [ ]  |
| const_iterator         | internal class MapConstIterator<K, T> or BinaryTree::const_iterator                   | [ ]  |
| size_type              | size_t defines the type of the container size (standard type is size_t)               | [ ]  |

## Map Member functions

This table contains the main public methods for interacting with the class:

| Member functions       | Definition                                      | Done |
|-------------------------|------------------------------------------------|------|
| map()                  | default constructor, creates an empty map      | [ ]  |
| map(std::initializer_list<value_type> const &items) | creates a map initialized using std::initializer_list<T> | [ ]  |
| map(const map &m)      | copy constructor                                | [ ]  |
| map(map &&m)           | move constructor                               | [ ]  |
| ~map()                 | destructor                                     | [ ]  |
| operator=(map &&m)     | assignment operator overload for moving an object | [ ] |

## Map Element access

| Element access         | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| T& at(const Key& key)   | access a specified element with bounds checking | [ ]  |
| T& operator[](const Key& key) | access or insert specified element       | [ ]  |

## Map Iterators

| Iterators              | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| iterator begin()        | returns an iterator to the beginning          | [ ]  |
| iterator end()          | returns an iterator to the end                | [ ]  |

## Map Capacity

| Capacity               | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| bool empty()           | checks whether the container is empty         | [ ]  |
| size_type size()       | returns the number of elements                | [ ]  |
| size_type max_size()   | returns the maximum possible number of elements | [ ] |

## Map Modifiers

| Modifiers              | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| void clear()           | clears the contents                           | [ ]  |
| std::pair<iterator, bool> insert(const value_type& value) | inserts a node and returns an iterator + success | [ ] |
| std::pair<iterator, bool> insert(const Key& key, const T& obj) | inserts a value by key and returns iterator + success | [ ] |
| void erase(iterator pos) | erases an element at pos                     | [ ]  |
| void swap(map& other)   | swaps the contents                            | [ ]  |
| void merge(map& other)  | splices nodes from another container          | [ ]  |

## Map Lookup

| Lookup                 | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| bool contains(const Key& key) | checks if container contains an element with specific key | [ ]  |

</details>

# Queue

<details>
  <summary>Specification</summary>
<br />

## Queue Member type

| Member type            | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| value_type             | T the template parameter T                    | [ ]  |
| reference              | T & defines the type of the reference to an element | [ ]  |
| const_reference        | const T & defines the type of the constant reference | [ ]  |
| size_type              | size_t defines the type of the container size | [ ]  |

## Queue Member functions

| Functions              | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| queue()                | default constructor, creates an empty queue   | [ ]  |
| queue(std::initializer_list<value_type> const &items) | creates queue initialized using std::initializer_list<T> | [ ] |
| queue(const queue &q)  | copy constructor                              | [ ]  |
| queue(queue &&q)       | move constructor                              | [ ]  |
| ~queue()               | destructor                                    | [ ]  |
| operator=(queue &&q)   | assignment operator overload for moving an object | [ ] |

## Queue Element access

| Element access         | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| const_reference front() | access the first element                     | [ ]  |
| const_reference back()  | access the last element                      | [ ]  |

## Queue Capacity

| Capacity               | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| bool empty()           | checks whether the container is empty         | [ ]  |
| size_type size()       | returns the number of elements                | [ ]  |

## Queue Modifiers

| Modifiers              | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| void push(const_reference value) | inserts an element at the end       | [ ]  |
| void pop()             | removes the first element                     | [ ]  |
| void swap(queue& other)| swaps the contents                            | [ ]  |

</details>

# Set

<details>
  <summary>Specification</summary>
<br />

## Set Member type

| Member type            | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| key_type               | Key the first template parameter (Key)        | [ ]  |
| value_type             | Key value type (the value itself is a key)    | [ ]  |
| reference              | value_type & defines the type of the reference to an element | [ ]  |
| const_reference        | const value_type & defines the type of the constant reference | [ ]  |
| iterator               | internal class SetIterator<T>                 | [ ]  |
| const_iterator         | internal class SetConstIterator<T>            | [ ]  |
| size_type              | size_t defines the type of the container size | [ ]  |

## Set Member functions

| Member functions       | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| set()                  | default constructor, creates an empty set     | [ ]  |
| set(std::initializer_list<value_type> const &items) | creates the set initialized using std::initializer_list<T> | [ ] |
| set(const set &s)      | copy constructor                              | [ ]  |
| set(set &&s)           | move constructor                              | [ ]  |
| ~set()                 | destructor                                    | [ ]  |
| operator=(set &&s)     | assignment operator overload for moving an object | [ ] |

## Set Iterators

| Iterators              | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| iterator begin()        | returns an iterator to the beginning          | [ ]  |
| iterator end()          | returns an iterator to the end                | [ ]  |

## Set Capacity

| Capacity               | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| bool empty()           | checks whether the container is empty         | [ ]  |
| size_type size()       | returns the number of elements                | [ ]  |
| size_type max_size()   | returns the maximum possible number of elements | [ ] |

## Set Modifiers

| Modifiers              | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| void clear()           | clears the contents                           | [ ]  |
| std::pair<iterator, bool> insert(const value_type& value) | inserts a node and returns iterator + success | [ ] |
| void erase(iterator pos) | erases an element at pos                     | [ ]  |
| void swap(set& other)  | swaps the contents                            | [ ]  |
| void merge(set& other) | splices nodes from another container          | [ ] |

## Set Lookup

| Lookup                 | Definition                                     | Done |
|-------------------------|-----------------------------------------------|------|
| iterator find(const Key& key) | finds an element with a specific key    | [ ]  |
| bool contains(const Key& key) | checks if the container contains an element with a specific key | [ ] |

</details>
