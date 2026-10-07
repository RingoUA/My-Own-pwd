cmake_minimum_required(VERSION 4.0)

set(CMAKE_EXPERIMENTAL_CXX_IMPORT_STD
    "f35a9ac6-8463-4d38-8eec-5d6008153e7d"
)
set(CMAKE_CXX_MODULE_STD ON)

project(mopwd
    VERSION 0.1.1
    DESCRIPTION "My Own pwd. A clone of the Unix pwd utility."
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Fix some clangd error
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(CTest)

# -----------------------------------------------------------------------------
# Generated files
# -----------------------------------------------------------------------------
configure_file(
    ${PROJECT_SOURCE_DIR}/include/version.hpp.in
    ${PROJECT_BINARY_DIR}/generated/version.hpp
)

# -----------------------------------------------------------------------------
# Main executable
# -----------------------------------------------------------------------------
add_subdirectory(src)

# -----------------------------------------------------------------------------
# Tests
# -----------------------------------------------------------------------------
if(BUILD_TESTING)
    include(cmake/dependencies.cmake)
    add_subdirectory(tests)
endif()
