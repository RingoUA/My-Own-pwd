cmake_minimum_required(VERSION 3.31.6)

project(mopwd
    VERSION 0.1.1
    DESCRIPTION "My Own pwd. A clone of the Unix pwd utility."
    LANGUAGES CXX
)

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
