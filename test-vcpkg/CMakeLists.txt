cmake_minimum_required(VERSION 3.10)
project(test-vcpkg)

# Set the path to the vcpkg toolchain file
set(CMAKE_TOOLCHAIN_FILE "C:/vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "Vcpkg toolchain file")

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)

# Find the package
find_package(curl CONFIG REQUIRED)

# Add the executable
add_executable(test-vcpkg main.cpp)

# Link the libraries
target_link_libraries(test-vcpkg PRIVATE CURL::libcurl)