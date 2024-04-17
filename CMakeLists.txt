cmake_minimum_required(VERSION 3.5)

project(OpSystemsCodeExamples)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(BUILD_OPTIONAL_EXAMPLES "Build optional examples" OFF)

if(UNIX AND APPLE)
  message("--> We only provide limited Apple support at this time. Please use a Linux system if at all possible..")
  message("--> Some GNU-specific examples will be disabled.")
endif()

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)

FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG        v1.14.0
)

# cmake Windows issue: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

FetchContent_MakeAvailable(googletest)


# add_subdirectory(std-queue)
add_subdirectory(NathCode/rforth)



if(BUILD_OPTIONAL_EXAMPLES)

    if(UNIX AND NOT APPLE)
      add_subdirectory(monitor)
      add_subdirectory(mutex)
      add_subdirectory(semaphore)
      add_subdirectory(spin_lock)
      add_subdirectory(std-hsearch)
      add_subdirectory(std-tsearch)
      add_subdirectory(stm)
    else()
    endif()
endif()