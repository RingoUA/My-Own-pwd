cmake_minimum_required(VERSION 4.1.2)

project("My Own pwd")

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
