cmake_minimum_required(VERSION 3.16)

project(pacman LANGUAGES CXX)

include(FetchContent)

set(SFML_BUILD_AUDIO OFF CACHE BOOL "" FORCE)
set(SFML_BUILD_NETWORK OFF CACHE BOOL "" FORCE)

FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 3.0.2
    GIT_SHALLOW TRUE
)

FetchContent_MakeAvailable(SFML)

add_executable(pacman 
    src/main.cpp
    src/map.cpp
    src/player.cpp
    src/sfml_render.cpp
    src/game.cpp
)

target_include_directories(pacman PRIVATE include)
target_link_libraries(pacman PRIVATE SFML::Graphics)

target_compile_features(pacman PRIVATE cxx_std_17)
