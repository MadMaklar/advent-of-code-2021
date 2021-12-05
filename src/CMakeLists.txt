find_package(Catch2 REQUIRED)
find_package(Boost REQUIRED)

include(CTest)
include(Catch)

add_library(lib)
target_link_libraries(lib PRIVATE project_warnings Boost::boost)
target_include_directories(lib PUBLIC ${CMAKE_CURRENT_LIST_DIR})

add_executable(run main.cpp)
target_link_libraries(run PRIVATE lib project_warnings)

if(ENABLE_TESTING)
  add_executable(tests)
  target_link_libraries(tests PRIVATE lib project_warnings
                                      Catch2::Catch2WithMain)
  catch_discover_tests(tests)
endif()

add_subdirectory(advent_of_code_2021)
