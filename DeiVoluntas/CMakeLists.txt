find_package(boost_asio CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

add_library(DeiVoluntas ${SOURCES} ${HEADER_LIST})

target_include_directories(DeiVoluntas PUBLIC include)

target_link_libraries(DeiVoluntas PRIVATE Boost::asio)
target_link_directories(DeiVoluntas PUBLIC src/**)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/DeiVoluntas/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})
