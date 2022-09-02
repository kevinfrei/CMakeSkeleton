cmake_minimum_required(VERSION 3.6.1)

project(DynamicLib VERSION 2.3.1)

configure_file(${PROJECT_SOURCE_DIR}/impl-include/dynamic_version_private.h.in dynamic_version_private.h)

if(APPLE)
  # Do something for Mac
endif()

if(WIN32)
  # This makes windows behave a bit more like the very broken behavior
  # of Linux & Darwin: Export everything (no .def files of __declspec's).
  # Why should everything default to exported? I'm not really sure, but
  # I think it's likely to make a bunch of C++ tech just not behave the way
  # you may think it should. Not a big deal, however....
  # Even more broken is that everything in the invoking binary
  # defaults to attempting to import. That's batshit crazy, honestly...
  # It does seem to allow random .so's to override internal function calls.
  # Some day I should demonstrate the situation...
  set(CMAKE_WINDOWS_EXPORT_ALL_SYMBOLS TRUE)
endif()

# Use a list, so you can conditionally add stuff later...
# (Otherwise, you can just include the files directly)
add_library(
  dynamicLib
    SHARED
  "dyn1.cpp"
  "dyn2.cpp"
)
target_include_directories(
  dynamicLib
    PUBLIC
      "${PROJECT_SOURCE_DIR}/include"
    PRIVATE
      "${PROJECT_SOURCE_DIR}/impl-include"
      "${PROJECT_BINARY_DIR}"
)
target_compile_definitions(
  dynamicLib
  PUBLIC
  D_HOWDY
  INTERFACE
  D_HOLA
  PRIVATE
  D_BONJOUR
)

target_link_libraries(dynamicLib theStaticLibrary myConfig)
set_target_properties(
  dynamicLib
    PROPERTIES
      OUTPUT_NAME demoDyn
)

# You only need to install it if it's part of the final bits (SDK or something)
install(TARGETS dynamicLib LIBRARY DESTINATION lib)
