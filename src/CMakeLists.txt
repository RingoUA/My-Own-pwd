add_executable(mopwd)

target_sources(mopwd
    PRIVATE
        main.cpp
        mopwd.cpp
        arg_parser.cpp
)

target_include_directories(mopwd
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_BINARY_DIR}/generated
)

target_compile_features(mopwd
    PRIVATE
        cxx_std_23
)
