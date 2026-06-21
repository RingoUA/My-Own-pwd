cmake_minimum_required(VERSION 4.1.2)

project("My Own pwd"
    VERSION 0.1.0
    DESCRIPTION "A clone of the Unix pwd utility."
    LANGUAGES CXX
)

# Fix some clangd error
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(mopwd src/main.cpp)

target_sources(mopwd
    PRIVATE
        src/main.cpp
        src/mopwd.cpp
)

target_include_directories(mopwd
    PRIVATE
        include
)

target_compile_features(mopwd PRIVATE cxx_std_23)
