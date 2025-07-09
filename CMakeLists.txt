cmake_minimum_required (VERSION 3.8)

project (wood LANGUAGES CXX)

add_library(wood STATIC wood.cpp "main.cpp")
target_include_directories(wood PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})


include(FetchContent)

FetchContent_Declare(
	termcolor
	GIT_REPOSITORY https://github.com/ikalnytskyi/termcolor.git
	tag v2.1.0
)

FetchContent_MakeAvailable(termcolor)
FetchContent_GetProperties(termcolor)

target_include_directories(wood PUBLIC ${termcolor_SOURCE_DIR}/include)

if (CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    add_executable(wood_test main.cpp)
    target_link_libraries(wood_test PRIVATE wood)
endif()