cmake_minimum_required(VERSION 3.5.0)
project(SimpleComplexRPG VERSION 0.1.0 LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_RELEASE "/O2 /Zi")
set(CMAKE_EXE_LINKER_FLAGS_RELEASE "/PROFILE")

add_subdirectory(DeiVoluntas)
add_subdirectory(SimpleComplexCommon)
add_subdirectory(SimpleComplexServer)
add_subdirectory(SimpleComplexClient)