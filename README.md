# Custom Implementation of C++ Standard Containers

This repository contains custom implementations of the following C++ Standard Library containers:

[vector](#vector),
[array](#array), 
[list](#list), 
[stack](#stack),
[queue](#queue)


These containers are implemented to closely mimic the behavior and interfaces of their standard counterparts in C++. This project serves as both a learning exercise in understanding the inner workings of standard containers and a demonstration of C++ programming skills.

## Build and Test Instructions
| Command            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `make all`              | build and run tests and coverage report                                                             |
| `make gcov_report`        | generate code coverage report                                         |
| `make test`              | build tests                                                          |
| `make sanitize`              | check with AddressSanitizer |
| `make valgrind`              | check for memory leaks with Valgrind |
| `make style`              | format code |
| `make clean`              | clean the project |

### Dependencies

Ensure you have the following tools and libraries installed:

* Google Test: [Installation Guide](https://github.com/google/googletest/blob/main/googletest/README.md)
* lcov: Install via package manager (e.g., sudo apt-get install lcov)
* clang-format: For code formatting (sudo apt-get install clang-format)
* Valgrind: For detecting memory leaks (sudo apt-get install valgrind)

### Notes

* Compiler: The Makefile uses g++ by default. Ensure your compiler supports the C++17 standard.
* Operating System: The Makefile script automatically detects your operating system (Linux or macOS) and uses the appropriate commands for opening reports and handling code coverage.

### Support

If you have any questions or encounter issues while building or testing the project, please create an issue in the GitHub repository or contact the project author.

## Containers Info

### Array

<details id="general-info-array">
  <summary>General information</summary>
<br />

Array is a sequence container that encapsulates a static array. You cannot add new elements to an array container, you can only modify the value of the original ones. In terms of interaction, a container array combines the obvious properties of a static array with the main advantage of container classes - a clearer organisation of data. For example, an Array container stores the size of an array and provides iterators. Just like a vector, an array occupies a sequential part of memory and can be passed to a function as a standard array in C. The second template argument of the array class is its actual size.

</details>

<details>
  <summary>Specification</summary>
<br />

*Array Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Array Member functions*

This table contains the main public methods for interacting with the class:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `array()`  | default constructor, creates an empty array                                 |
| `array(std::ptrdiff_t n)`  |       parameterized constructor, creates the vector of size n                           |
| `array(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates array initizialized using std::initializer_list<T>    |
| `array(const array &other)`  | copy constructor  |
| `array(array &&other)`  | move constructor  |
| `~array()`  | destructor  |
| `operator=(array &&right)`      | assignment operator overload for moving an object                                |
| `operator=(const array& right)`      | assignment operator overload for сopying an object                                |

*Array Element access*

This table contains the public methods for accessing the elements of the class:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access a specified element with bounds checking                                          |
| `reference operator[](size_type pos)`             | access a specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Array Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Array Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*Array Modifiers*

This table contains the public methods for modifying a container:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void swap(array& other)`                   | swaps the contents                                |
| `void fill(const_reference value)`         | assigns the given value to all elements in the container. |

</details>

### List

<details>
  <summary>General information</summary>
<br />

List is a sequence container that stores a set of elements with arbitrary size, in the form of nodes connected in sequence by pointers. Each node stores a value corresponding to an element in the list, and a pointer to the next element.
This container design allows you to avoid a rigidly fixed size, such as in a static array, and makes adding a new element to the container more user-friendly.

![](misc/images/list_01.png)

The above is an example of a list of four elements. Each of the list elements is represented as a structure with two fields: a node value and a pointer to the next list element. The last element in the list does not point to anything.

![](misc/images/list_02.png)

This type of list structure allows you to simply (without cascading) add elements to both the end and the middle of the list. Adding an element to a specific position in the list creates a new node pointing to the next element after that position, after which the pointer of the previous element is moved to the new one.

![](misc/images/list_03.png)

Removing an element from the list frees the corresponding node, and the pointers of neighbouring elements change values: the previous element moves the pointer to the next after the deleted element.

Lists can be singly or doubly linked. A singly linked list is a list where each node stores only one pointer: to the next list element (the example above). In a doubly linked list, each node stores an additional pointer to the previous element as well. The standard C++ implementation of the list container uses a doubly linked list.

The container class object stores pointers to the "head" and "tail" of the list, pointing to the first and last elements of the list. The List container provides direct access only to the 'head' and 'tail', but allows you to add and delete elements in any part of the list.
</details>

<details>

<summary>Specification</summary>
<br />

*List Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of an element (T is a template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*List Functions*

This table contains the main public methods for interacting with the class:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `list()`  | default constructor, creates an empty list                                  |
| `list(size_type n)`  | parameterized constructor, creates the list of size n                                 |
| `list(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates a list initizialized using std::initializer_list<T>    |
| `list(const list &l)`  | copy constructor  |
| `list(list &&l)`  | move constructor  |
| `~list()`  | destructor  |
| `operator=(list &&l)`      | assignment operator overload for moving an object                                |
| `operator=(std::initializer_list<T> const &items)`      | assigns elements from the initialization list                                 |

*List Element access*

This table contains the public methods for accessing the elements of the class:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*List Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*List Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |

*List Modifiers*

This table contains the public methods for modifying a container:

| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts element into concrete pos and returns the iterator that points to the new element     |
| `void erase(iterator pos)`          | erases an element at pos                                 |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void pop_back()`   | removes the last element        |
| `void push_front(const_reference value)`      | adds an element to the head                      |
| `void pop_front()`   | removes the first element        |
| `void swap(list& other)`                   | swaps the contents                                                                     |
| `void merge(list& other)`                   | merges two sorted lists                                                                      |
| `void splice(const_iterator pos, list& other)`                   | transfers elements from list other starting from pos             |
| `void reverse()`                   | reverses the order of the elements              |
| `void unique()`                   | removes consecutive duplicate elements               |
| `void sort()`                   | sorts the elements                |

*List Modifiers(other)*

This table contains the public other methods for modifying a container:

| Modifiers       | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator insert_many(iterator pos, Args &&...args)`          | inserts new elements into the container directly before `pos`           |
| `void insert_many_back(Args &&...args)`           | appends new elements to the end of the container                  |
| `void insert_many_front(Args &&...args)`       | appends new elements to the top of the container |
| `void print()`       | print list |


</details>


### Queue

<details>
  <summary>General information</summary>
<br />

Queue is a container with elements organized according to FIFO (First-In, First-Out) principle. Just like a list, an object of the queue container class has pointers to the "tail" and "head" of the queue, but the deletion is performed strictly from the "head", and the addition of new elements is performed strictly in the "tail". It is convenient to think of a queue as a kind of pipe, with elements entering at one end and exiting at another one.

![](misc/images/queue01.png)

</details>

<details>
  <summary>Specification</summary>
<br />

*Queue Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Queue Member functions*

This table contains the main public methods for interacting with the class:


| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `queue()`  | default constructor, creates an empty queue                                 |
| `queue(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates queue initizialized using std::initializer_list<T>    |
| `queue(const queue &q)`  | copy constructor  |
| `queue(queue &&q)`  | move constructor  |
| `~queue()`  | destructor  |
| `operator=(queue &&q)`      | assignment operator overload for moving an object                                |

*Queue Element access*

This table contains the public methods for accessing the elements of the class:

| Element access | Definition                                      |
|----------------|-------------------------------------------------|
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Queue Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Queue Modifiers*

This table contains the public methods for modifying a container:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts an element at the end                       |
| `void pop()`              | removes the first element                        |
| `void swap(queue& other)`             | swaps the contents                               |

</details>

### Stack

<details>
  <summary>General information</summary>
<br />

Stack is a container with elements organized according to LIFO (Last-In, First-Out) principle. A stack container class object contains pointers to the "head" of the stack; removing and adding elements is done strictly from the "head". You can think of the stack as a glass or a pipe with one sealed end: in order to get to the element placed in the container first, you must take out all the elements on top.

![](misc/images/stack01.png)

</details>

<details>
  <summary>Specification</summary>
<br />

*Stack Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type      | Definition                                       |
|------------------|--------------------------------------------------|
| `value_type`       | `T` the template parameter T                   |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`        | `size_t` defines the type of the container size (standard type is size_t) |

*Stack Member functions*

This table contains the main public methods for interacting with the class:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `stack()`  | default constructor, creates an empty stack                                 |
| `stack(std::initializer_list<value_type> const &items)`  | initializer list constructor, creates stack initizialized using std::initializer_list<T>    |
| `stack(const stack &s)`  | copy constructor  |
| `stack(stack &&s)`  | move constructor  |
| `~stack()`  | destructor  |
| `operator=(stack &&s)`      | assignment operator overload for moving an object                                |

*Stack Element access*

This table contains the public methods for accessing the elements of the class:

| Element access   | Definition                                       |
|------------------|--------------------------------------------------|
| `const_reference top()`              | accesses the top element                         |

*Stack Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity       | Definition                                      |
|----------------|-------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |

*Stack Modifiers*

This table contains the public methods for modifying a container:

| Modifiers        | Definition                                       |
|------------------|--------------------------------------------------|
| `void push(const_reference value)`             | inserts an element at the top                       |
| `void pop()`              | removes the top element                        |
| `void swap(stack& other)`             | swaps the contents                               |

</details>

### Vector

<details>
  <summary>General information</summary>
<br />

Vector is a sequence container that encapsulates a dynamic array for more user-friendly usage. This container does not require manual memory control like standard dynamic arrays, but instead allows any number of elements to be added via `push_back()` and `insert()` methods and, unlike a list, allows any container element to be accessed directly by an index. Elements in a vector are stored sequentially, allowing iterating over the vector not only through the provided iterator, but also by manually shifting the pointer to the vector element. So, a pointer to the first element of a vector can be passed as an argument to any function that expects an ordinary array as an argument. The dynamic resizing of the array does not occur every time an element is added or removed, only when the specified buffer size is exceeded. So, the vector stores two values for a size: the size of the stored array (`size()` method) and the size of the buffer (`capacity()` method).

</details>

<details>
  <summary>Specification</summary>
<br />

*Vector Member type*

This table contains in-class type overrides (typical for the standard STL library) that are adopted to make class code easy to understand:

| Member type            | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `value_type`             | `T` defines the type of the element (T is template parameter)                                  |
| `reference`              | `T &` defines the type of the reference to an element                                                             |
| `const_reference`        | `const T &` defines the type of the constant reference                                         |
| `size_type`              | `size_t` defines the type of the container size (standard type is size_t) |

*Vector Member functions*

This table contains the main public methods for interacting with the class:

| Functions      | Definition                                      |
|----------------|-------------------------------------------------|
| `vector()`  | default constructor, creates an empty vector                                 |
| `vector(std::ptrdiff_t n)`  | parameterized constructor, creates the vector of size n                                 |
| `vector(std::initializer_list<value_type> &items)`  | initializer list constructor, creates a vector initizialized using `std::initializer_list<T>`    |
| `vector(const vector &other)`  | copy constructor  |
| `vector(vector &&other)`  | move constructor  |
| `~vector()`  | destructor  |
| `operator=(vector &&right)`      | assignment operator overload for moving an object                                |
| `operator=(vector &right)`      | assignment operator overload for copying an object                                |

*Vector Element access*

This table contains the public methods for accessing the elements of the class:

| Element access         | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `reference at(size_type pos)`                     | access a specified element with bounds checking                                          |
| `reference operator[](size_type pos);`             | access a specified element                                                               |
| `const_reference front()`          | access the first element                        |
| `const_reference back()`           | access the last element                         |

*Vector Iterators*

This table contains the public methods for iterating over class elements (access to iterators):

| Iterators      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator begin()`    | returns an iterator to the beginning            |
| `iterator end()`        | returns an iterator to the end                  |

*Vector Capacity*

This table contains the public methods for accessing the container capacity information:

| Capacity               | Definition                                                                             |
|------------------------|----------------------------------------------------------------------------------------|
| `bool empty()`          | checks whether the container is empty           |
| `size_type size()`           | returns the number of elements                  |
| `size_type max_size()`       | returns the maximum possible number of elements |
| `void reserve(size_type size)`                | allocate storage of size elements and copies current array elements to a newely allocated array                                     |
| `size_type capacity()`               | returns the number of elements that can be held in currently allocated storage         |
| `void shrink_to_fit()`          | reduces memory usage by freeing unused memory                                          |

*Vector Modifiers*

This table contains the public methods for modifying a container:


| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `void clear()`          | clears the contents                             |
| `iterator insert(iterator pos, const_reference value)`         | inserts elements into concrete pos and returns the iterator that points to the new element     |
| `void push_back(const_reference value)`      | adds an element to the end                      |
| `void push_back(reference &value)`      | removes the last element(using move semantics)                      |
| `void pop_back()`   | removes the last element(using copy semantics)          |
| `void swap(vector& other)`                   | swaps the contents                                                                     |

*Vector Modifiers(other)*

This table contains the public other methods for modifying a container:


| Modifiers      | Definition                                      |
|----------------|-------------------------------------------------|
| `iterator insert_many(iterator pos, Args &&...args)`          | inserts new elements into the container directly before `pos`           |
| `void insert_many_back(Args &&...args)`           | appends new elements to the end of the container                  |
| `void insert_many_front(Args &&...args)`       | appends new elements to the top of the container |
| `void print()`      | print vector                      |

</details>
