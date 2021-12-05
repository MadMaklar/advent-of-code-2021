target_sources(lib PRIVATE giant_squid.cpp)

if(ENABLE_TESTING)
  target_sources(tests PRIVATE giant_squid.test.cpp)
endif()
