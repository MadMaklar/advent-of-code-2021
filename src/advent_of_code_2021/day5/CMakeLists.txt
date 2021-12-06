target_sources(lib PRIVATE hydrothermal_venture.cpp)

if(ENABLE_TESTING)
  target_sources(tests PRIVATE hydrothermal_venture.test.cpp)
endif()
