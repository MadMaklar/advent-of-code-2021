target_sources(lib PRIVATE dive.cpp)

if(ENABLE_TESTING)
  target_sources(tests PRIVATE dive.test.cpp)
endif()
