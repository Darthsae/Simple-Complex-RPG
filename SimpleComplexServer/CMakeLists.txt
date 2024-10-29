find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(boost_asio CONFIG REQUIRED)
find_package(boost_thread CONFIG REQUIRED)
find_package(platform_folders CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

add_executable(SimpleComplexServer src/main.cpp ${SOURCES} ${HEADER_LIST})

target_include_directories(SimpleComplexServer PUBLIC include)

target_link_libraries(SimpleComplexServer PRIVATE DeiVoluntas SimpleComplexCommon)
target_link_libraries(SimpleComplexServer PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
target_link_libraries(SimpleComplexServer PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
target_link_libraries(SimpleComplexServer PRIVATE imgui::imgui Boost::asio Boost::thread sago::platform_folders)
target_link_directories(SimpleComplexServer PUBLIC src/**)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/SimpleComplexServer/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})


include(CTest)
enable_testing()

# add the tests
add_subdirectory(tests)
