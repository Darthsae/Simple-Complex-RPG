find_package(boost_asio CONFIG REQUIRED)
find_package(boost_thread CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

add_library(SimpleComplexCommon ${SOURCES})

target_include_directories(SimpleComplexCommon PUBLIC include)

target_link_libraries(SimpleComplexCommon PRIVATE DeiVoluntas Boost::asio Boost::thread)
target_link_directories(SimpleComplexCommon PUBLIC src/**)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/SimpleComplexCommon/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

include(CTest)
enable_testing()

# add the tests
add_subdirectory(tests)
