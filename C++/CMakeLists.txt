cmake_minimum_required(VERSION 3.0)
project(JSON-comparison)
add_library(comparison SHARED comparison.cpp)
add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} PRIVATE comparison ssl crypto)
install(TARGETS comparison DESTINATION lib)
install(FILES comparison.hpp DESTINATION include)