# Table of Contents
- [Node Struct](#node)
- [List Class](#list)
- [Iterator Class](#iterator)
---

# Node Template Struct {#node}

## Constructors
| Name             | Description                                                   |
|------------------|---------------------------------------------------------------|
| Node<T\>()        | Creates a node with no next, previous, or value.              |
| Node<T\>(T value) | Creates a node with no next or previous, and the given value. |

## Variables
| Name                | Description                  |
|---------------------|------------------------------|
| T value             | The value the node stores.   |
| Node<T\>* next      | Pointer to the next node.    |
| Node <T\>* previous | Pointer to the previous node |

---

# List Class {#list}

## Constructors
| Name                                      | Description                                                                     |
|-------------------------------------------|---------------------------------------------------------------------------------|
| List<T\>()                                | Creates a List of the given type.                                               |
| List<T\>(std::initializer_list<T\> values) | Creates a List of the given type with the values given in the initializer list. |

## Functions
| Name                                   | Description                                                                             |
|----------------------------------------|-----------------------------------------------------------------------------------------|
| void PushFront(const T& value)         | Pushes a node to the front of the list.                                                 |
| void PushBack(const T& value)          | Pushes a node to the back of the list.                                                  |
| T PopFront()                           | Removes the node from the front and returns its value.                                  |
| T PopBack()                            | Removes the node from the back and returns its value.                                   |
| bool Insert(const T& value, int index) | Inserts a value at the given index and returns whether it succeeded or not.             |
| bool Remove(const T& value)            | Removes a single node that has the given value and returns whether it succeeded or not. |
| int RemoveAll(const T& value)          | Removes every node that has the given value, returning the amount it removed.           |
| T First() const                        | Returns the first thing in the list.                                                    |
| T Last() const                         | Returns the last thing in the list.                                                     |
| Iterator<T\> begin() const             | Returns an [iterator](#iterator) pointing to the first node in the list.                |
| Iterator<T\> end() const               | Returns an [iterator](#iterator) pointing to the last node in the list.                 |
| void Destroy()                         | Destroys everything in the list.                                                        |
| int GetLength() const                  | Returns the length of the list.                                                         |

---

# Iterator Class {#iterator}

## Constructors
| Name                           | Description                                       |
|--------------------------------|---------------------------------------------------|
| Iterator<T\>()                 | Creates a iterator that points to nullptr.        |
| Iterator<T\>(Node<T\>* current) | Creates a iterator that points to the given node. |

## Operators
| Name                                                  | Description                                                           |
|-------------------------------------------------------|-----------------------------------------------------------------------|
| T& operator*() const                                  | Returns what the iterator is pointing to.                             |
| Iterator<T> operator++()                              | Moves the iterator to the next node in the list.                      |
| Iterator<T> operator--()                              | Moves the iterator to the previous node in the list.                  |
| const bool operator==(const Iterator<T>& other) const | Returns whether this iterator and the other point to the same node.   |
| const bool operator!=(const Iterator<T>& other) const | Returns whether this iterator and the other point to different nodes. |