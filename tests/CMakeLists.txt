enable_testing()

add_executable(mopwd_tests)

target_sources(mopwd_tests
    PRIVATE
        FILE_SET CXX_MODULES
        BASE_DIRS
            ${PROJECT_SOURCE_DIR}/modules
        FILES ${PROJECT_SOURCE_DIR}/modules/arg_parser.cppm

    PRIVATE
        test_arg_parser.cpp
        ${PROJECT_SOURCE_DIR}/src/arg_parser.cpp
)

target_include_directories(mopwd_tests
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        ${PROJECT_BINARY_DIR}/generated
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
