add_library(Array Array.cpp)
add_library(Vector Vector.cpp)


target_include_directories(Array PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
target_include_directories(Vector PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})