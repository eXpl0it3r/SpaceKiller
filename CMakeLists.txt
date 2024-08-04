cmake_minimum_required(VERSION 3.16)
project(SpaceKiller LANGUAGES CXX)

option(BUILD_SHARED_LIBS "Build shared libraries" OFF)

if(WIN32)
    set(SFML_USE_STATIC_STD_LIBS ON)
endif()

include(FetchContent)
FetchContent_Declare(SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.6.x)
FetchContent_MakeAvailable(SFML)

add_executable(SpaceKiller main.cpp Icon.hpp TenStamps.hpp)
target_compile_features(SpaceKiller PRIVATE cxx_std_17)
target_link_libraries(SpaceKiller PRIVATE sfml-graphics)

if(WIN32)
    set_target_properties(SpaceKiller PROPERTIES WIN32_EXECUTABLE TRUE)
    target_link_libraries(SpaceKiller PRIVATE sfml-main)
endif()

if(WIN32 AND MSVC)
    set_property(TARGET SpaceKiller PROPERTY MSVC_RUNTIME_LIBRARY "MultiThreaded$<$<CONFIG:Debug>:Debug>")
elseif(CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(SpaceKiller PRIVATE -static)
endif()