cmake_minimum_required (VERSION 3.6.1)

project (dynamicLib)

if (APPLE)
  # Do something for Mac
endif ()

if (WIN32)
  # Do something for Windows
endif()

# Use a list, so you can conditionally add stuff later...
# (Otherwise, you can just include the files directly)
set (DYNAMICLIB_SOURCES
  "dyn1.cpp"
  "dyn2.cpp"
)
set (DYNAMICLIB_INCLUDES
  "${PROJECT_SOURCE_DIR}/include"
  "${staticLib_SOURCE_DIR}/include"
)
set (DYNAMICLIB_DEFINES "VERSION=\"1.1.1\"")

include_directories(${DYNAMICLIB_INCLUDES})
add_library(dynamicLib SHARED ${DYNAMICLIB_SOURCES})
target_link_libraries(dynamicLib staticLib)
set_target_properties(dynamicLib PROPERTIES
  COMPILE_DEFINITIONS "${DYNAMICLIB_DEFINES}"
  OUTPUT_NAME demoDyn
)
# You only need to install it if it's part of the final bits (SDK or something)
install(TARGETS dynamicLib LIBRARY DESTINATION lib)
