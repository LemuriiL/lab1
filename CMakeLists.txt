cmake_minimum_required(VERSION 3.14)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# TODO: rename project and delete this comment
project(template VERSION 0.1.0)
string(
        APPEND _opts
        "$<IF:$<CXX_COMPILER_ID:MSVC>,"
        "/W4;$<$<CONFIG:RELEASE>:/O2>,"
        "-Wall;-Wextra;-Werror;"
        "$<$<CONFIG:RELEASE>:-O3>"
        "$<$<CXX_COMPILER_ID:Clang>:-stdlib=libc++>"
        ">"
)
add_library(${PROJECT_NAME} STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/example/example.cpp
        sources/Lab1.1.cpp sources/Lab1.2.cpp sources/Lab1.3.cpp sources/Lab1.4.cpp sources/Lab1.5.cpp sources/Lab1.6.cpp sources/Lab1.7.cpp sources/Lab1.8.cpp sources/Lab1.9.cpp sources/Lab1.10.cpp sources/Lab1.18.cpp sources/Lab1.11.cpp sources/Lab1.12.cpp sources/Lab1.13.cpp sources/Lab1.14.cpp sources/Labs15-17.cpp)

add_executable(${PROJECT_NAME}_ex
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/Labs15-17.cpp
)

target_include_directories(${PROJECT_NAME} PUBLIC
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/sources/example>"
  "$<INSTALL_INTERFACE:/sources/example>"
)

target_link_libraries(${PROJECT_NAME}_ex ${PROJECT_NAME})

include(FetchContent)
FetchContent_Declare(
        googletest
        GIT_REPOSITORY https://github.com/google/googletest.git
        GIT_TAG        release-1.10.0
)
FetchContent_MakeAvailable(googletest)
include(GoogleTest)

add_executable(tests
  # TODO: enum your files and delete this comment
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/test_main.cpp
  ${CMAKE_CURRENT_SOURCE_DIR}/tests/example.cpp
)
target_link_libraries(tests ${PROJECT_NAME} pthread gtest_main)
enable_testing()
add_test(NAME unit_tests COMMAND tests)
