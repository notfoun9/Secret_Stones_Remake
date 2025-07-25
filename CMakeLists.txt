cmake_minimum_required(VERSION 3.10)

project(SDL LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_PREFIX_PATH "/opt/homebrew;${CMAKE_PREFIX_PATH}")

configure_file(assets/aerial.ttf ${CMAKE_CURRENT_BINARY_DIR}/assets/aerial.ttf COPYONLY)

find_package(SDL3 REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(spdlog REQUIRED)

add_executable(main main.cpp)

# Link libraries
target_link_libraries(main PRIVATE
    game
    spdlog::spdlog
    SDL3::SDL3
    SDL3_ttf::SDL3_ttf
    SDL3_image::SDL3_image
)

add_subdirectory(include)
