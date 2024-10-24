# Testing

This document outlines the testing procedures and guidelines for the project using CTest. It includes information on how to run tests, how to write new tests, and general best practices.

## Table of Contents
- [Overview](#overview)
- [Running Tests](#running-tests)
- [Writing Tests](#writing-tests)
- [Test Organization](#test-organization)
- [Continuous Integration](#continuous-integration)
- [Best Practices](#best-practices)

## Overview

Testing is a critical part of the development process to ensure that the application functions as intended and to catch bugs early. This project uses CTest as the testing framework, integrated with CMake for easy configuration and execution of tests.

## Running Tests

To run tests using CTest, follow these steps:

1. **Build the Project**: Make sure the project is built. You can do this using the following command:
   ```bash
   mkdir build
   cd build
   cmake ..
   cmake --build .
   ```

2. **Run CTest**: Execute the following command to run all tests:
   ```bash
   ctest
   ```

   - To see detailed output, use:
   ```bash
   ctest --verbose
   ```

3. **Run Specific Tests**: You can run specific tests by specifying the test name:
   ```bash
   ctest -R <test_name>
   ```

4. **Run Tests with Coverage**: If you have code coverage enabled, you can run tests and generate a coverage report:
   ```bash
   ctest --coverage
   ```

## Writing Tests

To add new tests to the project, follow these guidelines:

1. **Create Test Files**: Organize tests in a dedicated directory, such as `tests/`. Each test file should correspond to the source file or module it is testing.

2. **Include the Required Headers**: Ensure to include the necessary headers for CTest and the classes/functions you want to test:
   ```cpp
   #include <gtest/gtest.h>  // or other relevant testing framework headers
   ```

3. **Define Test Cases**: Use `TEST` macros to define test cases. For example:
   ```cpp
   TEST(MyModuleTest, MyFunctionTest) {
       EXPECT_EQ(myFunction(2, 3), 5);
   }
   ```

4. **Group Related Tests**: Use `TEST_F` for tests that require setup or teardown. Group related tests into test fixtures:
   ```cpp
   class MyModuleTest : public ::testing::Test {
   protected:
       void SetUp() override {
           // Code to set up before each test
       }
   };
   
   TEST_F(MyModuleTest, MyFunctionTest) {
       EXPECT_EQ(myFunction(2, 3), 5);
   }
   ```

5. **Check Assertions**: Use assertions like `EXPECT_EQ`, `EXPECT_TRUE`, `EXPECT_FALSE`, etc., to validate the expected behavior of the code.

## Test Organization

- Tests should be organized logically, grouping related tests into appropriate directories and files.
- Follow naming conventions for test files that correspond to the source files being tested (e.g., `my_module_test.cpp` for `my_module.cpp`).

## Continuous Integration (Under Consideration)

Integrate testing with Continuous Integration (CI) tools to automate the testing process on each commit or pull request. Ensure your CI configuration includes commands to build the project and run CTest.

### Example CI Configuration

Here’s a basic example of how to configure CTest in a CI pipeline (e.g., GitHub Actions):

```yaml
name: CI

on: [push, pull_request]

jobs:
  build:
    runs-on: ubuntu-latest
    steps:
      - name: Checkout code
        uses: actions/checkout@v2

      - name: Set up CMake
        uses: scikit-build/cmake-build-release@v0.2.0

      - name: Build
        run: |
          mkdir build
          cd build
          cmake ..
          cmake --build .

      - name: Run Tests
        run: |
          cd build
          ctest --output-on-failure
```

## Best Practices

- **Write Tests Early**: Aim to write tests as you develop features to ensure functionality is validated.
- **Test Edge Cases**: Include tests for edge cases and invalid inputs to ensure robustness.
- **Maintain Tests**: Regularly review and update tests as the codebase evolves.
- **Run Tests Frequently**: Run tests frequently during development to catch issues early.

## Conclusion

Testing is essential for maintaining the quality and reliability of the project. By following the guidelines outlined in this document, you can ensure that the project remains robust and that new features are thoroughly validated.
