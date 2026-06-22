cmake_minimum_required(VERSION 4.1.2)

project(mopwd
    VERSION 0.1.1
    DESCRIPTION "My Own pwd. A clone of the Unix pwd utility."
    LANGUAGES CXX
)

# Fix some clangd error
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# Generate version const
configure_file(
    ${CMAKE_CURRENT_SOURCE_DIR}/include/version.hpp.in
    ${CMAKE_CURRENT_BINARY_DIR}/generated/version.hpp
)

add_executable(mopwd)

target_sources(mopwd
    PRIVATE
        src/main.cpp
        src/mopwd.cpp
        src/arg_parcer.cpp
)

target_include_directories(mopwd
    PRIVATE
        include
        ${CMAKE_CURRENT_BINARY_DIR}/generated
)

target_compile_features(mopwd
    PRIVATE
        cxx_std_23
)
