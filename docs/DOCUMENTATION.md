# C++ Documentation Standards

This document outlines the documentation standards for C++ code in this project, using Doxygen.

## General Guidelines
- **Use `@brief`** for short, one-line summaries.
- **Use `@param`** to describe function parameters.
- **Use `@return`** to describe return values.
- **Use `@tparam`** to describe template parameters.
- **Be consistent** with documentation across files, classes, methods, and variables.

---

## File Header Documentation
Each file should include a header comment describing the file's purpose.

```cpp
/**
 * @file <filename>
 * @brief Brief description of the file.
 *
 * Detailed description of the file, including purpose and usage details if necessary.
 */
```

---

## Namespace Documentation
Namespaces should have a description to clarify their purpose.

```cpp
/**
 * @namespace <namespace_name>
 * @brief Brief description of the namespace.
 */
namespace my_namespace {
    // Namespace content
}
```

---

## Class/Struct Documentation
Classes and structs should be documented with a summary of their purpose, along with detailed descriptions for constructors, methods, and member variables.

```cpp
/**
 * @class <ClassName>
 * @brief Brief description of the class.
 *
 * Detailed description of the class, including purpose and design notes.
 */
class MyClass {
public:
    /**
     * @brief Constructor description.
     * @param param1 Description of the first parameter.
     * @param param2 Description of the second parameter.
     */
    MyClass(int param1, double param2);

    /**
     * @brief Brief description of the method.
     *
     * Detailed explanation if necessary.
     * @param value Description of the parameter.
     * @return What the function returns.
     */
    int myMethod(int value) const;

private:
    int memberVariable; ///< Brief description of the member variable.
};

/**
 * @struct <StructName>
 * @brief Brief description of the struct.
 Detailed description of the class, including purpose and design notes.
 */
struct MyStruct {
    int x; ///< X coordinate.
    int y; ///< Y coordinate.
};
```

---

## Typedefs and Using Declarations
Provide clear descriptions of type aliases and `typedef` declarations.

```cpp
/**
 * @typedef <TypeName>
 * @brief Brief description of the type alias or typedef.
 */
typedef int MyType;

/**
 * @brief Alias for std::vector<int>.
 */
using IntVector = std::vector<int>;
```

---

## Variable Documentation
Global variables and public members should be documented as needed.

```cpp
/**
 * @var <variable_name>
 * @brief Description of the variable.
 */
int globalVar;
```

---

## Function / Method Documentation
Every function or method must include a description of its parameters, return values, and the purpose of the function.

```cpp
/**
 * @brief Brief description of the function.
 *
 * Detailed description if necessary.
 * @param param1 Explanation of the first parameter.
 * @param param2 Explanation of the second parameter.
 * @return Explanation of the return value.
 */
int myFunction(int param1, double param2);
```

---

## Enum Documentation
Each enumerator in an enum should be explained.

```cpp
/**
 * @enum <EnumName>
 * @brief Brief description of the enum.
 */
enum MyEnum {
    Value1, ///< Description of Value1.
    Value2, ///< Description of Value2.
};
```

---

## Template (Generics) Documentation
Template parameters (`@tparam`) should be described in detail.

```cpp
/**
 * @tparam T Description of the template parameter T.
 */
template<typename T>
class MyTemplateClass {
    // Template class content
};
```

---

## Additional Notes
- **Consistency**: Ensure consistency in how you document classes, structs, methods, variables, and other elements.
- **Clarity**: Keep descriptions clear and concise. Use longer, detailed descriptions only when necessary to explain complex functionality.

This standard helps to keep the codebase maintainable, improving readability and collaboration across the project.

---

### Example
```cpp
/**
 * @file my_class.h
 * @brief Header file for the MyClass class.
 */

/**
 * @class MyClass
 * @brief Handles operations for managing data.
 */
class MyClass {
public:
    /**
     * @brief Constructs a new MyClass object.
     * @param param1 The ID to initialize.
     * @param param2 The initial value to store.
     */
    MyClass(int param1, double param2);

    /**
     * @brief Retrieves the stored value.
     * @return The current value.
     */
    double getValue() const;

private:
    int id; ///< ID of the object.
    double value; ///< Stored value.
};
```
