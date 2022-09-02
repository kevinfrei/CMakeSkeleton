cmake_minimum_required(VERSION 3.12)

project(StaticLib VERSION 1.3.1)

configure_file(${PROJECT_SOURCE_DIR}/impl-include/static_version_private.h.in static_version_private.h)

if(APPLE)
  # Do something for Mac
endif()

if(WIN32)
  # Do something for Windows
endif()

# Use a list, so you can conditionally add stuff later...
# (Otherwise, you can just include the files directly)
add_library(
  theStaticLibrary
  STATIC
  "stat1.cpp"
  "stat2.cpp"
)
target_include_directories(
  theStaticLibrary
  AFTER
  PRIVATE
  "${PROJECT_SOURCE_DIR}/impl-include"
  "${PROJECT_BINARY_DIR}"
  PUBLIC
  "${PROJECT_SOURCE_DIR}/include"
)
target_compile_definitions(
  theStaticLibrary
  PUBLIC
  S_HOWDY
  INTERFACE
  S_HOLA
  PRIVATE
  S_BONJOUR
)
target_link_libraries(theStaticLibrary PRIVATE myConfig)
set_target_properties(
  theStaticLibrary
  PROPERTIES
  OUTPUT_NAME demoStat
)

# You only need to install it if it's part of the final bits (SDK or something)
# install(TARGETS staticLib ARCHIVE DESTINATION lib)
