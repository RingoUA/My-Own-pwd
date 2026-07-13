add_executable(mopwd)

target_sources(mopwd
    PRIVATE
        FILE_SET CXX_MODULES
        BASE_DIRS
            ${PROJECT_SOURCE_DIR}/modules
        FILES
            ${PROJECT_SOURCE_DIR}/modules/help.cppm
            ${PROJECT_SOURCE_DIR}/modules/arg_parser.cppm
            ${PROJECT_SOURCE_DIR}/modules/mopwd.cppm

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
