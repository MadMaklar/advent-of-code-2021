target_sources(lib PRIVATE sonar_sweep.cpp)

if(ENABLE_TESTING)
  target_sources(tests PRIVATE sonar_sweep.test.cpp)
endif()
