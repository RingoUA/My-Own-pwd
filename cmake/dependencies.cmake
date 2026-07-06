include(FetchContent)

if(BUILD_TESTING)
  FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG v3.15.1
  )

  FetchContent_MakeAvailable(Catch2)
endif()
