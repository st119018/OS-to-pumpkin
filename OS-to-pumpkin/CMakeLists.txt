cmake_minimum_required(VERSION 3.5) # specifies the minimum version of CMake the project needs
									
project(OStoPumpkin VERSION 1.0)

if(PROJECT_SOURCE_DIR STREQUAL PROJECT_BINARY_DIR)
  message(FATAL_ERROR "In-source builds not allowed. Please read README.\n")
endif()

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
#set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(${CMAKE_PROJECT_NAME} main.cpp) 
