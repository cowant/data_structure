cmake_minimum_required(VERSION 3.9)
project(ds VERSION 0.0.1 LANGUAGES C CXX)

option(DS_BUILD_TESTS "Build ds's unit tests" ON)

add_library(ds "")

target_sources(ds
  PRIVATE
    "forward_list/forward_list.c"
)
message(STATUS "PROJECT_SOURCE_DIR: " ${PROJECT_SOURCE_DIR})
target_include_directories(ds
  PUBLIC
    ${PROJECT_SOURCE_DIR}/include
)

if(DS_BUILD_TESTS)
  enable_testing()
  add_subdirectory("third_party/googletest")

  function(ds_test test_file)
    get_filename_component(test_target_name "${test_file}" NAME_WE)

    add_executable("${test_target_name}" "")
    target_sources("${test_target_name}"
      PRIVATE
        "${test_file}"
    )
    target_link_libraries("${test_target_name}" ds gmock gtest)
    add_test(NAME "${test_target_name}" COMMAND "${test_target_name}")
  endfunction(ds_test)

  ds_test("forward_list/forward_list_test.cc")
endif(DS_BUILD_TESTS)
