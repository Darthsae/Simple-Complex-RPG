find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(boost_asio CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)
find_package(boost_thread CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

add_executable(SimpleComplexClient src/main.cpp ${SOURCES} ${HEADER_LIST})

target_include_directories(SimpleComplexClient PUBLIC include)

target_link_libraries(SimpleComplexClient PRIVATE SimpleComplexCommon imgui::imgui Boost::asio Boost::thread DeiVoluntas)
target_link_libraries(SimpleComplexClient PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
target_link_libraries(SimpleComplexClient PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
target_link_directories(SimpleComplexClient PUBLIC src/**)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/SimpleComplexClient/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

include(CTest)
enable_testing()