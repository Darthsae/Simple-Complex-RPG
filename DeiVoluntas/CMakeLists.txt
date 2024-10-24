find_package(SDL2 CONFIG REQUIRED)
find_package(SDL2_image CONFIG REQUIRED)
find_package(sdl2-gfx CONFIG REQUIRED)
find_package(boost_asio CONFIG REQUIRED)
find_package(box2d CONFIG REQUIRED)
find_package(EnTT CONFIG REQUIRED)

file(GLOB_RECURSE SOURCES "src/**/*.cpp")
file(GLOB_RECURSE HEADER_LIST "include/**/*.h")

add_library(DeiVoluntas ${SOURCES})

target_include_directories(DeiVoluntas PUBLIC include)

target_link_libraries(DeiVoluntas PRIVATE $<TARGET_NAME_IF_EXISTS:SDL2::SDL2main> $<IF:$<TARGET_EXISTS:SDL2::SDL2>,SDL2::SDL2,SDL2::SDL2-static>)
target_link_libraries(DeiVoluntas PRIVATE $<IF:$<TARGET_EXISTS:SDL2_image::SDL2_image>,SDL2_image::SDL2_image,SDL2_image::SDL2_image-static>)
target_link_libraries(DeiVoluntas PRIVATE Boost::asio box2d::box2d SDL2::SDL2_gfx EnTT::EnTT)
target_link_directories(DeiVoluntas PUBLIC src/**)

source_group(
  TREE "${PROJECT_SOURCE_DIR}/DeiVoluntas/include"
  PREFIX "Header Files"
  FILES ${HEADER_LIST})

include(CTest)
enable_testing()

# add the tests
add_subdirectory(tests)
