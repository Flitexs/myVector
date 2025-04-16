cmake_minimum_required (VERSION 3.8)
add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")
project ("CMakeProject4")
add_executable (CMakeProject4 "CMakeProject4.cpp" "CMakeProject4.h" "Vector.h")


if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET CMakeProject4 PROPERTY CXX_STANDARD 20)
endif()