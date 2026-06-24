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
        src/arg_parser.cpp
        src/free_deleter.cpp
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

include(FetchContent)

FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG v3.15.1
)

FetchContent_MakeAvailable(Catch2)

include(CTest)
enable_testing()

add_executable(mopwd_tests)

target_sources(mopwd_tests
    PRIVATE
        tests/test_arg_parser.cpp
        src/arg_parser.cpp
)

target_include_directories(mopwd_tests
    PRIVATE
        include
        ${CMAKE_CURRENT_BINARY_DIR}/generated
)

target_link_libraries(mopwd_tests
    PRIVATE
        Catch2::Catch2WithMain
)

target_compile_features(mopwd_tests
    PRIVATE
        cxx_std_23
)

include(Catch)
catch_discover_tests(mopwd_tests)
