cmake_minimum_required(VERSION 3.12)

# Name the project, because...
project(DemoProject VERSION 1.0.0)

configure_file(${PROJECT_SOURCE_DIR}/include/demo_version_private.h.in demo_version_private.h)

include(test-script.cmake)
test_macro(THISISTHEVALUE ANOTHER_VALUE)

# Include any global configuration library
add_subdirectory(configuration)

# Now, set the configuration you selected as the one that subsequent  libs depend on
add_library(myConfig ALIAS configNoRTTI)

# The order of subdirectories only matters for dependencies
add_subdirectory(staticLib)

# Which is probably not great, because dynamicLib depends on staticLib
add_subdirectory(dynamicLib)

# Create the executable target
add_executable(
  demoProject
  "demo1.cpp"
  "demo2.cpp"
)
target_compile_features(
  demoProject
  PRIVATE
  cxx_std_17
)
target_include_directories(
  demoProject
  PRIVATE
  "${PROJECT_SOURCE_DIR}/include"
  "${PROJECT_BINARY_DIR}" # This is for the demo.h.in -> demo.h translation
)
target_link_libraries(
  demoProject
  theStaticLibrary
  dynamicLib
)
target_compile_definitions(
  demoProject
  PRIVATE
  HOWDY
)
set_target_properties(
  demoProject
  PROPERTIES
  OUTPUT_NAME demoBinary
)

# You only need to install it if it's part of the final bits (SDK or something)
install(TARGETS demoProject RUNTIME DESTINATION bin)
