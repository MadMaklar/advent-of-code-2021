target_sources(lib PRIVATE binary_diagnostic.cpp)

if(ENABLE_TESTING)
  target_sources(tests PRIVATE binary_diagnostic.test.cpp)
endif()
