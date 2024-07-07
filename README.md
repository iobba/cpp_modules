# C++ projects

## Introduction

```C++ is a general-purpose programming language created by Bjarne Stroustrup as an extension of the C programming language, or "C with Classes".```


The goal of these modules is to introduce me to Object-Oriented Programming.
This is the starting point of my C++ journey. Many languages are recommended
to learn OOP. I decided to choose C++ since it’s derived from my old friend C.
Because this is a complex language, and in order to keep things simple, my code will
comply with the C++98 standard.

```Keep discovering new concepts step-by-step. The exercises will progressively increase in complexity.```

## Key Concepts
  - **cpp_00** : Namespaces, classes, member functions, stdio streams, initialization lists, static, const, and some other basic stuf.
    - `what is the difference between a static variable and a normal variable in a class `
      ```
      _nbAccounts
      _totalAmount
      _totalNbDeposits
      _totalNbWithdrawals
      ```
      These variables are static, which means they are associated with the class itself rather than individual instances of the class. Here are the implications:
      
      - `Static variables`: When a member variable is declared as static, it is shared among all instances of the class. There is only one instance of the variable that is shared across all objects of the class. Any modification to the static variable will be reflected in all instances.
      
      - `Non-static variables`: On the other hand, the non-static variables (_accountIndex, _amount, _nbDeposits, _nbWithdrawals) are regular instance variables. Each object of the class will have its own separate copy of these variables. Modifying these variables in one object will not affect the values of the same variables in other objects.
      
      In summary, _nbAccounts, _totalAmount, _totalNbDeposits, and _totalNbWithdrawals are shared variables accessible to all instances of the class, while _accountIndex, _amount, _nbDeposits, and _nbWithdrawals are individual variables specific to each object of the class.

    - `what is the purpose of a default constructor in private`
      When a default constructor is placed in the private section of a class, it means that instances of that class cannot be created using the default constructor from outside the class. This is often done to enforce a specific initialization process or to control the creation of objects.
  - **cpp_01** : Memory allocation, pointers to members, references, switch statement.
    - `A reference and a pointer are both used to refer to other objects, but they have some key differences`:
      - Syntax: A reference is declared using an ampersand (&) symbol, while a pointer is declared using an asterisk (*) symbol.
      
      - Nullability: A reference must always be initialized and cannot be null. It must refer to a valid object. On the other hand, a pointer can be assigned a null value (nullptr) or can point to a valid object.
      
      - Reassignment: Once a reference is initialized, it cannot be reassigned to refer to a different object. It remains bound to the initial object. In contrast, a pointer can be reassigned to point to a different object.
      
      - Indirection: When accessing the value through a reference, you do not need to use the dereference operator (). It provides a transparent way to access the object. In contrast, when using a pointer, you need to dereference it using the asterisk () operator to access the value it points to.
      
      - Memory: References do not require memory allocation or deallocation. They are essentially an alias for an existing object. Pointers, however, require memory allocation and deallocation using new and delete or new[] and delete[] for dynamic memory management.
      
      - Function parameters: References are often used in function parameters to pass objects by reference, allowing the function to modify the original object. Pointers can also be used for this purpose, but they require explicit dereferencing.
      
      In summary, references provide a convenient way to work with objects without worrying about nullability and explicit dereferencing, while pointers offer more flexibility and control over memory allocation and object reassignment.

  - **cpp_02** : Ad-hoc polymorphism, operator overloading and Orthodox Canonical class form.
    - `why the copy constructor takes a reference of an object`
      Because if it's not by reference, it's by value. To do that you make a copy, and to do that you call the copy constructor. But to do that, we need to make a new value, so we call the copy constructor, and so on...
      You would have infinite recursion because "to make a copy, you need to make a copy".
      By taking a reference to an object as a parameter, the copy constructor avoids this recursion. It allows the copy constructor to be invoked with an existing object as an argument without triggering an infinite loop of copy constructor calls.
      Additionally, taking a reference to an object is more efficient than passing the object by value. When an object is passed by value, a copy of the object is made, which can be costly in terms of memory and performance, especially for large objects. By passing a reference, the copy constructor can directly access and work with the original object without incurring the overhead of making a copy.
      In summary, by taking a reference to an object in the copy constructor, we avoid recursion and improve efficiency by directly accessing the original object without unnecessary copying.

    - `what if we just type class2 = class1 without that copy assignment operator`
      - If you don't provide a custom copy assignment operator, the compiler will generate a default copy assignment operator for you. The default copy assignment operator performs a member-wise assignment, copying each member variable from the source object to the target object.
      - By providing a custom copy assignment operator, you have control over how the copying is performed. You can implement a deep copy, where new resources are allocated and values are copied over, ensuring that each object manages its own independent set of resources. This allows for proper resource cleanup and avoids unintended side effects between objects.
  
    - `the  operator overload '+' automatically called when '+' is used with  between two objects`
  
    - `Parametric polymorphism and ad-hoc polymorphism are two different forms of polymorphism in programming`
  
      - `Parametric Polymorphism`:
        Parametric polymorphism, also known as generic programming, allows code to be written in a way that can operate on values of different types without specifying the exact type at compile time. It is achieved through the use of type parameters. This enables the creation of reusable code that can work with multiple types.
          ```
          template <typename T>
          T add(T a, T b) {
              return a + b;
          }
          ```
  
      - `Ad-hoc Polymorphism`:
        Ad-hoc polymorphism, also known as function overloading or operator overloading, allows a function or operator to exhibit different behaviors depending on the types of its arguments. It allows the same function or operator name to be used with different implementations for different argument types.
          ```
          // Function overloaded for different types
          void printValue(int value)
          {
              std::cout << "Integer value: " << value << std::endl;
          }
          
          void printValue(double value)
          {
              std::cout << "Double value: " << value << std::endl;
          }
          
          void printValue(const std::string& value)
          {
              std::cout << "String value: " << value << std::endl;
          }
          ```
          
      - `how does the pre-increment and .... operator functions get called`
          ```
          When the compiler sees ++a, and a is not a built-in type, then the compiler looks for either a::operator++() or operator++(a&) and if found then calls it.
          
          When the compiler sees a++, and a is not a built-in type, then the compiler looks for either a::operator++(int) or operator++(a&, int) and if found then calls it.
          
          + The (int) parameter is a dummy parameter used to differentiate between prefix and postfix versions of the operators. the value passed in that parameter is always zero.
          
          --> The compiler determines whether to interpret ++a as pre-increment or a++ as post-increment based on the context in which the expression is used.
          
          If the ++ operator is used before the variable (++a), it is interpreted as a pre-increment operation. In this case, the compiler will look for an overloaded operator++() member function or a non-member function that takes the object by reference or as a non-const argument. If such a function is found, it will be called to perform the increment operation.
          
          If the ++ operator is used after the variable (a++), it is interpreted as a post-increment operation. In this case, the compiler will look for an overloaded operator++(int) member function or a non-member function that takes an additional int argument. The int argument is not used, but its presence distinguishes the post-increment operator from the pre-increment operator. If such a function is found, it will be called to perform the increment operation.
          ```
  - **cpp_03** : Inheritance, Subclasses.
    - `Diamond inheritance problem`    

      - When class A inherits from both class B and class C, and both B and C inherit from class D, it can result in a problem known as the "diamond problem" or "diamond inheritance problem". The diamond problem occurs when there are two paths for class A to inherit class D, causing ambiguity

      - To fix this issue, you can use virtual inheritance. Virtual inheritance ensures that only one instance of the shared base class is present in the derived class hierarchy.
        By adding the virtual keyword before the inheritance of class D in both class B and class C, you ensure that class A only inherits a single instance of class D. This resolves the ambiguity in the diamond problem.

  - **cpp_04** : Subtype polymorphism, abstract classes, interfaces.

    * `Dynamic binding`
    
      - also known as late binding or runtime binding, is a mechanism in object-oriented programming that determines the specific implementation of a polymorphic function (a function declared in a base class and overridden in a derived class) at runtime based on the actual type of the object being referred to.
      - When a function is declared as virtual in the base class, and the derived class overrides that function, dynamic binding allows the correct implementation of the function to be resolved at runtime, depending on the actual type of the object.

    * `Interfaces`
    
      - Pure abstract classes, also known as pure virtual classes or interfaces, are classes that contain only pure virtual functions. A pure virtual function is a virtual function that is declared in a base class but has no implementation. It is specified by appending "= 0" to the end of the function declaration.
      - A pure abstract class serves as an interface or contract that defines a set of functions that derived classes must implement. It provides a way to establish a common interface for a group of related classes without providing any default implementation. 
  - **cpp_05** : Repetition and Exceptions and Error handling.
  - **cpp_06** : Casts : static_cast, dynamic_cast, reinterpret_cast.
      - `The static_cast` ------->> operator in C++ is a casting operator used for implicit and explicit type conversions between related types. It performs compile-time type checking and allows conversions that are known at compile-time, ensuring type safety. 
      - `The dynamic_cast` ------>> operator in C++ is used for performing runtime type checks and conversions between pointers or references of polymorphic types within an inheritance hierarchy. It allows you to safely downcast and cross-cast pointers or references, ensuring type safety.
      - `The reinterpret_cast` ->> operator in C++ is a low-level casting operator that allows you to convert between unrelated types, such as between pointers and integer types, without any implicit conversions or type checking. It reinterprets the bit pattern of the source expression as if it were the destination type.
 
  - **cpp_07** : Templates.
  - **cpp_08** : Templated containers, iterators, algorithms
    - [  pointer VS iterator ]

        Pointers and iterators are both used to navigate and access elements in a sequence, but they have some differences in terms of functionality and usage. Here are some key differences between pointers and iterators:

        1- Type of Sequence: Pointers are primarily used for navigating and accessing elements in arrays, whereas iterators are designed to work with various container types, such as arrays, vectors, lists, sets, and more. Iterators provide a consistent interface across different containers.
        
        2- Interface and Operations: Pointers have a limited set of operations compared to iterators. Pointers can be dereferenced using the * operator to access the value they point to, and they can be incremented or decremented to move through memory locations. Iterators, on the other hand, provide a richer set of operations depending on the category of iterator (e.g., forward, bidirectional, random access). Iterators can be dereferenced, incremented, decremented, and they often support additional operations specific to the container they belong to (e.g., insertion, erasure).
        
        3- Range and Validity: Pointers have a concept of a range defined by the memory addresses they point to. They can point to valid elements within the allocated memory or be set to nullptr to indicate a null or invalid state. Iterators, however, have more flexibility in terms of the range they can represent. They can point to elements within a container, including the beginning and end of the container, representing a range of elements. Iterators also have the concept of validity, where an iterator can be valid or invalid depending on the state of the container it belongs to (e.g., if the container has been modified and the iterator is no longer valid).
        
        4- Syntax and Usage: Pointers are used in C and C++ to directly manipulate memory and arrays. They are often used in low-level programming and scenarios where direct memory access is required. Iterators, on the other hand, are used in more high-level programming and provide a more abstract and container-agnostic way of working with sequences. They are often used with standard library containers and algorithms to iterate, access, and manipulate container elements.
        
        Overall, iterators provide a more generic and container-agnostic approach to working with sequences, while pointers are more closely tied to memory addresses and array access. However, it's worth noting that iterators can be implemented using pointers internally, especially in the case of random access iterators.

  - **cpp_09** :
    - `Bitcoin Exchange`: I used map container --> so i can get the ability to store data in the format of key/value.
    - `Reverse Polish Notation`: I used stack container --> LIFO.
      - Stack-based evaluation: RPN lends itself well to stack-based evaluation algorithms. The operands are pushed onto a stack, and when an operator is encountered, the necessary operands are popped from the stack, the operation is performed, and the result is pushed back onto the stack. This stack-based approach simplifies the evaluation process and allows for efficient implementation.
    - `PmergeMe`: making a comparison between list and vector performances.
      - In general, `std::vector` is faster than std::list for most operations, particularly for accessing elements by index, iterating through the container, and performing bulk modifications. This is because std::vector provides contiguous memory storage, allowing for efficient element access and better cache locality.
      - On the other hand, `std::list` is optimized for fast insertions and deletions at any position within the container. Unlike std::vector, which requires moving elements when inserting or removing in the middle, std::list maintains pointers between elements, allowing for constant-time insertion and deletion. However, this advantage comes at the cost of slower element access and higher memory overhead.
