# Code Quality Standards and Best Practices

This document outlines the standards and best practices to follow when writing code for the project. Consistency and clarity are key to making the codebase readable and easy to maintain for all contributors.

## 1. **General Coding Practices**

### 1.1 Readability
- **Comments**: Write clear, meaningful comments. Use comments to explain the "why" behind your code, not the "what." The code itself should be descriptive enough for "what." If the code is not self explanatory explanation of the "what" is permitted.
- **Function Length**: Aim to keep functions short and focused. A function should do one thing and do it well. If a function exceeds ~40 lines, consider refactoring it.
- **Indentation**: Use **spaces over tabs** for consistent indentation (e.g., 4 spaces). Ensure this is enforced in your editor settings.
- **Line Length**: Keep line lengths under 100 characters where possible to ensure readability across different screens.

### 1.2 DRY Principle (Don’t Repeat Yourself)
- Avoid duplicating code across the project. Refactor common logic into reusable functions or classes to make the code more maintainable.
  
### 1.3 YAGNI Principle (You Aren’t Gonna Need It)
- Write only the code you need now. Avoid over-engineering and implementing features "just in case."
- Exceptions to this are when the features are for interfacing with future planned changes.

### 1.4 Consistency
- Stick to the project’s **naming conventions** and file structure (see [Naming Conventions](./Naming)).
- Follow the same structure for functions, classes, and modules as others in the codebase, even if you prefer a different style. Consistency helps everyone understand the code faster.

## 2. **Error Handling and Exceptions**

### 2.1 Use Error Codes and Exceptions Appropriately
- Use **exceptions** for exceptional cases that are truly errors or unexpected states.
- For predictable failures (e.g., file not found), handle errors gracefully using return codes or error states in the API.
  
### 2.2 Guard Clauses
- Use **guard clauses** to return early from a function when invalid input or states are encountered, improving code readability:
  
  ```cpp
  if (!isValidInput(input)) {
      return false;  // Early return
  }
  // Continue with main logic
  ```

## 3. **Memory Management**

### 3.1 RAII (Resource Acquisition Is Initialization)
- Follow the **RAII** principle to manage resources such as memory, file handles, and locks. Use smart pointers (e.g., `std::unique_ptr`, `std::shared_ptr`) to ensure automatic resource cleanup.

### 3.2 Avoid Raw Pointers
- Prefer **smart pointers** over raw pointers for dynamic memory allocation. Raw pointers should only be used for non-owning references or in performance-critical code.

### 3.3 Handle Ownership and Lifetimes
- Clearly define object ownership. Who is responsible for creating and destroying objects? Use appropriate data structures to indicate ownership (e.g., smart pointers, containers).

## 4. **Code Style and Formatting**

### 4.1 Naming Conventions
- Follow the project’s **Naming Conventions** (see the `CONTRIBUTING.md` file for details):
  - Functions: `PascalCase`
  - Variables: `camelCase`
  - Constants: `MACRO_CASE`
  - Etc.

### 4.2 Braces
- Always use **curly braces** for `if`, `for`, `while` blocks, even if it’s a single statement. This helps avoid bugs and improves readability:
  
  ```cpp
  if (condition) {
      doSomething();
  }
  ```

### 4.3 Spaces and Alignment
- Use spaces around operators and after commas:
  
  ```cpp
  int result = a + b;  // Good
  ```

### 4.4 Function Definitions
- For function definitions, keep the return type on the same line as the function name for consistency:
  
  ```cpp
  void RenderEntity(Entity& entity);
  ```

## 5. **Testing and Validation**

### 5.1 Unit Tests
- Write **unit tests** for all critical logic, especially functions that handle complex algorithms or state changes. Tests should cover edge cases and ensure code correctness.

### 5.2 Test Automation
- Integrate tests into the build process to ensure they are run automatically with CI/CD (Continuous Integration/Continuous Delivery). This helps catch errors early.

### 5.3 Use Assertions
- Use `assert` to enforce assumptions about your code and prevent undefined behavior. For example:
  
  ```cpp
  assert(pointer != nullptr && "Pointer must not be null.");
  ```

## 6. **Performance Considerations**

### 6.1 Efficient Algorithms and Data Structures
- Choose the most efficient algorithms and data structures for the task at hand. Profile and test performance-sensitive code regularly.
  
### 6.2 Avoid Premature Optimization
- Don't optimize until you know where the bottlenecks are. Focus on writing clean, maintainable code first. Optimize later when necessary, based on performance measurements.

## 7. **Concurrency and Multithreading**

### 7.1 Use Safe Concurrency
- Use **mutexes**, **locks**, or **atomic operations** to manage shared data safely in multithreaded code.
- Use thread-safe containers or manage locking manually when sharing data between threads.

### 7.2 Thread Pools
- For tasks that require many threads (e.g., networking, physics), use a **thread pool** to manage threads efficiently rather than creating/destroying threads dynamically.

## 8. **Design Patterns**

### 8.1 Favor Composition Over Inheritance
- Whenever possible, prefer **composition** over inheritance to achieve greater flexibility and avoid deep class hierarchies.

### 8.2 Use Design Patterns Where Appropriate
- Use well-established design patterns (e.g., **Factory**, **Observer**, **Singleton**) where applicable to solve common design problems.

## 9. **Code Review Guidelines**

### 9.1 PR Expectations
- Each pull request (PR) should contain a well-defined, small set of changes. Large PRs are hard to review and introduce more risk. If a pr is a refactor larger sizes are permitted.
- Ensure your PR includes:
  - A detailed description of the changes.
  - Clear commit messages explaining what each commit does.
  - Tests, if applicable.
- If you can not do this then another contributor will, however this may cause longer times to merge and review.

### 9.2 Review Etiquette
- Be respectful when reviewing code. Offer constructive feedback and aim to help the contributor improve their code, not criticize them personally. Jokes are allowed if the contributor used all lowercase names.
- As a reviewer, focus on:
  - Correctness (logic and functionality).
  - Code readability and maintainability.
  - Performance implications.
  - Adherence to the project's coding standards and best practices.

---

## Conclusion

Following these coding standards ensures that the project remains consistent, readable, and easy to maintain. Adherence to these guidelines is required for all contributions to the project.
