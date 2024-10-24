# Build Guide

This project uses **CMake** and **vcpkg** for dependency management and can be built in different environments, including Visual Studio, VSCode, and terminal on Windows, macOS, and Linux. 

## Prerequisites
1. **CMake** - Ensure that CMake is installed on your system.
   - [CMake Installation Guide](https://cmake.org/install/)
   
2. **vcpkg** - Used for managing dependencies.
   - [vcpkg Installation Guide](https://github.com/microsoft/vcpkg)

   To install `vcpkg`, run the following:
   ```bash
   git clone https://github.com/microsoft/vcpkg.git
   cd vcpkg
   ./bootstrap-vcpkg.sh # On Linux/macOS
   .\bootstrap-vcpkg.bat # On Windows
   ```

3. **Install dependencies**:
   Use `vcpkg` to install dependencies defined in the `vcpkg.json`:
   ```bash
   ./vcpkg install
   ```

   The project dependencies are:
   ```json
   {
     "dependencies": [
       "boost-asio",
       "boost-thread",
       {
         "name": "imgui",
         "default-features": false,
         "features": [
           "docking-experimental",
           "freetype",
           "sdl2-binding",
           "sdl2-renderer-binding"
         ]
       },
       "sdl2",
       "sdl2-image",
       "sdl2-gfx",
       "box2d"
     ]
   }
   ```

---

## Building with VSCode (Windows, macOS, Linux)
1. **Install the C++ Extensions**:
   - Install the [C++](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cpptools) and [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extensions for VSCode.

2. **Configure the Project**:
   - Open the project folder in VSCode.
   - Ensure that `vcpkg` is integrated with CMake:
     ```bash
     ./vcpkg integrate install
     ```

3. **Configure the build**:
   - Use the following `CMakePresets.txt` configuration to define the build presets:

     ```json
     {
         "version": 8,
         "configurePresets": [
             {
                 "name": "vcpkg",
                 "generator": "Visual Studio 17 2022",
                 "toolset": "host=x64",
                 "architecture": "x64",
                 "binaryDir": "${sourceDir}/build",
                 "cacheVariables": {
                     "CMAKE_TOOLCHAIN_FILE": "$env{VCPKG_ROOT}/scripts/buildsystems/vcpkg.cmake"
                 }
             }
         ],
         "buildPresets": [
             {
                 "name": "VX",
                 "configurePreset": "vcpkg"
             }
         ]
     }
     ```

4. **Build**:
   - In VSCode, open the **Command Palette** (`Ctrl+Shift+P`) and select `CMake: Configure`.
   - Select the `vcpkg` preset to configure the build.
   - Run `CMake: Build` to build the project.

---

## Building with Visual Studio (Windows)
1. **Install Visual Studio**:
   - Install the **Desktop Development with C++** workload.

2. **Configure vcpkg with Visual Studio**:
   - Ensure `vcpkg` is integrated with CMake:
     ```bash
     .\vcpkg integrate install
     ```

3. **Open the Project in Visual Studio**:
   - Open Visual Studio, and then select `File > Open > CMake` and navigate to your project’s root directory.

4. **Build the Project**:
   - Visual Studio should automatically detect the CMakePresets configuration and use the `vcpkg` toolchain.
   - Build the project by selecting `Build > Build All`.

---

## Building from Terminal (Windows, macOS, Linux)

### Windows Terminal (MSVC)

1. **Open a Terminal (Developer Command Prompt)**:
   Ensure that MSVC is set up in your environment by opening the Developer Command Prompt for Visual Studio.

2. **Configure and Build**:
   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=%VCPKG_ROOT%\scripts\buildsystems\vcpkg.cmake -B build
   cmake --build build
   ```

### macOS/Linux Terminal (GCC/Clang)

1. **Install Dependencies**:
   Use `vcpkg` to install all necessary dependencies:
   ```bash
   ./vcpkg install
   ```

2. **Configure the Build**:
   Run the following CMake command:
   ```bash
   cmake -DCMAKE_TOOLCHAIN_FILE=$VCPKG_ROOT/scripts/buildsystems/vcpkg.cmake -B build
   ```

3. **Build the Project**:
   Use the following to build:
   ```bash
   cmake --build build
   ```

---

## Notes
- **CMakePresets.txt** is used to simplify build configurations across different platforms.
- If you want to adjust the CMake generator or toolchain, modify the `CMakePresets.txt` or use `cmake` command-line options.
- Ensure `vcpkg` is properly integrated with CMake and your IDE by using `vcpkg integrate install` to configure the toolchain automatically.
